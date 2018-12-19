#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#define BUFSIZE 1024
int main(int argc, char *argv[])
{
	FILE *fd=fopen(argv[2], "r");
	int nb_lprint = atoi(argv[1]); //nombres de lignes à afficher
	int i,nLignes = 0;
	char c, buffer[BUFSIZE];
	
	if (fd==NULL) printf("erreur");
	fseek(fd, -1, SEEK_END);
 
	while(nLignes <= nb_lprint)
	{
		c=fgetc(fd);
		if(c=='\n') nLignes++;
		if(fseek(fd, -2, SEEK_CUR)==-1)
		{
			fseek(fd, 0, SEEK_SET);
			break;
		}		 
	}
	//fseek(fd, 2, SEEK_CUR);
	while((c=fgetc(fd))!=EOF)
	{
		printf("%c", c);
	}						
}
