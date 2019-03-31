import os
import numpy as np
from TransClass import Trans
from prettytable import PrettyTable
import csv

def get_strings_from_file(path):
    f = open(path)
    for line in f:
        thestr = line.rstrip('\n')
        yield thestr
    f.close()

def get_transactions(fname, cnt):
    strgen = get_strings_from_file(fname)
    translist = []
    firstline = True

    for i in range(cnt):
        if firstline:
            firstline = False
            continue
        trss = thestr.split(',')
        translist.append(Trans(step = trss[0],
                               ttype = trss[1],
                               amount = trss[2],
                               nameOrig = trss[3],
                               oldbalanceOrg = trss[4],
                               newbalanceOrig = trss[5],
                               nameDest = trss[6],
                               oldbalanceDest = trss[7],
                               newbalanceDest = trss[8],
                               isFraud = trss[9],
                               isFlaggedFraud = trss[10]))
    return translist


cnt = 100;
translist = get_transactions("data.csv", cnt)

x = PrettyTable(["Step", "Type", "Amount", "NameOrig", "OBOrig", "NBOrig", "NameDest", "OBDest", "NBDest", "IsFraud", "isFlaggedFraud"])

for i in range(cnt):
  tr = translist[i]
  x.add_row([tr.step, tr.ttype, tr.amount, tr.nameOrig, tr.oldbalanceOrg, tr.newbalanceOrig, tr.nameDest, tr.oldbalanceDest, tr.newbalanceDest, tr.isFraud, tr.isFlaggedFraud])

print(x)  