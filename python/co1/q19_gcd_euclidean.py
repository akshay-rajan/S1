a = int(input("Number 1: "))
b = int(input("Number 2: "))
    
# Euclidean Algorithm: Repeatedly replacing the second number by its remainder when divided by the first number
while b > 0:
    a, b = b, a % b

# GCD is the last non zero remainder
print(f"GCD :", a)
    