# Find the area of square, rectangle and triangle using lambda functions

choice = int(input("Enter 1 for square, 2 for rectangle and 3 for triangle"))
if choice == 1:
	area = lambda x: x * x
	print("Area: ", area(int(input("Side: "))))
elif choice == 2:
	area = lambda x, y: x * y
	print("Area: ", area(int(input("Length: ")), int(input("Breadth: "))))
elif choice == 3:
	area = lambda b, h: (1/2) * b * h
	print("Area: ", area(int(input("Base: ")), int(input("Height: "))))
else:
	print("Invalid Input!")

