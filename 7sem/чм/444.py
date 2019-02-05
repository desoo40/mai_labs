import numpy as np
import math
import copy

x = np.arange(0, 1.25, 0.25)
y = np.arange(0, 1.25, 0.25)

d = 3
a = 3
b = -2
c = 0
hx = 0.25
hy = 0.25

def f(x,y):
    return np.sin(x*y)
def phi1(y):
    return -np.sin(np.pi*y)/(-3)
def phi3(x):
    return np.sin(np.pi*x)/(-2)
def phi2(y):
    return -3*y/3
def phi4(x):
    return -3*x/(-3)

def copym(U):
    a, b = np.shape(U)
    UN = np.zeros((a,b))
    for  j in range(a):
        for i in range(b):
            UN[j,i] = U[j,i]
    return UN

U = np.zeros((len(y), len(x)))
for i in range(len(x)):
    U[0,i] = phi3(x[i])
    U[-1,i] = phi4(x[i])
for j in range(1, len(y)-1):
    U[j,0] = phi1(y[j])
    U[j,-1] = phi2(y[j])

for j in range(1, len(y)-1):
    for i in range(1, len(x)-1):
        U[j,i] = U[j,0] + (U[j,-1] - U[j,0])*i*hx
print('0 поверхность')
print('           ', end = ' ')
for i in range(len(x)):
    print('x =', "%.1f" %x[i],"    ", end = ' ')
print(' ')
for j in range(len(y)):
    print('y = ',"%.3f" % y[j], end = '  ')
    for i in range(len(x)):
        print("%.8f" % U[j,i], end = '  ')
    print(' ')


for k in range(1, 16):
    print(k, ' поверхноть')
    L = copym(U)
    U = np.zeros((len(y), len(x)))
    for j in range(1, len(y)-1):
        for i in range(1, len(x)-1):
            U[j,i] = (hx*hx*f(x[i],y[j]) - (L[j,i+1] + L[j,i-1]) - d*hx*hx*(L[j+1,i]+L[j-1,i])/(hy*hy) - a*hx*0.5*(L[j,i+1] - L[j,i-1]) - b*hx*hx*(L[j+1,i] - L[j-1,i])*0.5/hy)/(c*hx*hx - 2*(hy*hy + d*hx*hx)/(hy*hy))

    for i in range(len(x)):
        U[0,i] = phi3(x[i])
        U[-1,i] = phi4(x[i])
    for j in range(1, len(y)-1):
        U[j,0] = phi1(y[j])
        U[j,-1] = phi2(y[j])
    
    print('           ', end = ' ')
    for i in range(len(x)):
        print('x =', "%.1f" %x[i],"    ", end = ' ')
    print(' ')
    for j in range(len(y)):
        print('y = ',"%.3f" % y[j], end = '  ')
        for i in range(len(x)):
            print("%.8f" % U[j,i], end = '  ')
        print(' ')

