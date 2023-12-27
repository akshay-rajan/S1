def pattern(n):
	for i in range(n):
		if i < n // 2:
			for j in range(i + 1):
				print("* ", end="")
		else:
			for j in range(i + 1, n + 1):
				print("* ", end="")
		print("")

pattern(int(input("Enter the height of the pyramid: ")))