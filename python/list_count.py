# Read a word from the user
word = input("Enter a word: ").split()[0]

# Find the number of occurences of each letter in the word
occurences = [word.count(character) for character in word]

# Print the number of occurences of each letter
for i in range(len(word)):
    print(word[i]," : ", occurences[i])
