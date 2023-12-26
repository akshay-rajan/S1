# Read two strings
str1 = input("Enter the first string: ")
str2 = input("Enter the second string: ")

# Swap the characters at position 1 and concatenate the strings
newstring = str1[0] + str2[1] + str1[2:] + " " + str2[0] + str1[1] + str2[2:]
print(newstring)