# Create a string from a given string with first and last characters replaced

string = input("Enter the string: ")
string2 = string[-1] + string[1:-1] + string[0]

print(string2)
