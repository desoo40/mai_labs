import numpy as np
import math
import copy
x = np.arange(1, 5.8, 0.8)
t = np.arange(0, 0.125, 0.025)
y = np.zeros(len(x))
a = 4
b = 1
c = 2.5
tau = 0.025
h = 0.8
def f(x,t):
    return (x + 3)/(t + 2)
def yl(t):
    return (52 + t/(-2))/4
def yr(t):
    return (52 + t*t/(2) - 0.2*t)/4
def y0(x):
    return 4 + 9*np.sin(x*np.pi/2)
def tma(a, b, c, d):
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
#################
U = np.zeros((len(t), len(x)))
for i in range(len(t)):
    for j in range(len(x)):
        if i == 0:
            U[i,j] = y0(x[j])
        else:
            if j == 0:
                U[i,j] = yl(t[i])
            elif j == len(x)-1:
                U[i,j] = yr(t[i])
            else:
                U[i,j] = U[i-1,j] + (a*tau/h**2)*(U[i-1,j-1] - 2*U[i-1,j] + U[i-1,j+1]) + (b*tau*0.5/h)*(- U[i-1,j-1] + U[i-1,j+1]) + c*tau*U[i-1,j] + tau*f(x[j],t[i-1])
print('Явная')
print('           ', end = ' ')
for j in range(len(x)):
    print('x =', "%.1f" %x[j],"    ", end = ' ')
print(' ')
for i in range(len(t)):
    print('t = ',"%.3f" % t[i], end = '  ')
    for j in range(len(x)):
        print("%.8f" % U[i,j], end = '  ')
    print(' ')
#################

U2 = np.zeros((len(t), len(x)))
a2= np.zeros(len(x))
b2= np.zeros(len(x))
c2= np.zeros(len(x))
d2= np.zeros(len(x))
for j in range(len(x)):
    U2[0,j] = y0(x[j])

for i in range(len(x)):
    if i == 0 or i == 5:
        b2[i]=1
    else:
        a2[i] = (2*a - h*b)*tau/(2*h**2)
        b2[i] = (c*tau - 2*a*tau/h**2 -1)
        c2[i] = (2*a + h*b)*tau/(2*h**2)
for k in range(1,len(t)):    
    d2[0] = yl(t[k])
    d2[-1] = yr(t[k])
    for i in range(1, len(x) - 1):
        d2[i] = - U2[k-1,i] - tau*f(x[i],t[k])
    d2_NEW = tma(a2,b2,c2,d2)
    for j in range(len(x)):
        U2[k,j] = d2_NEW[j]
    
#print('###################')
print('Неявная')
print('           ', end = ' ')
for j in range(len(x)):
    print('x =', "%.1f" %x[j],"    ", end = ' ')
print(' ')
for i in range(len(t)):
    print('t = ',"%.3f" % t[i], end = '  ')
    for j in range(len(x)):
        print("%.8f" % U2[i,j], end = '  ')
    print(' ')


print('\nЯвно - неявная схема')
print('teta = ', end = '')
teta = float(input())
U = np.zeros((len(t), len(x)))
for j in range(len(x)):
    U[0, j] = y0(x[j])
for i in range(1, len(t)):
    aa = np.zeros(len(x))
    bb = np.zeros(len(x))
    cc = np.zeros(len(x))
    dd = np.zeros(len(x))
    dd[0] = yl(t[i])
    dd[-1] = yr((t[i]))
    bb[0] = 1
    bb[-1] = 1
    for j in range(1,len(x)-1):
        aa[j] = teta*(2*a - b*h)*tau*0.5/(h**2)
        bb[j] = c*tau*teta - teta*2*a*tau/(h**2) - 1
        cc[j] = teta*(2*a + h*b)*tau*0.5/(h**2)
        dd[j] = -U[i-1, j] - teta * tau * f(x[j],t[i]) - (1 - teta) * ((a*tau/h**2)*(U[i-1,j-1] - 2*U[i-1,j] + U[i-1,j+1]) + (b*tau*0.5/h)*(- U[i-1,j-1] + U[i-1,j+1]) + c*tau*U[i-1,j] + tau*f(x[j],t[i-1]))
    xx = tma(aa, bb, cc, dd)
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

