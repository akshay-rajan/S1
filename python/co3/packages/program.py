from graphics import circle
from graphics.rectangle import *
from graphics.graphics3d import cuboid
from graphics.graphics3d.sphere import area as sphere_area
from graphics.graphics3d.sphere import perimeter as sphere_perimeter

print("Area of the circle: ", circle.area(int(input("Enter the radius of the circle: "))))
print("Perimeter of the circle: ", circle.perimeter(int(input("Enter the radius of the circle: "))))
print("Area of the rectangle: ", area(int(input("Length: ")), int(input("Breadth: "))))
print("Perimeter of the rectangle: ", perimeter(int(input("Length: ")), int(input("Breadth: "))))
print("Area of the sphere: ", sphere_area(int(input("Enter the radius of the sphere: "))))
print("Perimeter of the sphere: ", sphere_perimeter(int(input("Enter the radius of the sphere: "))))
print("Area of the cuboid: ", cuboid.area(int(input("Length: ")), int(input("Breadth: ")), int(input("Height: "))))
print("Perimeter of the rectangle: ", cuboid.perimeter(int(input("Length: ")), int(input("Breadth: ")), int(input("Height: "))))

