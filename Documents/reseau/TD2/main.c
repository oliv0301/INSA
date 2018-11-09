#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <resolv.h>
#include <arpa/inet.h>
#include <errno.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define MY_PORT		9999
#define MAXBUF		1024

int main(void)
{
	int numberOfConnectionDescriptor;
	int numberOfConnectedDescriptor;
	int *sizeConnectedExtremity;
	struct sockaddr_in myLocalExtremity;
	struct sockaddr_in ConnectedExtremity;
	char buffer[MAXBUF];
	char extremity[MAXBUF];
	socklen_t cnt = 
    printf("OK\n");
    close(0);
  if ( (numberOfConnectionDescriptor = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
	{
			perror("Socket");
			exit(errno);
	}
    printf("Numéro de la prise = %d\n",numberOfConnectionDescriptor);

	bzero(&myLocalExtremity, sizeof(myLocalExtremity));
	myLocalExtremity.sin_family = AF_INET;
	myLocalExtremity.sin_port = htons(MY_PORT);
	inet_aton("127.0.0.1",&myLocalExtremity.sin_addr);

    if ( bind(numberOfConnectionDescriptor, (struct sockaddr*)&myLocalExtremity, sizeof(myLocalExtremity)) != 0 )
	{
		perror("socket--bind");
		exit(errno);
	}

	if ( listen(numberOfConnectionDescriptor, 20) != 0 )
	{
		perror("socket--listen");
		exit(errno);
	}
  if ( (numberOfConnectedDescriptor= accept(numberOfConnectionDescriptor,(struct sockaddr*)&ConnectedExtremity, sizeConnectedExtremity)) < 0 )
        {
                        perror("socket--accept");
                        exit(errno);
        }
			
	printf("nbConnected = %i\n", numberOfConnectedDescriptor);
}

