exo: liste.o main.o vehicule.o
	gcc  liste.o main.o vehicule.o -o exo

liste.o: liste.c vehicule.h
	gcc -c liste.c

vehicule.o: vehicule.c liste.h
	gcc -c vehicule.c

main.o: main.c liste.h vehicule.h
	gcc -c main.c
