def isqrt_hard(n):
    """return the bottom boundary of a square root"""
    i=0
    while i*i<n:
        i=i+1
    if i*i>n:
        print(i-1)
    else :
        print(i)

def isqrt_sum(n):
    s=0
    i=0
    for impair in range (1, n*2, 2):
        s=s+impair
        i=i+1
        if s > n:
            return i-1

def isqrt_dicho(n, i=0):
    if i==0:
        i=n/2
    if i*i<n+1:
        return i
    elif i*i>n:
        isqrt_dicho(n, i/2)
    elif i*i<n:
        isqrt_dicho(n, n-(i/2))
    

    
    
