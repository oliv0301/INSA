#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	struct sockaddr_in= myLocalExtremity;
	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(9999);
	myaddr.sin_addr.s_addr = 127.0.0.1;
	int numberOfConnectionDescriptor;
	numberOfConnectionDescriptor = socket(PF_INET,SOCK_STREAM, 0);
	printf("numero de la prise : %i\n", numberOfConnectionDescriptor);
	exit(EXIT_SUCCESS);
}
