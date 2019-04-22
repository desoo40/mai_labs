import numpy as np
import pandas as pd
import seaborn as sns; sns.set(color_codes=True)
import matplotlib.pyplot as plt
from pandas import read_csv as read

path = "data.csv"
data = read(path, delimiter=",", usecols=['amount', 'isFraud'])

X = data.values

sum_no_fraud = 0
sum_fraud = 0

cnt_no_fraud = 0
cnt_fraud = 0

fr = []
n_fr = []

for x in X:
    if x[1] == 1:
        cnt_fraud += 1
        sum_fraud += x[0]
        fr.append(x[0])
    else:
        cnt_no_fraud += 1
        sum_no_fraud += x[0]
        n_fr.append(x[0])

fr_df = pd.DataFrame(fr, columns = ['Fraud'])
n_fr_df = pd.DataFrame(n_fr, columns = ['No fraud'])

import plotly
import plotly.plotly as py
import plotly.graph_objs as go

import numpy as np
plotly.tools.set_credentials_file(username='desoo', api_key='i3YJOw7BxhGZlky35QNk')
# x = fr_df
# data = [go.Histogram(x=x['Fraud'])]

# py.plot(data, filename='basic histogram')

# x = n_fr_df
# data = [go.Histogram(x=x['No fraud'])]

# py.plot(data, filename='basic histogram')


print("Avg no fraud: ", sum_no_fraud / cnt_no_fraud)
print("Avg fraud: ", sum_fraud / cnt_fraud)