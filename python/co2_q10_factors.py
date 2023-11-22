n = int(input("Enter the number: "))

factors = [x for x in range(1, n + 1) if n % x == 0]

print(factors)


