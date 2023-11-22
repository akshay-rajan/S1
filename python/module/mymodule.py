def pyramid(n):
	for i in range(1, n + 1):
		for j in range(1, i + 1):
			print(i * j," ", end="")
		print("")

def pattern(n):
	for i in range(n - 1):
		if i <= n // 2 - 1:
			for j in range(i + 1):
				print("* ", end="")
			print("")
		else:
			for j in range(i + 1, n):
				print("* ", end="")
			print("")
