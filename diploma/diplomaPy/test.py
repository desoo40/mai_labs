import numpy as np
from pandas import read_csv as read

path = "new.csv"
rows = 10000000
data = read(path, delimiter=",", nrows=rows, usecols=[0,1,2,4,5,7,8,9,11,12])

print(len(data))

X = data.values[:, 0:6]
y = data.values[:, 7]
y=y.astype('int') # не совсем понял, почему https://stackoverflow.com/questions/45346550/valueerror-unknown-label-type-unknown

from sklearn.preprocessing import LabelEncoder

le = LabelEncoder()
X[:, 1] = le.fit_transform(X[:, 1])

# from sklearn.cross_validation import train_test_split as train - changed to model selection
from sklearn.model_selection import train_test_split as train

X_train, X_test, y_train, y_test = train(X, y)

print(len(X_train))
print(len(y_train))
print(len(X_test))
print(len(y_test))

from sklearn.ensemble import RandomForestClassifier
clf = RandomForestClassifier(n_estimators=100, n_jobs=-1)
# from sklearn.tree import DecisionTreeClassifier

# clf = DecisionTreeClassifier()
clf.fit(X_train, y_train)

expected = y_test
predicted = clf.predict(X_test)

# lol = np.c_[expected, predicted]
# np.savetxt('lol.txt', lol, fmt='%d')
# print(expected[0])
# print(lol[0])

from sklearn import metrics

report = metrics.classification_report(expected, predicted)
conf_matrix = metrics.confusion_matrix(expected, predicted)

print(report)
print(conf_matrix)
print(metrics.roc_auc_score(expected, predicted))
# print(clf.score(X_test, y_test)) бесполезна в этой задаче

# import matplotlib.pyplot as plt
# import itertools
# from matplotlib.pylab import rc, plot

# def plot_confusion_matrix(cm, classes,
#                           normalize=False,
#                           title='Confusion matrix',
#                           cmap=plt.cm.Blues):
#     """
#     This function prints and plots the confusion matrix.
#     Normalization can be applied by setting `normalize=True`.
#     """
#     plt.imshow(cm, interpolation='nearest', cmap=cmap)
#     plt.title(title)
#     plt.colorbar()
#     tick_marks = np.arange(len(classes))
#     plt.xticks(tick_marks, classes, rotation=45)
#     plt.yticks(tick_marks, classes)

#     if normalize:
#         cm = cm.astype('float') / cm.sum(axis=1)[:, np.newaxis]
#         print("Normalized confusion matrix")
#     else:
#         print('Confusion matrix, without normalization')

#     print(cm)

#     thresh = cm.max() / 2.
#     for i, j in itertools.product(range(cm.shape[0]), range(cm.shape[1])):
#         plt.text(j, i, cm[i, j],
#                  horizontalalignment="center",
#                  color="white" if cm[i, j] > thresh else "black")

#     plt.tight_layout()
#     plt.ylabel('True label')
#     plt.xlabel('Predicted label')

# font = {'size' : 15}

# plt.rc('font', **font)

# cnf_matrix = metrics.confusion_matrix(expected, predicted)
# plt.figure(figsize=(10, 8))
# plot_confusion_matrix(cnf_matrix, classes=['Non-fraud', 'Fraud'], title='Confusion matrix')
# plt.savefig("conf_matrix.png")