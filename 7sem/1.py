import numpy as np

k = 2
delta = 0.01

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

def xk_del():
	return F(k * delta) *  np.transpose(np.matrix(cnstant)) - np.linalg.inv(mtx) * np.transpose(np.matrix(vt))

def A_wave():
	return F(delta) * np.linalg.inv(F(0)) * xk_del() + vk() + F(delta) * np.linalg.inv(F(0))

def vk():
	return (F(delta) * np.linalg.inv(F(0)) * np.linalg.inv(mtx) - np.linalg.inv(mtx)) * np.transpose(np.matrix(vt))

def yk1():
	return A_wave() * xk_del() + vk()


print("A:\n")
print(mtx,"\n")
print("v(t):\n")
print(vt,"\n")
print("A wave:\n")
print(A_wave(),"\n")
print("v_k:\n")
print(vk(),"\n")
print("y_k:\n")
print(xk_del(),"\n")
print("y_k+1:\n")
print(yk1(),"\n")