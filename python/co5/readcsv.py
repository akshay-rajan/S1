import csv

with open(input("File: "), "r") as file:
    reader = csv.reader(file)
    for row in reader:
        print(row)
    