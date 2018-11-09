#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern char **environ;
int main(int argc, char *argv[])
{
	//char **env=environ;
	//char *value=getenv(argv[1]);
	
	//exo7
	/*if(value==NULL) printf("valeur non trouver");
	else printf("valeur de %s = %s\n", argv[1], value);
	*/
	
	//exo6
	/*while(*env!=)
	{
		printf("%s\n", *env++);
	}*/

	//exo7.1
	char envp[256];
	strcpy(envp, argv[1]);
	strcat(envp, "=");
	strcat(envp, argv[2]); //concatenation
	printf("%s\n", envp);
	if(putenv(envp)==0)
	{
		if(getenv(argv[1])!=NULL) printf("success\n");
		else printf("error\n");
	}
	else printf("error2\n");
	exit(EXIT_SUCCESS);
}


