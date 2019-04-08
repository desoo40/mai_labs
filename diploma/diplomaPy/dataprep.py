import numpy as np
from pandas import read_csv as read

path = "data.csv"
data = read(path, delimiter=",", nrows=1000)

uniq_cl = set()
fraud_cl = set()
merchants = set()
is_new = list()

X = data.values[:, :]

for trans in X:
    sender = trans[3]
    receiver = trans[6]
    is_fraud = trans[9]

    is_new_app = 0
    is_merchant_app = 0
    is_fraud_early_app = 0
    ## поиск уникальных
    if  sender in uniq_cl or receiver in uniq_cl:
        is_new_app = 1
    else:
        uniq_cl.add(trans[3])
        uniq_cl.add(trans[6])

    ## магазины

    if receiver.contains('M'):
        is_merchant_app = 1
    
    if is_fraud == 1:
        fraud_cl.add(sender)
        fraud_cl.add(receiver)
    
    is_new.append(is_new_app)
    merchants.append(is_merchant_app)
    
    

hours = data.values[:, 0]

hours %= 24
data['hour'] = hours
data['newClient'] = is_new


data.to_csv("new.csv", sep=",", index=False)

print(sum(p == 1 for p in is_new))