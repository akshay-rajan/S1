a = int(input("Number 1: "))
b = int(input("Number 2: "))
    
# Repeatedly replacing the larger number by its remainder when divided by the smaller number
while b > 0:
    a, b = b, a % b
    
print(f"GCD :", a)
    