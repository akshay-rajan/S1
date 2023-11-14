dict1 = {6 : "india", 4 : "japan", 0 : "korea"}
dict2 = {3 : "china", 1 : "kovalam", 5: "karamana"}

# Unpacking syntax-- **
#print({**dict1, **dict2})

dict1.update(dict2)
print(dict1)

