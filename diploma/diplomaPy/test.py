import numpy as np
import random
from pandas import read_csv as read
import pandas as pd
import seaborn as sns; sns.set(color_codes=True)
import matplotlib.pyplot as plt

path = "newFilt.csv"
data = read(path, delimiter=",")

print(data.corr())
# print(data.head())

data.drop('isFlaggedFraud', axis=1, inplace=True)
data.drop('nameOrig', axis=1, inplace=True)
data.drop('nameDest', axis=1, inplace=True)

from sklearn.preprocessing import LabelEncoder

le = LabelEncoder()
data['type'] = le.fit_transform(data['type'])

# data = pd.get_dummies(data)
print(data.head())

# print(data.head())

X = data.loc[:, data.columns != 'isFraud'].values
y = data.loc[:, 'isFraud'].values

y=y.astype('int') # не совсем понял, почему https://stackoverflow.com/questions/45346550/valueerror-unknown-label-type-unknown

# from sklearn import preprocessing
# # normalize the data attributes
# normalized_X = preprocessing.normalize(X)
# # standardize the data attributes
# standardized_X = preprocessing.scale(X)

from sklearn.model_selection import train_test_split as train

X_train, X_test, y_train, y_test = train(X, y, shuffle=False)

from sklearn.ensemble import RandomForestClassifier, GradientBoostingClassifier
from sklearn.naive_bayes import GaussianNB
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn import metrics

models = []
models.append(DecisionTreeClassifier())
models.append(RandomForestClassifier(n_estimators=110, n_jobs=-1))
models.append(GradientBoostingClassifier(max_depth=4))
models.append(KNeighborsClassifier(n_neighbors=20))

for model in models:
    
    model.fit(X_train, y_train)
    expected = y_test
    predicted = model.predict(X_test)
    
    pobas = model.predict_proba(X_test)
    preds = pobas[:, 1]

    
    

    report = metrics.classification_report(expected, predicted)
    conf_matrix = metrics.confusion_matrix(expected, predicted)

    print(type(model).__name__)
    print(report)
    print(conf_matrix)
    print(metrics.roc_auc_score(expected, preds))
    # print(roc_auc)

    # df = pd.DataFrame()
    # df['Exp'] = expected
    # df['pre'] = predicted
    # df.to_csv('ep.csv', index=False)

plt.savefig("roc.png")
