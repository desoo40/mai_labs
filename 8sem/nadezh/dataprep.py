import math
import numpy as np
import random

lmbds = []
mus = []

for i in range(0, 6):
    lmbds.append(random.uniform(1e-7, 1e-2))
    mus.append(random.uniform(1e-7, 1e-2))

np.savetxt("lm.txt", lmbds)
np.savetxt("mu.txt", mus)
