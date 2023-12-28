from graphics import circle
from graphics.rectangle import *
from graphics.graphics3d import cuboid
from graphics.graphics3d.sphere import area as sphere_area
from graphics.graphics3d.sphere import perimeter as sphere_perimeter

print("Circle with Radius 5")
print("Area: ", circle.area(5))
print("Perimeter: ", circle.perimeter(5))
print("Rectangle with Length: 6, Breadth: 4")
print("Area: ", area(6, 4))
print("Perimeter: ", perimeter(6, 4))
print("Sphere with Radius 4")
print("Area: ", sphere_area(4))
print("Perimeter: ", sphere_perimeter(4))
print("Cuboid with Length: 6, Breadth: 4, Height: 3")
print("Area: ", cuboid.area(6, 4, 3))
print("Perimeter: ", cuboid.perimeter(6, 4, 3))

