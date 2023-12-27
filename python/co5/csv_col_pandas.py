import pandas as pd

columns = ["Maxpulse"]

file = pd.read_csv("data.csv", usecols=columns)
print(file)