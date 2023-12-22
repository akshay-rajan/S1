# Read the size and elements of the lists
l1, l2 = [], []
n1 = int(input("Enter the size of the first list: "))
for i in range(n1):
	l1.append(input(f"l1[{i}]: "))
n2 = int(input("Enter the size of the second list: "))
for i in range(n2):
	l2.append(input(f"l2[{i}]: "))

# Comparisons
if l1 == l2:
	print("The lists are equal and are of the same length!")
else:
	print("The lists are not equal!")
	if len(l1) == len(l2):
		print("The lists are of the same length!")
	else:
		print("The lists are of different length!")

common = []
for i in range(len(l1)):
	if l1[i] in l2:
		common.append(l1[i])
if l1[i]:
	print("The values occuring on both of the lists are: ", common)
else:
	print("The lists have no elements in common!")
	