import numpy as np
import math
import copy
x = np.arange(0, 5*np.pi/4, np.pi/4)
t = np.arange(0, 0.6, 0.1)
a1=3
a2=5
a3=1
a4=-4
h=np.pi/4
T=0.1
PH2= -7
PH5= -3

def y0(t):
    return -t/(np.exp(-t))
def yL(t):
    return t*t/(np.exp(-t))
def Y(x):
    return np.sin(x)
def Yt(x):
    return np.cos(x)
def f(x,t):
    return (x*t)/(1+x*x+2*t*t)

def prog(a, b, c, d):
    n = len(d)
    x=np.zeros(n)
    p = [-c[0] / b[0]]
    q = [d[0] / b[0]]
    for i in range(1, n):
        p.append(-c[i] / (b[i] + a[i] * p[i - 1]))
        q.append((d[i] - a[i] * q[i - 1]) / (b[i] + a[i] * p[i - 1]))
    x[-1] = q[-1]
    for i in reversed(range(n-1)):
        x[i] = p[i] * x[i + 1] + q[i]
    return x

U = np.zeros((len(t), len(x)))
for i in range(len(t)):
    for j in range(len(x)):
        if i == 0:
            U[i,j] = Y(x[j])
        elif i == 1:
            U[i,j] = U[0,j] + T*Yt(x[j])
        else:
            if j == 0:
                U[i,j] = (1/PH2)*y0(t[i])
            elif j == len(x)-1:
                U[i,j] = (1/PH5)*yL(t[i])
            else:
                U[i,j] = (1/(2+a1*T))*(4*U[i-1,j] + (a1*T-2)*U[i-2,j] + ((2*a2*T*T)/(h*h))*(U[i-1,j-1] + U[i-1,j+1] - 2*U[i-1,j]) + ((a3*T*T)/(h))*(U[i-1,j+1] - U[i-1,j-1]) + 2*T*T*(a4*U[i-1,j] + f(x[j],t[i-1])))
print('Явная схема')
print('            ', end = ' ')
for j in range(len(x)):
    print('x = ', "%.2f" %x[j], end = '  ')
print(' ')
for i in range(len(t)):
    print('t = ',"%.3f" % t[i], end = '  ')
    for j in range(len(x)):
        print("%.8f" % U[i,j], end = '  ')
    print(' ')

print('\nНеявная схема')
U = np.zeros((len(t), len(x)))
for j in range(len(x)):
    U[0,j] = Y(x[j])
for j in range(len(x)):
    U[1,j] = U[0,j] + T*Yt(x[j])
for i in range(2, len(t)):
    aa = np.zeros(len(x))
    bb = np.zeros(len(x))
    cc = np.zeros(len(x))
    dd = np.zeros(len(x))
    dd[0] = y0(t[i])/PH2
    dd[-1] = yL((t[i]))/PH5
    bb[0] = 1
    bb[-1] = 1
    for j in range(1,len(x)-1):
        aa[j] = 2*a2 - h*a3
        bb[j] = 2*h*h*(-a1/(2*T) - 1/(T*T) + a4) - 4*a2
        cc[j] = h*a3 + 2*a2
        dd[j] = -(4*h*h/(T*T))*U[i-1, j] + (2*h*h/(T*T) - a1*h*h/T)*U[i-2,j] - 2*h*h*f(x[j],t[i])
    xx = prog(aa, bb, cc, dd)
    for j in range(len(x)):
        U[i, j] = xx[j]

print('            ', end = ' ')
for j in range(len(x)):
    print('x = ', "%.2f" %x[j], end = '  ')
print(' ')
for i in range(len(t)):
    print('t = ',"%.3f" % t[i], end = '  ')
    for j in range(len(x)):
        print("%.8f" % U[i,j], end = '  ')
    print(' ')



    
