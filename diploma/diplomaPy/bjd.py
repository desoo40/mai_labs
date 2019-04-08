import math

def simpson(f, a, b, n):
    h=(b-a)/n
    k=0.0
    x=a
    for i in range(1, int(n/2)):
        x += 2*h
        k += 4*f(x)
    for i in range(2,int((n/2)-1)):
        x += 2*h
        k += 2*f(x)
    return (h/3)*(f(a)+f(b)+k)

def function(x):
    return x*x*x - 2 * x + 3

a = simpson(function, 0.0, 5.0, 10000)
print (a)