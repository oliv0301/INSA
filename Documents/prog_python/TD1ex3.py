def second_between(y1,m1,d1,y2,m2,d2):
    """nb second between two date"""
    assert y1 and y2>=0, m1 and m2 and d1 and d2 >0
    if y2 > y1:
        y=y2-y1
        m=m2-m1
        d=d2-d1
    elif y2==y1:
        if m2>m1:
            y=0
            m=m2-m1
            d=d2-d1
        elif m2==m1:
            if d2>d1:
                d=d2-d1
                m=0
                y=0
            else:
                return 0
    else:
        y=y1-y2
        m=m1-m2
        d=d1-d2

    d=365,2425*y+30*m+d
    return 31536000*d
        
print (second_between(1,1,1,1,1,2))
