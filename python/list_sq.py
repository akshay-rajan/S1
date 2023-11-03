# Read the list
li = []
n = int(input("Enter the size of the list: "))
for i in range(n):
   li.append(int(input(f"li[{i}]: "))) 

# Generate the squares of all the numbers
sq = [x * x for x in li]
print("Squares: ", sq) 