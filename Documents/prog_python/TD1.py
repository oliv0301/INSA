from math import sqrt
def root_poly(a,b,c):
    """return the greatest root from a 2deg polynome"""
    assert a!=0
    discr = (b*b)-(4*a*c)
    print (discr)
    if discr >= 0:
        r1 = (-b-sqrt(discr))/(2*a)
        print (r1)
        r2 = (-b+sqrt(discr))/(2*a)
        print (r2)
        return max(r1,r2)
    else:
        return None
