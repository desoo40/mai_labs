from pandas import read_csv as read
import pandas as pd
import random
import numpy as np
import seaborn as sns; sns.set(color_codes=True)
import matplotlib.pyplot as plt
from sklearn import metrics
from sklearn.metrics import precision_recall_curve
from sklearn.metrics import f1_score
from sklearn.metrics import auc
from sklearn.metrics import average_precision_score

def pltPRcurve(expected, predicted, preds, name):
    precision, recall, thresholds = precision_recall_curve(expected, preds)
    # calculate F1 score
    f1 = f1_score(expected, predicted)
    # calculate precision-recall AUC
    au = auc(recall, precision)
    # calculate average precision score
    ap = average_precision_score(expected, preds)
    #s = 'f1=%.3f auc=%.3f ap=%.3f' % (f1, au, ap)
    #print(s)
    # plot the precision-recall curve for the model
    plt.title("Precision-recall curve")

    plt.plot(recall, precision, 'b', label=f'PR {name}' )
    plt.legend(loc = 'lower left')

    plt.xlabel('Recall')
    plt.ylabel('Precision')
    plt.savefig(f"PR {name}", dpi=300)

def pltROCcurve(expected, predicted, preds, name):
    fpr, tpr, thershold = metrics.roc_curve(expected, preds)
    roc_auc = metrics.auc(fpr, tpr)

    plt.title("ROC")
    plt.plot(fpr, tpr, 'b', label=f'AUC {name}' + '= %0.3f' % roc_auc, color=(random.uniform(0,1), random.uniform(0, 1), random.uniform(0, 1)))
    plt.legend(loc = 'lower right')
    plt.plot([0, 1], [0, 1], 'r--')
    plt.xlabel('FP Rate')
    plt.ylabel('TP Rate')
    plt.savefig(f"ROC {name}", dpi=300)
    plt.close()
