# Get a string from an input string where all occurences of first character 
# replaced with '$' except first character

string = input("Enter the string: ")

# Replace every occurence of first character with "$" in a list
string2 = [x if x != string[0] else '$' for x in string]

# Insert the first character at the starting of the list
string2 = [string[0]] + string2[1:]

# Convert the list to a string
print("".join(string2))
