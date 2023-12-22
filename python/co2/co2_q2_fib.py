def fibonacci(n):
	i = 1
	a, b, c = 0, 1, 1
	while i <= n:
		if i == 1:
			print(a)
		elif i == 2:
			print(b)
		else:
			print(c)
			a, b = b, c
			c = a + b
		i += 1

fibonacci(int(input("Enter a number: ")))
	

