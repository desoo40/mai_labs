import numpy as np
from pandas import read_csv as read

path = "data.csv"
data = read(path, delimiter=",", nrows=2000000)

senders = set()
receivers = set()
frauds = set()
merchants = set()

is_new_sender = list()
is_new_receiver = list()
merhants_list = list()
frauds_early = list()

X = data.values

for trans in X:
    sender = trans[3]
    receiver = trans[6]
    is_fraud = trans[9]

    is_new_sender_app = 0
    is_new_receiver_app = 0
    is_merchant_app = 0
    is_fraud_early_app = 0

    ## поиск уникальных
    
    if sender not in senders:
        is_new_sender_app = 1
        senders.add(sender)

    if receiver not in receivers:
        is_new_receiver_app = 1
        receivers.add(receiver)

    ## магазины

    if 'M' in receiver:
        is_merchant_app = 1

    ## frauds

    if sender in frauds or receiver in frauds:
        is_fraud_early_app = 1

    if is_fraud == 1:
        frauds.add(sender)
        frauds.add(receiver)

    
    
    is_new_sender.append(is_new_sender_app)
    is_new_receiver.append(is_new_receiver_app)
    merhants_list.append(is_merchant_app)
    frauds_early.append(is_fraud_early_app) 
    

hours = data.values[:, 0]

hours %= 24
data['hour'] = hours
data['newSender'] = is_new_sender
data['newReceiver'] = is_new_receiver
data['merchant'] = merhants_list
data['fraudsEarly'] = frauds_early


data.to_csv("new.csv", index=False)

print(sum(p == 1 for p in frauds_early))