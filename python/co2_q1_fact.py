def factorial(n):
	if n == 0:
		return 1
	if n < 0:
		return "Invalid"
	fact = 1
	for i in range(1, n + 1):
		fact *= i
	return fact



n = int(input("Enter a number: "))
print("Factorial: ", factorial(n))

