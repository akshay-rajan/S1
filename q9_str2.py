# Create a string from a given string with first and last characters replaced

string = input("Enter the string: ")
string2 = string[len(string) - 1] + string[1:len(string) - 2] + string[0]

print(string2)