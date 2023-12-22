n1 = int(input("Number 1: "))
n2 = int(input("Number 2: "))
n3 = int(input("Number 3: "))

if n1 > n2:
	if n1 > n3:
		print("Number 1 is the largest")
	else:
		print("Number 3 is the largest")
else:
	if n2 > n3:
		print("Number 2 is the largest")
	else:
		print("Number 3 is the largest")


