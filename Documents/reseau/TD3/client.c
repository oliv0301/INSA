#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <arpa/inet.h>

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int nDescSocket, port;
    struct sockaddr_in serverExtremity;

    char buffer[256];

    nDescSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (nDescSocket < 0) 
        error("ERROR opening socket");

    serverExtremity.sin_family = AF_INET;
    inet_aton(argv[2],(struct in_addr *)&serverExtremity.sin_addr);
    port = atoi(argv[1]);
    serverExtremity.sin_port = htons(port);

    if (connect(nDescSocket,(struct sockaddr *) &serverExtremity,sizeof(serverExtremity)) < 0) 
        error("ERROR connecting");

    while(1)
    {
      printf("Please enter the message: ");
      bzero(buffer,256);
      fgets(buffer,255,stdin);
      int n = write(nDescSocket,buffer,strlen(buffer));
      if (n < 0) 
         error("ERROR writing to socket");
      bzero(buffer,256);
      n = read(nDescSocket,buffer,255);
      if (n < 0) 
         error("ERROR reading from socket");
      if (strstr(buffer,"/exit")==buffer)
         {
                printf("\nEnd of client\n");
                exit(0);
         }
      printf("received %s\n",buffer);
    };
}
