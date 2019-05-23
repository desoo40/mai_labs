#!/usr/bin/env python
# coding: utf-8



import numpy as np
import pandas as pd
import seaborn as sns; sns.set(color_codes=True)
import matplotlib.pyplot as plt
from pandas import read_csv as read

path = "data.csv"
data = read(path, delimiter=",")

print(((data.type == 'TRANSFER') & (data.isFraud == 1)).sum())
print(((data.type == 'CASH_IN') & (data.isFraud == 1)).sum())
print(((data.type == 'CASH_OUT') & (data.isFraud == 1)).sum())
print(((data.type == 'PAYMENT') & (data.isFraud == 1)).sum())
print(((data.type == 'DEBIT') & (data.isFraud == 1)).sum())







