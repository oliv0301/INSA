#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

typedef struct File
{
    int taille;
    element *tab;
    int tete;
    int queue;
    int estPleine;
}File;



int estPleineFile (File f);
int estVideFile (File f);
File initFile (int taille);

#endif // FILE_H_INCLUDED
