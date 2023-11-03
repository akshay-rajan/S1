vowels = ['a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U']

# Read a word from the user
word = input("Enter a word: ").split()[0]

# Extract the vowels
vowInWord = [letter for letter in word if letter in vowels]
print("Vowels in the entered word: ", vowInWord)
