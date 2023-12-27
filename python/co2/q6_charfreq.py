def characterFrequency(string, char):
    count = 0
    for i in range(len(string)):
        if string[i] == char:
            count += 1
    return count

string = input("Enter the string: ")
frequencies = {x: characterFrequency(string, x) for x in string}
print(frequencies)
