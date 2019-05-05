import numpy as np
from pandas import read_csv as read
import pandas as pd
import seaborn as sns; sns.set(color_codes=True)
import matplotlib.pyplot as plt

path = "new.csv"
rows = 500000
data = read(path, delimiter=",", nrows=rows)

data.drop('isFlaggedFraud', axis=1, inplace=True)
data.drop('nameOrig', axis=1, inplace=True)
data.drop('nameDest', axis=1, inplace=True)

from sklearn.preprocessing import LabelEncoder

le = LabelEncoder()
data['type'] = le.fit_transform(data['type'])

# data = pd.get_dummies(data)

X = data.loc[:, data.columns != 'isFraud'].values
y = data.loc[:, 'isFraud'].values

y=y.astype('int') # не совсем понял, почему https://stackoverflow.com/questions/45346550/valueerror-unknown-label-type-unknown

from sklearn.model_selection import train_test_split as train

X_train, X_test, y_train, y_test = train(X, y, shuffle=False)

from sklearn.ensemble import RandomForestClassifier
from sklearn import metrics

n_ests = []
max_fs = []
rauc_scores = []

maxFF = len(data.columns) - 1
print(maxFF)
n_eSS = 110
for i in range(0, maxFF, 1):
    rfc = RandomForestClassifier(n_estimators=n_eSS, max_features=maxFF, n_jobs=-1)

    rfc.fit(X_train, y_train)
    expected = y_test
    predicted = rfc.predict(X_test)

    report = metrics.classification_report(expected, predicted)
    conf_matrix = metrics.confusion_matrix(expected, predicted)

    rauc_s = metrics.roc_auc_score(expected, predicted)
    # n_ests.append(i)
    max_fs.append(i)
    rauc_scores.append(rauc_s)
    
    print(i)
    print(rauc_s)

df = pd.DataFrame()
# df['n_est'] = n_ests
df['max_f'] = max_fs
df['rauc_score'] = rauc_scores

print(df)


sns.lineplot(x='max_f', y='rauc_score', data=df)
plt.title(f"RAUC n_est={n_eSS}")
plt.savefig(f'max_fs{n_eSS}.png')

# sns.lineplot(x='n_est', y='rauc_score', data=df)
# plt.savefig('n_est100.png')