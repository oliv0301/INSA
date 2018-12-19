#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(int argc, char *argv[])
{
	struct stat stsrc, stdst;
	int fdsrc, fddst;
	char *psrc; 
	int size;

	lstat(argv[1], &stsrc);
	lstat(argv[2], &stdst);

	if (stsrc.st_ino == stdst.st_ino && stsrc.st_dev == stdst.st_dev)
	{
		fprintf(stderr, "%s et %s sont le même fichier\n", argv[1], argv[2]);
		return;
	}
	
	fdsrc = open(argv[1], O_RDONLY);
	fddst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR |S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	size = stsrc.st_size;
	psrc = mmap(NULL, size,PROT_READ, MAP_PRIVATE, fdsrc, 0);	
	write(fddst, psrc, size);
	munmap(psrc, size);
	close(fdsrc);
	close(fddst);
}
