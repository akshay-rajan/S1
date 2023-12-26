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
