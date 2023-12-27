numbers = []
for i in range(int(input("Enter the size of the list: "))):
    numbers.append(int(input(f"numbers[{i}]: ")))

newlist = [x for x in numbers if x % 2 != 0]
print(newlist)