import pandas as pd
import seaborn as s
import matplotlib.pyplot as plt

d=pd.read_csv(r"C:\Users\Vamshi R A\OneDrive\Desktop\Datasets\housingG.csv")

cm=d.corr()
plt.figure(figsize=(10,5))
s.heatmap(cm,annot=True,fmt='.2f',linewidth=0.5)
plt.show()

plt.figure(figsize=(10,5))
s.pairplot(d)
plt.show()