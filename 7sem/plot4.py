import numpy as np
import matplotlib.pyplot as plt

a = np.sqrt(1e-3)

def u(r, phi):
    return 2 * r * np.sin(phi)

x = np.arange(0, 1, 0.005)
plt.xlabel('r')
plt.ylabel('u(r, phi)')

def plot(rrang, phi, kek):
    label_str = "phi = {:.1f}".format(phi)
    y = []
    for r in rrang:
        y.append(u(r, phi))
    plt.plot(rrang, y, linestyle=kek, label=label_str)

plot(x, 0, '-')
plot(x, np.pi / 2, '--')
plot(x, np.pi, ':')
plot(x, 3 * np.pi / 2, ':')
plot(x,2 * np.pi, '-.')


plt.legend()

plt.show()