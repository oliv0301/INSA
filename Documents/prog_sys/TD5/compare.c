#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	FILE *file1=fopen(argv[1], "r");
	FILE *file2=fopen(argv[2], "r");
	char a, b;
	
	while((a=fgetc(file1)) == (b=fgetc(file2)))
	{
		if(a == EOF)
		{
			printf("OK\n");
			return 0;
		}
	}
	printf("NOK\n");
	return 0;
}
	
