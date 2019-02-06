import numpy as np

def f(x, t):
    return ((x + 5) / (t + 9))

def f1(t):
    return (-15.0 - t/3)

def f2(t):
    return (12.0 + t**2/(-3) - 0.8*t)

def f3(x):
    return (3 + 7 * np.sin(1.57079633 * x))

def main():
    alpha1 = 4
    alpha2 = -7
    alpha3 = -6
    #phi1 = 5
    phi2 = -5
    #phi4 = 5
    phi5 = 4
    hx = 0.8
    ht = 0.025
    tend = 0.1
    x = 4
    t = 0
    y = np.zeros((5, 6))
    print(y)

    for j in range(0, 6):
        y[0, j] = f3(x + j*hx)

    for i in range(1,5):
        t += ht
        for j in range(1, 5):
            y[i, j] = (alpha1*ht/(hx**2) - alpha2*ht/(2*hx))*y[i-1, j-1] + (alpha1*ht/(hx**2) + alpha2*ht/(2*hx))*y[i-1, j+1] + (ht*alpha3 + 1 - 2*alpha1*ht/(hx**2))*y[i-1, j] + ht * f(x + j*hx, t - ht)

        y[i, 0] = (hx * f1(t)) / (hx * phi2)
        y[i, 5] = (hx * f2(t)) / (hx * phi5)

    for i in range(0, 5):
        print(y[i,0], " ", y[i,1], " ", y[i,2], " ", y[i,3], " ", y[i,4], " ", y[i,5])

main()