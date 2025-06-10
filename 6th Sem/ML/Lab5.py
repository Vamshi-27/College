import numpy as np
import pandas as pd
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score
import warnings
warnings.filterwarnings('ignore')

values = np.random.rand(100)
labels = []
for x in values[:50]:
    if x <= 0.5:
        labels.append("class1")
    else:
        labels.append("class2")

labels += [None] * 50

data = {"Point": [f"x{i+1}" for i in range(100)],"Value": values,"Label": labels}

df = pd.DataFrame(data)
labeled_df = df[df["Label"].notna()]
x_train = labeled_df[["Value"]]
y_train = labeled_df["Label"]

unlabeled_df = df[df["Label"].isna()]
x_test = unlabeled_df[["Value"]]

k_values = [1, 2, 3, 4, 5, 20, 30]
results = {}
accuracies = {}

true_labels = ["class1" if x <= 0.5 else "class2" for x in values[50:]]

for k in k_values:
    knn = KNeighborsClassifier(n_neighbors=k)
    knn.fit(x_train, y_train)
    predictions = knn.predict(x_test)

    results[k] = predictions
    accuracy = accuracy_score(true_labels, predictions) * 100
    accuracies[k] = accuracy

    print(f"Accuracy for k={k}: {accuracy:.2f}%")
    unlabeled_df[f"Label_k{k}"] = predictions