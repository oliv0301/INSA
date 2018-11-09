def chiffrement():
    """print a chiffrement table"""
    alphabet=["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]
    #print(alphabet)
##    for i in range (len(alphabet)):
##        print()
##        j=i
##        for k in range(len(alphabet)):
##            print(alphabet[j], end='')
##            j+=1
##            if j==len(alphabet):
##                j=0
    for i in range (65,91):
        print()
        j=i
        for k in range(65,91):
            print(chr(j), end='')
            j+=1
            if j==91:
                j=65

def crypt(msg, key, mode=False):
    crypt=""
    j=0
    taille=len(key)
    if mode:
        for i in range(len(msg)):
            crypt+=chr(65+(ord(msg[i])-ord(key[j%taille]))%26)
            j+=1
    else :
        for i in range(len(msg)):
            crypt+=chr(65+(ord(msg[i])+ord(key[j%taille]))%26)
            j+=1
    print(crypt)
    return crypt
    

def autobreak(msg):
    import ngram_score as ns
    fitness = ns.ngram_score()
    key="A"
    liste_keys=[]
    score_key=-1000
    for i in range (10):
        liste_keys.append(i)
        for j in range(len(key)):
            for k in range (65, 91):
                key[j]=chr(k)
                if fitness.score(crypt(msg, key, True))>score_key:
                    liste_keys[i]=key;
        key+="A"
    
    
    
    
    




    
                
        
        
    
