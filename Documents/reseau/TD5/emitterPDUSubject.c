/* (C) 2018 Christian Toinard INSA CVL, christian.toinard@insa-cvl.fr, All right reserved,  to preserve the limits of the message through TCP */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include "PDULimit.h"

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main( argc, argv )
int argc; char *argv[];
{
    int nDescSocket, port;
    struct sockaddr_in serverExtremity;
    messagePDU message;

    nDescSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (nDescSocket < 0) error("ERROR opening socket");

    int on = 1;
    setsockopt(nDescSocket, IPPROTO_TCP, TCP_NODELAY, &on, sizeof(on)); /* Explain why we are using TCP_NODELAY for that emitter */

    serverExtremity.sin_family = AF_INET;
    inet_aton(argv[2],(struct in_addr *)&serverExtremity.sin_addr);
    port = atoi(argv[1]);
    serverExtremity.sin_port = htons(port);

    if (connect(nDescSocket,(struct sockaddr *) &serverExtremity,sizeof(serverExtremity)) < 0) 
        error("ERROR connecting");

    while(1)
    {
      printf("Please enter the message: ");
      bzero(message.data.data,BUFSIZ);
      fgets(message.data.data,BUFSIZ,stdin);

      int n = write(nDescSocket,&PDU_TYPE_DATA,sizeof(PDU_TYPE_DATA)); /* Send first the Data type of the PDU */
      if (n < 0) error("ERROR writing to socket\n");

      int lg=strlen((const char *)message.data.data)-1; /* Must compute the length of the data */
      sprintf(message.head.lg, "%d", lg); /* Must convert the lenght to the header field */
      n = write(nDescSocket,&lg,sizeof(lg)); /* Send the lenght of the data */
      if (n < 0) error("ERROR writing to socket\n");

      n = write(nDescSocket,&message, sizeof(message)); /* Send the data */
      if (n < 0) error("ERROR writing to socket\n");

      if (strstr(message.data.data,"/exit")==message.data.data)
         {
                printf("\nEnd of client\n");
                exit(0);
         }
    }
}
