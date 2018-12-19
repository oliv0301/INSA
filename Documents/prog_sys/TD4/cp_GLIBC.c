
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define BUFSIZE 4096
int main(int argc, char argv[])
{
	struct stat stsrc, stdst;
	FILE *fsrc, *fdst;	
	char buffer[BUFSIZE];
	int c;

	lstat(&argv[1], &stsrc);
	lstat(&argv[2], &stdst);
	if (stsrc.st_ino == stdst.st_ino && stsrc.st_dev == stdst.st_dev) 
	{
		fprintf(stderr, "%s et %s sont le meme fichier\n", argv[1], argv[2]);
		return;
	}
	fsrc = fopen(&argv[1], "r");
	fdst = fopen(&argv[2], "w");

	while((c = fread(buffer,1, BUFSIZE, fsrc)))
		fwrite(buffer, 1, BUFSIZE, fdst);

	fclose(fsrc);
	fclose(fdst);
}
	
