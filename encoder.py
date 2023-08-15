SIZE=2


PAYLOAD =  "HELLO!!"

def pad(p): 
    return p+("\x00"*(SIZE-(len(p)%SIZE))) # Maybe put \x60 here? \x00 messes with asm a little too much, NOPs may be more efficient.

def find_key(p, k):
    r = []
    for i in range(SIZE):
        r.append(chr(ord(p[i])^ord(k[i])))
    return ''.join(r)

def generate(p): # A python implementation of the encoding process!
    pa = []
    k = ""
    pn = int(len(p)/SIZE)
    for i in range(pn):
        pa.append(p[i*SIZE:(i+1)*SIZE])
    k=pa[0]
    for i in range(1,pn):
        k+=find_key(pa[i], pa[i-1]) # "find" the appropriate key for the received blocks!
    return k
    

def decode(k): # A python implementation of the decoder function.
    ka = []
    p = ""
    kn = int(len(k)/SIZE)
    for i in range(kn):
        ka.append(k[i*SIZE:(i+1)*SIZE])
    p = ka[0]
    for i in range(1,kn):
        p+=find_key(ka[i], p[(i-1)*SIZE:i*SIZE])
    return p





# Driver code!
PAYLOAD = pad(PAYLOAD) # Just some padding to make the whole thing a little cleaner
E = generate(PAYLOAD) 
a = []
print(E)
