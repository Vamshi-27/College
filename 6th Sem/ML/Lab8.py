import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score
from sklearn import tree

df = pd.read_csv(r"C:\Users\Vamshi R A\OneDrive\Desktop\Datasets\breast_cancer.csv")
x = df.iloc[:, :-1].values
y = df.iloc[:, -1].values

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=42)

clf = DecisionTreeClassifier(random_state=42)
clf.fit(x_train, y_train)

y_pred = clf.predict(x_test)
accuracy = accuracy_score(y_test, y_pred)
print(f"Model accuracy: {accuracy * 100:.2f}%")

new_sample = np.array([x_test[0]])
prediction = clf.predict(new_sample)
prediction_class = "Benign" if prediction == 1 else "Malignant"
print(f"Predicted class for new sample: {prediction_class}")

plt.figure(figsize=(12, 8))
tree.plot_tree(clf, filled=True, feature_names=df.columns[:-1], class_names=["Malignant", "Benign"])
plt.title("Decision Tree - Breast Cancer Dataset")
plt.show()