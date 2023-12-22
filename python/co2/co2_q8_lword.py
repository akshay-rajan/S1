words = input("List of words separated by space: ")
words = words.split()

n = 0
for word in words:
	if len(word) > n:
		n = len(word)

print("Length of the largest word: ", n)




