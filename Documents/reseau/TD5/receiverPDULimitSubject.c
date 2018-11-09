/* (C) 2018 Christian Toinard INSA CVL, christian.toinard@insa-cvl.fr, All right reserved,  to preserve the limits of the message through TCP */

#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>  
#include <fcntl.h>
#include "PDULimit.h"

//errors handling
void error(const char *msg) 
{
    perror(msg);
    exit(0);
}

//display of structure sockaddr_in 
void print_sockaddr_in(struct sockaddr_in* sockaddr)
{
    printf("struct sockaddr_in {\n");
    printf("sin_family      = %d\n",sockaddr->sin_family);
    printf("sin_addr.s_addr = %s\n",inet_ntoa(sockaddr->sin_addr));
    printf("sin_port        = %d\n",ntohs(sockaddr->sin_port));
    printf("} sockaddr;\n\n");
}

int main(int argc, char const *argv[])
{
    /*** Create a network descriptor ***/
    int demand = socket(AF_INET,SOCK_STREAM,0);
    if(demand<0)
        error("ERROR opening socket");


    /*** Define a container for the local extremity **/
    struct sockaddr_in localExtremity;
    int localExtremity_length = sizeof(struct sockaddr_in);
    
    localExtremity.sin_family = AF_INET;
    localExtremity.sin_addr.s_addr = INADDR_ANY;/*Question 5*/    
    localExtremity.sin_port = 0;/*Question 5*/

    /*** Complete the local extremity ***/
    if( bind(demand,(struct sockaddr *) &localExtremity,sizeof(localExtremity) ) < 0 )
        error("ERROR bind");

    print_sockaddr_in(&localExtremity);


    /* Question 6: Explain why we are using such a system call */
    if( getsockname(demand,(struct sockaddr *) &localExtremity,(socklen_t *)&localExtremity_length ) < 0 )
        error("ERROR getsockname");

    printf("opened socket as nDesc (%d) on port (%d) for stream i/o\n",demand,ntohs(localExtremity.sin_port) );
    print_sockaddr_in(&localExtremity);


    /*** Establish the connections ***/
    listen(demand, 1 ); 

    /*** Retrieve a descriptor number for an established connection **/
    int talk = accept(demand,(struct sockaddr *) &localExtremity,(socklen_t *)&localExtremity_length );
    if( talk < 0 )
        error("ERROR accept");

    print_sockaddr_in(&localExtremity);
    printf("Connected \n");




    int read_ret;
    messagePDU message;
    while(1)
    {
        /*** recv messagePDU ***/
        //receiving header
        if( (read_ret=recv(talk,&message.head.lg, sizeof(message.head.lg),MSG_DONTTWAIT/* Question 7 : To be completed to receive the complete header */)) > 0 )
        {    
            printf("%s: read message.head.type as follows:(%c)\n", argv[0],message.head.type ); 
            printf("%s: read message.head.lg as follows:(%s)\n", argv[0],message.head.lg );

            //Compute the length that must be passed to recv the data
            int lg = ToBeCompleted(message.head.lg);

            //receiving data
            if( (read_ret = recv(talk, &message.data.data, lg, /* Question 8: To be completed to receive the complete data */)) > 0 )
            {
                printf( "%s: read message.data.data as follows:(%s)\n\n", argv[0],message.data.data ); 
            }
        }
        

        /*** exit ***/
        if(read_ret == 0) 
        {
            printf("%s: connection closed by distant peer:\n", argv[0] );
            exit(0);
        }


        /*** error ***/
        if( read_ret < 0 )
            error("ERROR reading talk");
    }


    return 0;
}



