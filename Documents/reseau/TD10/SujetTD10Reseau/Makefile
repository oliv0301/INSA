DICT=dict
RDICT=r$(DICT)
CC=cc
CFLAGS=-g

.c.o:
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $<


all: $(DICT) $(DICT)1.o $(DICT)2.o $(RDICT) $(RDICT)demon

rpc: $(RDICT).h

install: all
	@echo rien � installer

clean:
	rm *.o $(RDICT) $(RDICT)demon 

proper:
	rm *_clnt.c *_svc.c *_xdr.c $(RDICT).h \
		*.o $(DICT) $(RDICT) $(RDICT)demon


#########################################
# Fonctions communes � la version centralis�e et r�partie
#########################################

# Code client = fichier inclu dans le programme du client (dict1.c ou rdict.c)

CodeClient.hc:
	@echo Le fichier inclu dans le programme client est modifi�

# Code serveur = fichier inclu dans le programme du serveur 
# (dict2.c ou rdict_srp.c)

DictProcedures.hc:
	@echo Le fichier inclu, pour les proc�dures du serveur, est modifi�


#########################################
# Programme initial, version centralis�e 
#########################################

$(DICT): $(DICT)1.o $(DICT)2.o CodeClient.hc
	$(CC) -o $(DICT) $(DICT)1.o $(DICT)2.o 
$(DICT)1.o: $(DICT)1.c dict.h CodeClient.hc
$(DICT)2.o: $(DICT)2.c dict.h DictProcedures.hc


#######################
# Programme r�parti
#######################

# D�pendances pour les fichiers g�n�r�s par rpcgen
$(RDICT)_clnt.c: $(RDICT).h $(RDICT).x
$(RDICT)_svc.c: $(RDICT).h $(RDICT).x
$(RDICT)_xdr.c: $(RDICT).h $(RDICT).x

# Compilation avec rpcgen d'une sp�cification (.x) d'un programme distant: 
# la compilation g�n�re des fichiers _clnt.c, _svc.c, _xdr.c, $(RDICT).h
$(RDICT).h: $(RDICT).x
	rpcgen $(RDICT).x
#
# Objets pour le client
#

# Programme client 
$(RDICT).o: $(RDICT).c $(RDICT).h $(RDICT).x CodeClient.hc

# Souche pour le client
$(RDICT)_clnt.o: $(RDICT)_clnt.c $(RDICT).h $(RDICT).x

# Glue pour le client que le programmeur ajoute manuellement
$(RDICT)_cif.o: $(RDICT)_cif.c $(RDICT).h $(RDICT).x

#
# Objets pour le serveur
#

# Souche pour le serveur
$(RDICT)_svc.o: $(RDICT)_svc.c $(RDICT).h $(RDICT).x

# Glue pour le serveur que le programmeur ajoute manuellement
$(RDICT)_sif.o: $(RDICT)_sif.c $(RDICT).h $(RDICT).x

# Proc�dures ex�cut�es sur le serveur
$(RDICT)_srp.o: $(RDICT)_srp.c $(RDICT).h $(RDICT).x DictProcedures.hc

#
# Objet pour le codage/d�codage XDR des requ�tes et des r�ponses 
#
$(RDICT)_xdr.o: $(RDICT)_xdr.c $(RDICT).h $(RDICT).x


# Ex�cutable client
$(RDICT): $(RDICT)_clnt.o $(RDICT)_cif.o $(RDICT).o $(RDICT)_xdr.o 
	$(CC) -o $(RDICT) $(RDICT)_clnt.o $(RDICT)_cif.o $(RDICT).o $(RDICT)_xdr.o 
			

# Ex�cutable serveur
$(RDICT)demon: $(RDICT)_svc.o $(RDICT)_sif.c $(RDICT)_srp.o $(RDICT)_xdr.o
	$(CC) -o $(RDICT)demon $(RDICT)_svc.o $(RDICT)_sif.c $(RDICT)_srp.o $(RDICT)_xdr.o


