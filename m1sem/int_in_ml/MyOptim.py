import numpy as np
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter

def my_func(x):
    return x**2 + 2 * x *  - np.sin(x)

x = np.linspace(-2, 2, 101)
y = my_func(x) #+ np.sin(x * 25.5)

plt.plot(x, y)

from scipy.misc import derivative

def grad(fun, x_0, alpha, eps):
    x = 1000
    while (1):
        if abs(x - x_0) < eps:
            break
        x = x_0
        x_0 = x - alpha * derivative(fun, x)
    return x


x0 = 2

my_min = grad(my_func, x0, 0.01, 0.0000001)
print(my_func(my_min))