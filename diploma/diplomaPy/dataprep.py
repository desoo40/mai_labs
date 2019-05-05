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

last_trans_sender = list()
last_trans_receiver = list()
is_zero_on_balance = list()

last_trans = dict()


X = data.values

for trans in X:
    step = trans[0]
    sender = trans[3]
    receiver = trans[6]
    is_fraud = trans[9]
    new_bal_sender = float(trans[5])

    is_new_sender_app = 0
    is_new_receiver_app = 0
    is_merchant_app = 0
    is_fraud_early_app = 0
    last_trans_sender_app = 0
    last_trans_receiver_app = 0
    is_zero_on_balance_app = 0

    ## поиск уникальных
    
    if sender not in senders:
        is_new_sender_app = 1
        senders.add(sender)
        last_trans[sender] = step

    if receiver not in receivers:
        is_new_receiver_app = 1
        receivers.add(receiver)
        last_trans[receiver] = step

    last_trans_sender_app = step - last_trans[sender]
    last_trans_receiver_app = step - last_trans[receiver]
    ## магазины

    if 'M' in receiver:
        is_merchant_app = 1

    ## frauds

    if sender in frauds or receiver in frauds:
        is_fraud_early_app = 1

    if is_fraud == 1:
        frauds.add(sender)
        frauds.add(receiver)

    if new_bal_sender == 0:
        is_zero_on_balance_app = 1

    is_zero_on_balance.append(is_zero_on_balance_app)
    last_trans_sender.append(last_trans_sender_app)
    last_trans_receiver.append(last_trans_receiver_app)
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
data['LTS'] = last_trans_sender
data['LTR'] = last_trans_receiver
data['IZoB'] = is_zero_on_balance


data.to_csv("new.csv", index=False)