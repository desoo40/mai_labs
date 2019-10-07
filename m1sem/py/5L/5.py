import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import scipy as sc

import os
import os.path

myfile = "myfile3.txt"
my_f = open(myfile, "w")

path = ''
name = 'kinglear.txt'
finename = os.path.join(path, name)
file = open(finename,"r")

with open(finename,"r") as file:
    for _ in range(5):
        line = next(file)
        print(line)
        my_f.write(line)
        