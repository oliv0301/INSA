def convert_fahr(t):
    assert t>-273
    """convert celsius to fahrenheit"""
    return (9/5)*t+32
def convert_cel(t):
    assert t>=0
    """ convert fahrenheit to celsius"""
    return (t-32)/(9/5)
    
