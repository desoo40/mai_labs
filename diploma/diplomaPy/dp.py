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

    for line in tqdm(train_data):
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

train = open ('train.csv', 'r')
# train_data = csv.reader(train)

train_data = np.loadtxt(train, delimiter=';')

X = train_data[:, 0:6]
y = train_data[:, 7]

from sklearn import metrics
from sklearn.linear_model import LogisticRegression
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.naive_bayes import GaussianNB

# model = LogisticRegression()
# model = DecisionTreeClassifier()
model = GaussianNB()
model.fit(X, y)

print(model)

predict = open ('predict.csv', 'r')
predict_data = np.loadtxt(predict, delimiter=';')

predX = predict_data[:, 0:6]

expected = predict_data[:, 7]
predicted = model.predict(predX)

print(metrics.classification_report(expected, predicted))
print(metrics.confusion_matrix(expected, predicted))

# lines_cnt = sum (1 for row in reader)
# lines_cnt = 10000000
# lines_cnt = 10000

# trans = get_transactions(lines_cnt)