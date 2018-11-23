#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	
	//exo8
	syscall(sys_write, "hello\n");	
	exit(EXIT_SUCCESS);
}
