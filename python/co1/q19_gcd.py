a = int(input("Number 1: "))
b = int(input("Number 2: "))

# Make sure a is smaller than b, swap otherwise
if a > b:
    a, b = b, a

# Find the largest number that divides both a and b
gcd = a
while gcd > 0:
    if a % gcd == b % gcd == 0:
        break
    gcd -= 1
print(f"GCD({a}, {b}) :", gcd)