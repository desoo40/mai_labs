import math
import numpy as np
import random

def find_common_lambd(l1, l2):
    tmp1 = (1 - math.exp(-l1)) * (1 - math.exp(-l2))
    tmp2 = 1 - tmp1
    tmp3 = l1*math.exp(-l1) / (1 - math.exp(-l1)) + l2*math.exp(-l2) / (1 - math.exp(-l2))

    return tmp1 / tmp2 * tmp3

def find_proba(l1, l2, m1, m2):
    M = np.array([[-(l1 + l2), m1, m2, 0],
              [l1, -(l2 + m1), 0,  m2],
              [1, 1, 1, 1],
              [l2, 0, -(l1 + m2), m1]])

    v = np.array([0,0,1,0])
    return np.linalg.solve(M,v)

def print_block(i, l1, l2, m1, m2):
    print("**********************")
    print(f"B{i}")
    print()
    p = find_proba(l1, l2, m1, m2)
    print(f"l1 = {l1}")
    print(f"l2 = {l2}")
    print(f"m1 = {m1}")
    print(f"m2 = {m2}")
    print(f"p0 = {p[0]}")
    print(f"p1 = {p[1]}")
    print(f"p2 = {p[2]}")
    print(f"p3 = {p[3]}")
    Kr = p[0] + p[1] + p[2]
    KG.append(Kr)
    print(f"Kr{i} = {Kr}")
    w = l2 * p[1] + l1 * p[2]
    print(f"Tp{i} = {Kr / w}")
    TP.append(Kr / w)
    Po = Kr - p[1] * l2 / (l2 + m1) - p[2] * l1 / (l1 + m2)
    PO.append(Po)
    print(f"Po{i} = {Po}")
    print("**********************")


lmbds = np.loadtxt("lm.txt")
mus = np.loadtxt("mu.txt")

l_b1 = find_common_lambd(lmbds[0], lmbds[1])
l_b2 = find_common_lambd(l_b1, lmbds[2])
l_b3 = find_common_lambd(l_b2, lmbds[3])
l_b4 = find_common_lambd(l_b3, lmbds[4])

m_b1 = find_common_lambd(mus[0], mus[1])
m_b2 = find_common_lambd(m_b1, mus[2])
m_b3 = find_common_lambd(m_b2, mus[3])
m_b4 = find_common_lambd(m_b3, mus[4])

KG = []
TP = []
PO = []

print_block(1, lmbds[0], lmbds[1], mus[0], mus[1])
print_block(2, l_b1, lmbds[2], m_b1, mus[2])
print_block(3, l_b2, lmbds[3], m_b2, mus[3])
print_block(4, l_b3, lmbds[4], m_b3, mus[4])
print_block(5, l_b4, lmbds[5], m_b4, mus[5])

def calc_KgN(KG):
    s = 0
    for el in KG:
        s += (1 - el) / el

    return 1 / (1 + s)

def calc_KgV(KG, PO):
    s = 0
    s1 = 0

    for i in range(0, len(PO)):
        s += (KG[i] - PO[i]) / PO[i]

    for el in PO:
        s1 += (1 - el) / el

    return (1 + s) / (1 + s1)

def calc_TpN(TP):
    s = 0
    for el in TP:
        s += 1 / el

    return 1 / s

def calc_TpV(KG, PO, TP):
    s = 0
    s1 = 0

    for i in range(0, len(PO)):
        s += (KG[i] - PO[i]) / PO[i]
        s1 += KG[i] / (TP[i] * PO[i])

    return (1 + s) / (1 + s1)

KgN = calc_KgN(KG)
KgV = calc_KgV(KG, PO)
TpN = calc_TpN(TP)
TpV = calc_TpV(KG, PO, TP)

print(f"KgN {KgN}")
print(f"KgV {KgV}")
print(f"TpN {TpN}")
print(f"TpV {TpV}")

Kg = (KgN + KgV) / 2
Tp = (TpN + TpV) / 2

print(f"Kg {Kg}")
print(f"Tp {Tp}")

deltaK = 100 * (KgV - KgN) / (KgV + KgN)
deltaT = 100 * (TpV - TpN) / (TpV + TpN)

print(f"deltaK {deltaK}")
print(f"deltaT {deltaT}")

print(f"Kpe {1 - Kg}")
print(f"Tve {Tp * (1 - Kg) / Kg }")

# print(l_b4)
# print(lmbds)
# print(s)
# print(s[0] + s[1] + s[2] + s[3])
