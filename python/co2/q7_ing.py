def modify(string):
    if (string.endswith("ing")):
        return string + "ly"
    return string + "ing"

string = input("Enter the string: ")
print(modify(string))
