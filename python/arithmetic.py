n = int(input("Enter 1 to add, 2 to subtract, 3 to multiply, 4 to divide: "))
a = int(input("Number 1: "))
b = int(input("Number 2: "))

if n == 1:
	print(a + b)
elif n == 2:
	print(a - b)
elif n == 3:
	print(a * b)
elif n == 4:
	print(a / b)
else:
	print("Invalid input!")

