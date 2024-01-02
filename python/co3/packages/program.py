from graphics import circle
from graphics.rectangle import *
from graphics.graphics3d import cuboid
from graphics.graphics3d.sphere import area as sphere_area
from graphics.graphics3d.sphere import perimeter as sphere_perimeter

print(f"""Circle with Radius 5
Area: , {circle.area(5)}
Perimeter: {circle.perimeter(5)}
Rectangle with Length: 6, Breadth: 4
Area: {area(6, 4)}
Perimeter: {perimeter(6, 4)}
Sphere with Radius 4
Area: {sphere_area(4)}
Perimeter: {sphere_perimeter(4)}
Cuboid with Length: 6, Breadth: 4, Height: 3
Area: {cuboid.area(6, 4, 3)}
Perimeter: {cuboid.perimeter(6, 4, 3)}"""
)
