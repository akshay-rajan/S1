# Private Attributes are variables that are intended to be accessed only within the class
# Private Attributes are indicated by single/double leading underscores

class Rectangle:
    def __init__(self, length, width):
        self.__length = length
        self.__width = width

    def area(self):
        return self.__length * self.__width
    
    # Operator Overloading: Giving extended meaning for an operator
    
    def __lt__(self, other):
        return self.area() < other.area()


r1 = Rectangle(4, 10)
r2 = Rectangle(5, 6)
print("Area of r1: ", r1.area())
print("Area of r2: ", r2.area())

if r1 < r2:
    print("r1 < r2")
else:
    print("r2 < r1")
