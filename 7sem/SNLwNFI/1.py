import numpy as np

k = 2
delta = 0.01
t = 0.028
cnstant = [1, 0, 1, 0]
vt = [1, 2, 3, 4]

mtx = np.loadtxt("input.txt", dtype='i', delimiter=' ')
#mtx = np.matrix(mtx)

if np.linalg.det(mtx) == 0:
	print("Singulat mtx. Goodbye");
	quit()

eVal, eVec = np.linalg.eig(mtx)

def F(param):
	tmp = []
	for i in range(0,eVal.size):
		kek = eVec[i] * np.exp(eVal[i] * param)
		tmp.append(kek)

	return np.matrix(tmp)

def x():
	return F(k * delta) * cnstant - np.linalg.inv(mtx) * np.transpose(vt)

print(x())