import pandas as pd
import seaborn as s
import numpy as np
import matplotlib.pyplot as plt

d=pd.read_csv(r"C:\Users\Vamshi R A\OneDrive\Desktop\Datasets\housingG.csv")

nf=d.select_dtypes(include=['number']).columns

for i in nf:
    plt.figure(figsize=(6,3))
    s.histplot(d[i],bins=30)
    plt.show()

for i in nf:
    plt.figure(figsize=(6,3))
    s.boxplot(d[i])
    plt.show()

print("Outliers:")
os={}
for j in nf:
    q1=d[j].quantile(0.25)
    q3=d[j].quantile(0.75)
    iqr=q3-q1
    lb=q1-1.5*iqr
    hb=q3+1.5*iqr
    o=d[(d[j]<lb) | (d[j]>hb)]
    os[j]=len(o)
    print(f"{j}:{len(o)}")