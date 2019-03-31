import os
from tqdm import tqdm
import numpy as np
from TransClass import Trans
from prettytable import PrettyTable
import csv

def print_trans(translist):
    x = PrettyTable(["Step", "Type", "Amount", "NOrig", "OBOrig", "NBOrig", "NDest", "OBDest", "NBDest", "IF", "IFF"])

    for tr in translist:
        x.add_row([tr.step, tr.ttype, tr.amount, tr.nameOrig, tr.oldbalanceOrg, tr.newbalanceOrig, tr.nameDest, tr.oldbalanceDest, tr.newbalanceDest, tr.isFraud, tr.isFlaggedFraud])
    
    txt = x.get_string()
    f1 = open('ek.txt', 'w+')
    f1.write(txt)
    # print(x)

def get_transactions(cnt):
    i = 0
    translist = []

    for line in tqdm(reader):
        if i == 0:
            i += 1
            continue
        if i > cnt:
            break

        i += 1

        translist.append(Trans(step = line[0],
                               ttype = line[1],
                               amount = line[2],
                               nameOrig = line[3],
                               oldbalanceOrg = line[4],
                               newbalanceOrig = line[5],
                               nameDest = line[6],
                               oldbalanceDest = line[7],
                               newbalanceDest = line[8],
                               isFraud = line[9],
                               isFlaggedFraud = line[10]))
    return translist

data = open ('data.csv', 'r')
reader = csv.reader(data)

# lines_cnt = sum (1 for row in reader)
# lines_cnt = 10000000
lines_cnt = 10000

trans = get_transactions(lines_cnt)