c1 = ['red', 'blue', 'green']
c2 = ['orange', 'violet', 'green']

colors = [color for color in c1 if color not in c2]
print("Colors in list 1 but not in list 2: ", colors)
