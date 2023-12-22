# Read the list
li = []
n = int(input("Enter the size of the list: "))
for i in range(n):
   li.append(int(input(f"li[{i}]: "))) 

# Generate the list of positive numbers
pos = [x for x in li if x > 0]
print("Positive numbers: ", pos)