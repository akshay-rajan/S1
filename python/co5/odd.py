# Copy odd lines of a file to another
newfile = open("new.txt", "w")

file1 = open("demo.txt", "r")
file2 = open("new.txt", "a")

count = 0
for line in file1:
    count += 1
    if count % 2 != 0:
        file2.write(line)

