import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score
import matplotlib.pyplot as plt

df = pd.read_csv(r"C:\Users\Vamshi R A\OneDrive\Desktop\Datasets\olivetti_faces.csv")
x = df.iloc[:, :-1].values
y = df.iloc[:, -1].values

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=42)

gnb = GaussianNB()
gnb.fit(x_train, y_train)
y_pred = gnb.predict(x_test)

accuracy = accuracy_score(y_test, y_pred)
print(f"Accuracy of naive bayes classifier on olivetti faces Dataset: {accuracy*100:.2f}%")

n = 10

plt.figure(figsize=(60, 10))
for i in range(n):
    ax = plt.subplot(1, n, i + 1)
    ax.imshow(x_test[i].reshape(64, 64), cmap='gray')
    ax.axis('off')

plt.show()