yr = int(input("Enter the final year: "));
current = 2023
if yr <= current:
	print("Invalid")
else:
	# Next leap year is 2024
	print("The leap years are: ")
	for i in range(current + 1, yr, 4):
		print(i)


