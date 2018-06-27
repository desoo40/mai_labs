import os
import sys
import numpy as np
import math

def QR_method(A, epsilon):
    n = A.shape[0]
    E = np.eye(n)
    k = 0
    eigenvalues = np.zeros(n, dtype = complex)
    end = False
    Q_end = np.eye(n)
    while not end:
        k += 1
        Q = np.eye(n)
        R = np.copy(A)
        for i in range(n - 1):
            v = np.zeros((n, 1))
            sum_square = 0
            for j in range(i, n):
                sum_square += R[j][i]**2
            v[i][0] = R[i][i] + np.sign(R[i][i]) * math.sqrt(sum_square)
            for j in range(i + 1, n):
                v[j][0] = R[j][i]
            if np.matmul(np.transpose(v), v)[0][0] == 0:
               # print('!!!!!!!!!!!!!!!')
                H = np.eye(n)
            else:
                H = np.eye(n) - 2 * np.matmul(v, np.transpose(v)) / np.matmul(np.transpose(v), v)
            R = np.matmul(H, R)
            Q = np.matmul(Q, H)
        
        A = np.matmul(R, Q)
        sum_subdiagonal_item = np.zeros(n - 1)
        for j in range(n - 1):
            for i in range(j + 1, n):
                sum_subdiagonal_item[j] += A[i][j]**2

        eigenvalues_temp = np.zeros(n, dtype = complex)
        j = 0
        while j < (n - 1):
            if math.sqrt(sum_subdiagonal_item[j]) < epsilon:
                eigenvalues_temp[j] = complex(A[j][j], 0)
                j += 1
            else:
                b = A[j][j] + A[j + 1][j + 1]
                D = b**2 - 4 * (A[j][j] * A[j + 1][j + 1] - A[j][j + 1] * A[j + 1][j])
                if D < 0:
                    eigenvalues_temp[j] = complex(b / 2, math.sqrt(abs(D)) / 2)
                    eigenvalues_temp[j + 1] = complex( b / 2, - math.sqrt(abs(D)) / 2)
                else:
                    eigenvalues_temp[j] = complex(b / 2 +  math.sqrt(abs(D)) / 2, 0)
                    eigenvalues_temp[j + 1] = complex( b / 2 - math.sqrt(abs(D)) / 2, 0)
                j += 2
        if eigenvalues_temp[n - 1] == 0:
            eigenvalues_temp[n - 1] = complex(A[n - 1][n - 1], 0)

        end = True
        for i in range(n):
            if abs(eigenvalues[i] - eigenvalues_temp[i]) > epsilon:
                end = False

        eigenvalues = np.copy(eigenvalues_temp)
    return eigenvalues


def Arnoldi_iteration(A, b, nimp):
    m = A.shape[0] 

    h = np.zeros((nimp+1, nimp))    
    Q = np.zeros((m, nimp+1))       

    q  = b/np.linalg.norm(b)

    Q[:, 0] = q                     
    for n in range(nimp):
        v = A.dot(q)                
        for j in range(n+1):
            h[j, n] = np.dot(Q[:,j], v)      
            v = v - h[j,n]*Q[:,j]   

        print ("V:", v)
        print ("NORM", np.linalg.norm(v))
        h[n+1, n] = np.linalg.norm(v)
        q = v / h[n+1, n]
        Q[:, n+1] = q

    print ("Q:", Q)
    print ("H:", h)
    return Q, h

def Arnoldi_method(A, eps, m):
    n = A.shape[0]
    b = np.zeros((n))
    b[0] = 0.78289
    b[1] = 0.62216

    ans = Arnoldi_iteration(A, b, m)

    return QR_method(ans[1][:m, ::], eps)

    
def main():
    np.set_printoptions(precision=3)
    file_name = input("Enter file name:")
    while not os.path.isfile(file_name):
        print("Can\'t is file.")
        file_name = input("Enter file name:")
    file = open(file_name, 'r', encoding = 'utf8')
    number_eigenvalues = int(input("Enter number of eigenvalues:"))
    array = []
    epsilon = 0.001
    for line in file:
        str_array = line.split()
        arr = []
        m = len(str_array)
        if m == 1:
            epsilon = float(str_array[0])
        else:
            for i in range(m):
                arr.append(float(str_array[i]))
            array.append(arr)

    A = np.array(array, float)
    print("input mat:", A)
    
    eigenvalues = Arnoldi_method(A, epsilon, number_eigenvalues)
    
    print(eigenvalues)
    print('\n')
    
    print('\n', np.linalg.eig(A))
    

if __name__ == "__main__":
    main()
