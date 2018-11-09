#include <time.h>
#include <stdio.h>
#include"listes.h"
#include <string.h>

int afficheNvaleurs (liste l,int n)
{
    if (n>tailleListe(l))
        printf("Il n'y a pas assez de scores pour afficher un top %i \n", n);
    else
    {
        liste maListe;
        int i;
        init(&maListe);
        for(i=0;i<n;i++)
        {
            ajoutePos(&maListe,getValeur(l, i+1),i+1, getNom(l, i+1));
        }
        affiche(maListe);

        detruire(&maListe);
    }
    return 0;
}

void insertScore(liste* l, int score, char nom[])
{
    int i;
    int tmp=0;
    for(i=0; i<tailleListe(*l); i++)
    {
        if (score>getValeur(*l, i+1))
            tmp= score;
        else
            tmp= getValeur(*l, i+1);
    }
    if (score==tmp)
        ajoutePos(l,score, i, nom);
    else
        ajoutePos(l,score, i+1, nom);


}

void bestScoreJoueur(liste l, char nom[])
{
    int i, best_score=0;
    for(i=0; i<tailleListe(l); i++)
    {
        if(strcmp(nom, getNom(l, i+1))==0)
        {

            if(best_score<getValeur(l, i+1)) best_score=getValeur(l, i+1);
        }
    }
    if(best_score!=0) printf("le meilleur score du joueur : %s est : %i\n", nom, best_score);
    else printf("pas de meilleur score pour ce joueur\n");
}

void allScoreJoueur(liste l, char nom[])
{
    int i, score=0;
    printf("score du joueur %s\n", nom);
    for(i=0; i<tailleListe(l); i++)
    {
        if(strcmp(nom, getNom(l, i+1))==0)
        {

         score = getValeur(l, i+1);
         printf("%i|", score);
        }
    }
    printf("\n");
    if(score==0) printf("pas de score pour ce joueur\n");
}

void creatListCumul(liste l)
{
    liste liste2, l_finale;
    int i, j=0, debug;
    init(&liste2);
    init(&l_finale);
    debug=tailleListe(liste2);
    for(i=0; i<tailleListe(l); i++)
    {
        while ((j<=debug) && strcmp(getNom(l, i+1), getNom(liste2, j+1))!=0)
        {
            j++;
        }
    if(j<=tailleListe(liste2))
    {
        setValeur(liste2, getValeur(liste2, j+1)+getValeur(l, i+1), j+1);
        j=0;
        debug=tailleListe(liste2);
    }
    else
    {
        ajouteEnTete(&liste2,getValeur(l, i+1), getNom(l, i+1));
        j=0;
        debug=tailleListe(liste2);
    }

    }
    for(i=0; i<tailleListe(liste2); i++)
    {
        insertScore(&l_finale, getValeur(liste2, i+1), getNom(liste2, i+1));
    }
    affiche(l_finale);

}



int main()
{
   time_t time1; //pour la temporisation de simulation de jeu
   time_t time2;

   liste liste_score;
   init(&liste_score);
   int var=-1;
   char nom[255];
   int score;
   srand(time(NULL));//lié à la fonction aléatoire

/* Affichage du premier menu à l'utilisateur*/
	printf("------------------\nFaites votre choix\n------------------\n");
	printf("0 - Jouer!\n");
	printf("1 - Afficher tous les scores\n");
	printf("2 - Afficher le top 3\n");
	printf("3 - Afficher le top 10\n");
	printf("4 - Effacer les scores\n");
	printf("5 - Affichage du meilleur score d'un joueur\n");
	printf("6 - Affichage de tous les scores d'un joueur\n");
	printf("7 - Cumuler les scores\n");
	printf("8 - Fermer\n");
	scanf("%d",&var);

	/* Lancement de la boucle d'affichage du menu*/
	while(var!=8)
	{

		switch(var)
		{

		case 0 :
			/* Obtention du nom du joueur et de son score */
			puts("Entrez votre nom :");
			fflush(stdin);
			scanf("%s", nom);
			fflush(stdin);
           /* while(difftime(time2,time1)<3)  //valeur de temporisation en secondes, réduisez là pour tester votre programme plus vite
            {
                time(&time2);
            }*/
            score= rand()%500;
            printf("\n\nBravo %s vous avez obtenu le score de %i\n\n",nom,score);
            /****************   QUESTION I.2  *******************/
            insertScore(&liste_score,score, nom);


			break;

		case 1 :

			/****************   QUESTION I.1  *******************/
            affiche(liste_score);
			break;


		case 2 :
			/****************   QUESTION I.1  *******************/
			afficheNvaleurs(liste_score, 3);


			break;

		case 3 :
			/****************   QUESTION I.1  *******************/
			afficheNvaleurs(liste_score, 10);

			break;

		case 4 :
		    /****************   QUESTION I.3  *******************/
			detruire(&liste_score);


			break;

        case 5 :
		    /****************   QUESTION II.3  *******************/
			printf("saisir le nom du joueur :");
			scanf("%s", nom);
			bestScoreJoueur(liste_score, nom);


			break;

        case 6 :
		    /****************   QUESTION II.4  *******************/
            printf("saisir le nom du joueur :");
			scanf("%s", nom);
			allScoreJoueur(liste_score, nom);



			break;
        case 7 :
		    /****************   QUESTION II.5  *******************/
			creatListCumul(liste_score);


			break;

		default :
			/* Choix non-gérés par le programme */
			printf("\nCe choix est impossible!\n");
			fflush(stdin); // Vide le tampon pour éviter un bug quand on entre un caractère et non un chiffre
			break;

		}

    printf("------------------\nFaites votre choix\n------------------\n");
	printf("0 - Jouer!\n");
	printf("1 - Afficher tous les scores\n");
	printf("2 - Afficher le top 3\n");
	printf("3 - Afficher le top 10\n");
	printf("4 - Effacer les scores\n");
	printf("5 - Affichage du meilleur score d'un joueur\n");
	printf("6 - Affichage de tous les scores d'un joueur\n");
	printf("7 - Cumuler les scores\n");
	printf("8 - Fermer\n");
	scanf("%d",&var);

	}
	return 0;
}
