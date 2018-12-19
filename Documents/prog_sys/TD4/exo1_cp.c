#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFSIZE 10

int main(int argc, char* argv[])
{
	int fdsrc, fddst; 
	char buffer[BUFSIZE];
	int nchar;
	fdsrc = open(argv[1], O_RDONLY);
	fddst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC | S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	while ((nchar = read(fdsrc, buffer, BUFSIZE)))
	{
		write(fddst, buffer, nchar);
	}
	close(fdsrc);
	close(fddst);
}
