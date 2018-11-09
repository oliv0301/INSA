#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <resolv.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


#define MY_PORT 9998
#define MAXBUF	1024
#define NUMBER_OF_CLIENTS 2048


int main(int argc, const char *argv[])
{
	int numOfDemandDescriptor;
	if((numOfDemandDescriptor = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket()");
		exit(errno);
	}

	struct sockaddr_in self;
	bzero(&self, sizeof(self));
	self.sin_family      = AF_INET;
	self.sin_port        = htons(MY_PORT);
	self.sin_addr.s_addr = INADDR_ANY;

	if(bind(numOfDemandDescriptor, (struct sockaddr*)&self, sizeof(self)) != 0)
	{
		perror("bind()");
		exit(errno);
	}

	if(listen(numOfDemandDescriptor, 20) != 0)
	{
		perror("listen()");
		exit(errno);
	}

	printf("Father pid [%d]\n", getpid());

	char buffer[MAXBUF];
	pid_t clients[NUMBER_OF_CLIENTS];
	int nbclients = 0;

	while(1)
	{
		struct sockaddr_in client;
		socklen_t addrlen = sizeof(client);

		int numOfConnectedDescriptor = accept(numOfDemandDescriptor, (struct sockaddr*)&client, &addrlen);

		printf("%s:%d connected\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

                switch(clients[nbclients] = fork())
		{
			case -1:
				perror("fork()");
				exit(EXIT_FAILURE);

			case 0:
				close(numOfDemandDescriptor);
				printf("Child pid [%d]\n", getpid());

				while(1)
				{
					int sizereceived = write(numOfConnectedDescriptor, buffer, read(numOfConnectedDescriptor, buffer, MAXBUF));
					printf("Received from child [%d] : \n", getpid());
                                        int j = dup(1);
					write(j, buffer,sizereceived); /* Why write on descriptor number j ? (Is it because it is the best one ?)*/

					if(sizereceived == 0)
					{
						close(numOfConnectedDescriptor);
						printf("The end of [%d]: \n", getpid());
						exit(1);
					}

					if(strstr(buffer,"/exit")==buffer) // Take care that it is not fully satisfying, but sufficient for this directed work (TD)
					{
						printf("Je meurs [%d]\n",getpid());
						close(numOfConnectedDescriptor);
						exit(0);
					}
				}

			default:
				nbclients++;
				close(numOfConnectedDescriptor);
				break;
		}
	}


}

