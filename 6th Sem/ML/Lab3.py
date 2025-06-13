from sklearn.decomposition import PCA
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df = pd.read_csv(r"C:\Users\Vamshi R A\OneDrive\Desktop\Datasets\iris.csv")
features = df.iloc[:, :-1].values
target = df.iloc[:, -1].values

pca = PCA(n_components=2)
f_pca = pca.fit_transform(features)

pca_df = pd.DataFrame(data=f_pca, columns=["Principal component 1", "Principal component 2"])
pca_df["Target"] = target

plt.figure(figsize=(8, 4))
colors = ['r', 'g', 'b']

for i, label in enumerate(np.unique(target)):
    plt.scatter(
        pca_df[pca_df["Target"] == label]["Principal component 1"],
        pca_df[pca_df["Target"] == label]["Principal component 2"],
        label=label,
        color=colors[i]
    )

plt.title("PCA on Iris dataset")
plt.xlabel("PC 1")
plt.ylabel("PC 2")
plt.legend(title='Species', loc='lower right')
plt.grid()
plt.show()
print('hi')