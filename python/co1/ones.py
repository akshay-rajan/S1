# Read the list of integers
n = int(input("Enter the number of integers: "))
li = [int(input("Integer: ")) for i in range(n)]

# Change the list to replace all numbers greater than 100 with 1
li = [integer if integer <= 100 else 1 for integer in li]
print(li)