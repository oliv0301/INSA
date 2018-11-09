#!/usr/bin/env python 

#
# HISTORY
#
# Version v0 
#
# Version v0.1
#
# Correcting a bug for challenge11: 
#  #include "file.h" should be inserted after #include "arbre.h"
#
# Version v0.2 (Pascal/01/2018)
#
# Adapting the challenges to the new subject
# Changing the sequence generation  with a more (?) complex function (this function ensures that
#  the ASCII code of final letter belongs to the sequence, this sequence appears to have less 
#  collisions than the previous one (experimental) 
# Changing the 5th letter by the final letter of the name 

import sys, getopt, string, getpass




start = """#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arbre.h"
INCLUDEFILE

int main()
{
    printf("=====\\nBEGIN [AUTHOR] C#=CHAL\\n");

    arbre * noeud0 = NULL;
"""


end = """
    printf("\\nEND [AUTHOR]\\n===\\n");
    return 0;
}
"""



def generate_numbers(name, MAX):
  
  sequence = []
  repeat = 0
  lg = len(name)
  while lg*(repeat) < MAX:
    i=0
    for c in name:
      i = i+1
      val = ((lg-i)*ord(c)*ord(c) + ord(c) + 5*i*repeat -1) %120+1
      val2 =  ((lg-i)*ord(c)*ord(c) + ord(c) + 5*(i-lg)*(repeat+6) -1)
      #print str(i) + "  " + c  + "  " + str(val)  + "  " + str(val2)
      sequence.append(val )
    repeat = repeat + 1
  print "Generated length: " + str(len(sequence)) + " >= " + str(MAX)
  print "Test sequence: " + str(sequence)
  return sequence

class Cell:
  def __init__(self, i, root):
    self.fg = None
    self.fd = None
    self.number = i
    self.val = int(root)

def write_code_with_table(challenge, f, sequence, root):
    f.write("    noeud0 = creerNoeud(" + root + ");\n")
    f.write("    int * tableau = calloc( " + str(len(sequence)) + ", sizeof(int));\n")
    for i in range(len(sequence)):
      f.write("    tableau[" + str(i) + "] = " + str(sequence[i]) + ";\n");
    f.write("    insererTableau(noeud0, tableau, " + str(len(sequence)) + ");\n");

def write_code(challenge, f, sequence, name):

  root = str(reduce(lambda x, y: x + y, sequence[:4]) / len(sequence[:4])) # Average of the 4 first numbers
  print "Root: " + root

  if challenge == '1':
    # noeud * noeud1 = creerNoeud(5);
    # accroche(noeud X , noeud1);
    f.write("""    printf("=> Calling accroche\\n");\n""")
    f.write("noeud0 = creerNoeud(" + root + ");\n")
    r = Cell(0, root)

    for i in range(len(sequence)):
      pt = r # pointing on the root
      while pt.fg != None and pt.val >= sequence[i] or pt.fd != None and pt.val < sequence[i]:
        if pt.val >= sequence[i]:
          pt = pt.fg # going on left son
        else:
          pt  = pt.fd # going on right son
      if pt.val >= sequence[i]:
        pt.fg = Cell(i+1,sequence[i])
      else:
        pt.fd = Cell(i+1,sequence[i])
      
      #print "Inserting at " + str(pt.val) + " node " + str(sequence[i])
      
      f.write("    noeud * noeud" + str(i+1) + " = creerNoeud(" + str(sequence[i]) + ");\n");
      f.write("    accroche(noeud" + str(pt.number) + ", noeud" + str(i+1) + ");\n");

  elif challenge == '2':
    # noeud * noeud1 = creerNoeud(5);
    # accroche(unArbre, noeud1);
    f.write("""    printf("=> Calling insererDansArbre\\n");\n""")
    f.write("    noeud0 = creerNoeud(" + root + ");\n")

    for i in range(len(sequence)):
      f.write("    noeud * noeud" + str(i+1) + " = creerNoeud(" + str(sequence[i]) + ");\n");
      f.write("    insererDansArbre(noeud0, noeud" + str(i+1) + ");\n");

  elif challenge == '3':
    # int tableau[10] = {1, 45, 800, -40, 300, 4, 5, 333, 1001, 700};
    # insererTableau(unArbre, tableau, 10)
    f.write("""    printf("=> Calling insererTableau\\n");\n""")
    write_code_with_table(challenge, f, sequence, root) # Generates the tree with sequence

  elif challenge == '4':
    # afficher(unArbre,0);
    f.write("""    printf("=> Calling afficher\\n");\n""")
    write_code_with_table(challenge, f, sequence, root) # Generates the tree with sequence
    f.write("    afficher(noeud0, 0);\n")

  elif challenge == '5':
    # afficher(unArbre,0);
    f.write("""    printf("=> Switch imprimerChiffre = 1\\n");\n""")
    f.write("    imprimerChiffre = 1;\n")
    write_code('4', f, sequence, name)
   
  elif challenge == '6':
    # rechercherDerniereLettre(noeud0)
    f.write("""    printf("=> Calling rechercherDerniereLettre and comparing the value\\n");\n""")
    write_code_with_table(challenge, f, sequence, root) # Generates the tree with sequence
    #if (len(name) >= 5):
    #  letter5 = name[4]
    #else:
    letter5 = name[-1:]
    f.write("    noeud * n5 = rechercherDerniereLettre(noeud0);\n")
    f.write("    printf(\"Node found for your final letter: %i (%c) =? " + str(ord(letter5)) + " (" + letter5 + ") \\n\", n5->valeur, n5->valeur); ")

  elif challenge == '7':
    # rechercherDerniereLettre(noeud0)
    f.write("""    printf("=> Calling deforestationSauvage for your final letter\\n");\n""")
    write_code_with_table(challenge, f, sequence, root) # Generates the tree with sequence
    f.write("    imprimerChiffre = 1;\n")
    f.write("    afficher(noeud0, 0);\n")
    f.write("    noeud * n5 = rechercherDerniereLettre(noeud0);\n")
    f.write("    deforestationSauvage(n5);\n")
    f.write("    printf(\"\\n============ SAVAGE CUT of " + str(unichr(sequence[4])) + " ============\\n\");\n")
    f.write("    afficher(noeud0, 0);\n")

  elif challenge == '8':
    # rechercherDerniereLettre(noeud0)
    f.write("""    printf("=> Calling deforestation for your final letter\\n");\n""")
    write_code_with_table(challenge, f, sequence, root) # Generates the tree with sequence
    f.write("    afficher(noeud0, 0);\n")
    f.write("    noeud * n5 = rechercherDerniereLettre(noeud0);\n")
    f.write("""      printf("\\nSearching your final letter: %i\\n", n5->valeur);\n""")
    f.write("    noeud * n5g = n5->FGauche;\n")
    f.write("    noeud * n5d = n5->FDroit;\n")
    f.write("    if (n5g != NULL) {\n")
    f.write("    int old = n5g->valeur;\n")
    f.write("""      printf("Left child: %i\\n", n5g->valeur);\n""")
    f.write("""      printf("Cutting properly !\\n");\n""")
    f.write("""      deforestation(n5);\n""")
    f.write("""      printf("Left child (should not be %i): %i\\n", old, n5g->valeur);\n""")
    f.write("""    } else { printf("Not lucky, the left child is NULL.\\n"); }""")

  elif challenge == '9':
    f.write("""    printf("=> Calling parcoursProfondeur\\n");\n""")
    write_code_with_table(challenge, f, sequence, root) # Generates the tree with sequence
    f.write("    afficher(noeud0, 0);\n")
    f.write("    printf(\"\\nDepth-first traversal: \\n\");")
    f.write("    parcoursProfondeur(noeud0);\n")
    f.write("    printf(\"\\nSum: %i (should be %i) \\n\", somme(noeud0), " + str(sum(sequence)+int(root)) +");")

  elif challenge == '10':
    choixPetit = int(len(sequence)/3)
    f.write("""    printf("=> Searching from """ + str(choixPetit) + """ and calling couperPetits\\n");\n""")
    write_code_with_table(challenge, f, sequence, root) # Generates the tree with sequence

    print "Searching from " + str(choixPetit)
    while choixPetit < len(sequence)-1 and sequence[choixPetit] >= int(root):
      choixPetit = choixPetit + 1
    if sequence[choixPetit] >= int(root):
      choixPetit = 0
      while choixPetit < len(sequence)-1 and sequence[choixPetit] > int(root):
        choixPetit = choixPetit + 1
    print "Found " + str(sequence[choixPetit]) + " < " + str(root)
    if sequence[choixPetit] < int(root):
      f.write("    afficher(noeud0, 0);\n")
      f.write("    printf(\"\\nChoosen value for LittleCut: %i\\n\", " + str(sequence[choixPetit]) +" );\n")
      f.write("    couperPetits(noeud0, " + str(sequence[choixPetit]) + ");\n")
      f.write("    afficher(noeud0, 0);\n")
    else:
      f.write("    printf(\"\\nNot lucky: his name has only letters greather than the root !!!! :( \\n\");")

  elif challenge == '11':
    f.write("""    printf("=> Generating a queue of 5 elements\\n");\n""")
    f.write("    file * f = malloc(sizeof(file));\n")
    f.write("    f->taille=0;\n")
    f.write("    f->premier=NULL;\n")
    f.write("    f->dernier=NULL;\n")
    for i in range(5):
      f.write("    noeud * noeud" + str(i+1) + " = creerNoeud(" + str(sequence[i]) + ");\n");
      f.write("""    printf("Queuing """ + str(sequence[i]) + """\\n");\n""")
      f.write("    enfiler(f, noeud" + str(i+1) + ");\n")
      f.write("""    printf("Reverse print of the queue: ");\n""")
      f.write("    printFile(f);\n")

  elif challenge == '12':
    #parcoursLargeur(unArbre);
    f.write("""    printf("=> Queuing all nodes and printing on a line (Breadth First Search)\\n");\n""")
    write_code_with_table(challenge, f, sequence, root) # Generates the tree with sequence
    f.write("    afficher(noeud0, 0);\n")
    f.write("    printf(\"\\n\");")
    f.write("    printf(\"Breadth First Search from root:\\n\");")
    f.write("    parcoursLargeur(noeud0);\n")  
    f.write("    noeud * n5 = rechercherDerniereLettre(noeud0);\n")
    f.write("    printf(\"\\n\");")
    f.write("    printf(\"Breadth First Search from your final letter: %i\\n\", n5->valeur);")
    f.write("    parcoursLargeur(n5);\n")  

  elif challenge == '13':
    #parcoursLargeur(unArbre);
    f.write("""    printf("=> Queuing all nodes and printing on a line (Breadth First Search) + Carriage Return\\n");\n""")
    write_code_with_table(challenge, f, sequence, root) # Generates the tree with sequence
    f.write("    afficher(noeud0, 0);\n")
    f.write("    printf(\"\\n\");\n")
    f.write("    parcoursProfondeur(noeud0);\n")
    f.write("    printf(\"\\n\");\n")
    f.write("    printf(\"Breadth First Search from root:\\n\");\n")
    f.write("    parcoursLargeur(noeud0);\n")  
    f.write("    noeud * n5 = rechercherDerniereLettre(noeud0);\n")
    f.write("    printf(\"\\n\");\n")
    f.write("    printf(\"Breadth First Search from your final letter: %i\\n\", n5->valeur);\n")
    f.write("    parcoursLargeur(n5);\n")  

  elif challenge == '14' or challenge == '15':
    #parcoursLargeur(unArbre);
    if challenge == '14':
      f.write("""    printf("=> Final Display !!!\\n");\n""")
    else:
      f.write("""    printf("=> Final Display WITH bars !!! WOW !!!\\n");\n""")
    write_code_with_table(challenge, f, sequence, root) # Generates the tree with sequence
    f.write("    afficher(noeud0, 0);\n")
    f.write("    printf(\"\\n\");\n")
    f.write("    int niveaumax = parcoursProfondeur(noeud0);\n")
    f.write("    printf(\"\\n\");\n")
    f.write("    printf(\"Breadth First Search from root:\\n\");\n")
    f.write("    parcoursLargeur(noeud0, niveaumax);\n")  
    f.write("    noeud * n5 = rechercherDerniereLettre(noeud0);\n")
    f.write("    printf(\"\\n\");\n")
    f.write("    niveaumax = parcoursProfondeur(n5);\n")
    f.write("    printf(\"\\n\");\n")
    f.write("    printf(\"Breadth First Search from your final letter: %i\\n\", n5->valeur);\n")
    f.write("    parcoursLargeur(n5, niveaumax);\n")  
    
  else:
    f.write("    printf(\"CHALLENGE NOT IMPLEMENTED ! GO AWAY !\\n\");")

def generate_starting(start, challenge, name):
  entete = ""
  if int(challenge) < 11:
    entete = start.replace("INCLUDEFILE", "")
  else:
    entete = start.replace("INCLUDEFILE", """#include "file.h" """)
  
  return entete.replace("CHAL", challenge).replace("AUTHOR", name)

def generate_challenge(challenge, name, MAX):

  filename = "challenge"+challenge+".c"
  f = open(filename, "w")
  # Generates the starting of the main file
  f.write(generate_starting(start, challenge, name))

  # Generating instructions for the main  
  sequence = generate_numbers(name, MAX) # Generates unique sequence
  write_code(challenge, f, sequence, name)

  f.write(end.replace("AUTHOR", name))
  print "File generated: " + filename 



if __name__ == '__main__':
  challenge = None
  name = None
  signature = 'python challenge.py -c <k> [-n <name>]'
  try:
    opts, args = getopt.getopt(sys.argv[1:],"hc:n:",["challenge=", "name="])
  except getopt.GetoptError:
    print signature
    sys.exit(2)
  for opt, arg in opts:
    if opt == '-h':
      print signature
      sys.exit()
    elif opt =='-c':
      challenge = arg
    elif opt =='-n':
      name = string.upper(arg)

  if challenge is None:
    print 'Option -c required !'
    print signature
    sys.exit(2)

  if name is None:
    print 'No name provided using user name'
    name = string.upper(getpass.getuser())
    

  print 'Challenge detected:', challenge	
  print 'Name detected:', name

  if challenge == "1":
    MAX = 6 # Not under 4
  else:
    MAX = 15

  generate_challenge(challenge, name, MAX)
  

