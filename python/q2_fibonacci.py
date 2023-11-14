def fibonacci(n):
	if n < 1:
		return
	elif n == 1:
		return [0]
	elif n == 2:
		return [0, 1]
	i = 2
	fib = [0, 1, 1]
	while i < n - 1:
		i += 1
		num = fib[i-1] + fib[i - 2]
		fib.append(num)
	return fib

n = int(input("Enter a number: "))
print("Fibonacci: ", fibonacci(n))
	

