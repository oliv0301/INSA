def biss(y):
    assert y>1582
    return (y%4==0 and y%100!=0) or y%400==0

def longest_month(y,m):
    assert 0<m<=12
    if biss(y) and m==2:
        return 29
    elif m==2:
        return 28
    elif m==1 or m==3 or m==5 or m==7 or m==8 or m==10 or m==12:
        return 31
    else:
        return 30

def is_valid_date(y,m,d):
    return 0<m<=12 and 0<d<=longest_month(y,m)
    
def hard_way(y,m,d):
    """lundi 1 mardi 2 mercredi 3 jeudi 4 vendredi 5 samedi 6 dimanche 0"""
    assert is_valid_date(y,m,d)
    return (1+difference_date(y,m,d,1900,1,1))%7
    
        
def days_past(y, m, d):
    """return the numbers of days since the beginning of the year"""
    nb=0
    for i in range(1, m):
        nb=nb + longest_month(y, i)
    nb_days_past = d + nb
    #print("nombre de jour passé",nb_days_past)
    return nb_days_past
        
    
def difference_date(y1,m1,d1,y2,m2,d2):
    """ return the numbers of days between two dates"""
    if (y1,m1,d1)<(y2,m2,d2): #y2=1900 pour notre exo
        return -difference_date(y2,m2,d2, y1,m1,d1)
    nb_days=0
    for i in range (y2, y1):
        for j in range (1, 13):
            nb_days = nb_days + longest_month(i, j)
    #print("nombre de jour entre les années", nb_days)
    nb_days = nb_days-days_past(y2,m2,d2)
    nb_days = nb_days+days_past(y1,m1,d1)
    return nb_days
    
    
#calcul de la somme des années sigma, sum(longueur(m) for m' entre 1 et m
#calcul nombre de jours dans année
#numero dans le mois
#nombre de jour+1 modulo 7

def calendrier(y, m, weekday=weekday_delambre):
    """print the calendar of the month given in parameters"""
    if weekday==weekday_delambre:
        j1=delambre(y,m,1)
    else:
        j1=hard_way(y,m,1)
    d=1
    i=0
    print("jour 1 =", j1)
    liste_mois=['Janvier', 'Fevrier', 'Mars', 'Avril', 'Mai', 'Juin', 'Juillet', 'Aout', 'Septembre', 'Octobre', 'Novembre', 'Decembre']
    liste_jours=['di', 'lu', 'ma', 'me', 'je', 've', 'sa']
    print(liste_mois[m+1], " ", y, "\n", "di lu ma me je ve sa")
    print("   " * j1, end='')
    while d<=longest_month(y, m):
        if d<10:
            print("",d,"", end='')
        else :
            print(d,"", end='')
        d=d+1
        if j1==6:
            print()
            j1=0
        else :
            j1=j1+1
    
    
calendrier (2018, 9)

def delambre(y, m, d):
    l=[4,0,0,3,5,1,3,6,2,4,0,2]
    if biss(y) and m==1:
        m=3
    elif biss(y) and m==2:
        m=6
    else:
        m=l[m-1]
    print("jour = ",((d+m+int((21/4)*(int(y/100)))+int((5/4)*(y%100)))+2)%7)
    
def seconds_between_deluxe(y1,m1,d1,y2,d2,m2):
    diff_day=difference_date(y1,m1,d1,y2,m2,d2)
    print("il y a ", 60*60*24*diff_day, "seconde entre les deux dates")







    
    
