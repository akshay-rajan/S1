def pyramid(n):
	for i in range(1, n + 1):
		for j in range(1, i + 1):
			print(i * j," ", end="")
		print("")

def pattern(n):
	for i in range(2 * n):
		for j in range(n - i + 2):
			print("*", end="")
		print("")
