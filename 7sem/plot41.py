import numpy as np
import random
import matplotlib.pyplot as plt

T0 = 300
T1 = 500
a = 1e-3
b = 1e-6
l = 0.1
c = 1


def lmd(n, x):
    return 0.25 + 236 * n / x**2

def sum(x, t):

    ans = 0

    for i in range(0,100):
        ans += c * np.exp(x / 2) * np.sin(np.sqrt(lmd(i, x) - 0.25) * x) * (T0 - T1) * np.exp(- lmd(i, x) * a * a * t)

    return ans;


def u(x,t):

    if t == 0:
        return T0

    return T1 + sum(x,t)

x = np.arange(0, l, 0.0005)
plt.xlabel('x (м)')
plt.ylabel('u(x, t) (K)')

def plot(xrang, t):
    label_str = "t = {:.1f} (с)".format(t)
    y = []
    for x in xrang:
        y.append(u(x, t))
    plt.plot(xrang, y, label=label_str)

plot(x, 0)
plot(x, 0.5)
plot(x,1.)
plot(x,5.)
plot(x,10.)
plot(x,100.)


plt.legend()
plt.show()

plt.savefig("teplo_inf.png")