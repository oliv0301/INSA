#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void print_stat(char *ref, struct stat *statut)
{
	struct passwd *pw;
	struct group *gr;
	char type; 
	#define LTEMPS 32
	char pws[9], grs[9], temps[LTEMPS];
	
	type ='?';
	if(S_ISREG(statut->st_mode))  type='-';
	else if(S_ISDIR(statut->st_mode))  type='d';
	else if(S_ISCHR(statut->st_mode))  type='c';
	else if(S_ISBLK(statut->st_mode))  type='b';
	else if(S_ISFIFO(statut->st_mode))  type='p';
	strftime(temps, LTEMPS,"%a %e %h %Y %H:%M:%S", localtime(&(statut->st_mtime)));
	
	pw = getpwuid(statut->st_uid);
	if(pw!=NULL) strcpy(pws, pw->pw_name);
	else sprintf(pws, "%8d", (int)statut->st_uid);
	
	gr = getgrgid(statut->st_gid);
	if(gr!=NULL) strcpy(grs, gr->gr_name);
	else sprintf(grs,"%8d", (int)statut->st_gid);
	printf("%c%c%c%c%c%c%c%c%c%c %2d %8s %8s %9d %s %s\n", type, 
		statut->st_mode&S_IRUSR?'r':'-', 	
		statut->st_mode&S_IWUSR?'w':'-',
		statut->st_mode&S_IXUSR?'x':'-',
		statut->st_mode&S_IRGRP?'r':'-',
		statut->st_mode&S_IWGRP?'w':'-',
		statut->st_mode&S_IXGRP?'x':'-',
		statut->st_mode&S_IROTH?'r':'-',
		statut->st_mode&S_IWOTH?'w':'-',
		statut->st_mode&S_IXOTH?'x':'-',
		(int)statut->st_nlink, pws, grs, (int)statut->st_size, temps, ref);
}

int main (int argc, char *argv[])
{
	struct stat statut;
	int i;
	
	if(argc<2) 
	{
		if(fstat(STDIN_FILENO, &statut) == -1)
			{
				fprintf(stderr, "%s : impossible d'obtenir le status de %s\n\n", argv[0], "<STDIN>");
				exit(EXIT_FAILURE);
			}
		print_stat("<STDIN>", &statut);
	}
	else 
	{
		for(i=1; i<argc; i++)
		{
			if(stat(argv[i], &statut) == -1) 
			{
				fprintf(stderr, "%s : impossible d'ouvir le status de %s\n", argv[0], argv[i]);
				continue;
			}
			print_stat(argv[i], &statut); 
		}
	}
	exit(EXIT_SUCCESS);
}


	
