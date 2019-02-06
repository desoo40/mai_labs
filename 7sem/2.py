import numpy as np

delta = 0.01

mtx = np.loadtxt("input.txt", dtype='i', delimiter=' ')

#mtx = np.matrix(mtx)

if np.linalg.det(mtx) == 0:
	print("Singulat mtx. Goodbye");
	quit()

eVal, eVec = np.linalg.eig(mtx)

print("eigValues:\n")
print(eVal,"\n")

print("eigVectors:\n")
print(eVec,"\n")

def F(param):
	tmp = []
	for i in range(0,eVal.size):
		kek = eVec[i] * np.exp(eVal[i] * param)
		tmp.append(kek)

	#print(f"F{param}:\n", tmp)
	return np.matrix(tmp)

def A_wave():
	return F(delta) * np.linalg.inv(F(0))

def V_wave():
	return F(delta) * np.linalg.inv(F(0)) * np.linalg.inv(mtx) * np.linalg.inv(mtx)

print("A:\n")
print(mtx,"\n")
print("A wave:\n")
print(A_wave(),"\n")
print("V wave:\n")
print(V_wave(),"\n")