import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import matplotlib.pyplot as plt

mpl.rcParams['legend.fontsize'] = 10

fig = plt.figure()
ax = fig.gca(projection='3d')

dots = 100

phi = np.linspace(0, 2 * np.pi, dots)
r = np.linspace(0, 1, dots)
u = 2 * r * np.sin(phi)

ax.plot(u, r, phi, label='u(r, phi)')

ax.set_xlabel(r'u')
ax.set_ylabel(r'r')
ax.set_zlabel(r'phi')

ax.legend()

plt.savefig("umf2_3D.png")

plt.show()