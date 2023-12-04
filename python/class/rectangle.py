# Class is a constructor for creating objects
# Functions are called Methods, and Variables are called Properties
# Instances of a class are known as Objects

class Rectangle:
	# The __init__ function is always executed on initiation of the class: Constructor
	def __init__(self, length, breadth):
		self.length = length
		self.breadth = breadth

	# Methods
	def area(self):
		return self.length * self.breadth

	def perimeter(self):
		return 2 * (self.length + self.breadth)


# Objects
l1, b1 = int(input("Length of r1: ")), int(input("Breadth of r1: "))
l2, b2 = int(input("Length of r2: ")), int(input("Breadth of r2: "))
r1 = Rectangle(l1, b1)
r2 = Rectangle(l2, b2)


if r1.area() < r2.area():
	print(f"Area of r2 = {r2.area()} is greater than Area of r1, {r1.area()}")
else:
	print(f"Area of r1 ({r1.area()}) is greater than Area of r2 ({r2.area()})")

