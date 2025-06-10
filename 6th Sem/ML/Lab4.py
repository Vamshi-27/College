import pandas as pd

d = pd.read_csv(r"C:\Users\Vamshi R A\OneDrive\Desktop\Datasets\Data.csv")
a = d.iloc[:, [0, 1, 2, 3, 4, 5]].values
t = d.iloc[:, 6].values

for i in range(len(t)):
    if t[i] == "Yes":
        h = a[i].copy()
        break

for i in range(len(a)):
    if t[i] == "Yes":
        for j in range(len(h)):
            if h[j] != a[i][j]:
                h[j] = "?"

print("Final hypothesis:", h)


'''
Data:
CGPA	Interactiveness	  Practical Knowledge	Communication Skills	Logical Thinking	Interest	Job Offer
>=9	     Yes	               Excellent	           Good	                Fast	           Yes	       Yes
>=9	     Yes	                  Good	               Good	                Fast	           Yes	       Yes
>=8	     No	                      Good	               Good	                Fast	            No	        No
>=9	     Yes	                  Good	               Good	                Slow	           Yes	       Yes

'''