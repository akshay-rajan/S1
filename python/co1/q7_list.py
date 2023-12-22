l1 = [4,9,8,2,6]
l2 = [3,9,7,2,1]

if len(l1)==len(l2):
	print("Lists are of same length")
else :
	print("Lists are not of same length")

if sum(l1)==sum(l2):
	print("Lists have the same sum: ", sum(l1))
else :
	print("Lists does not have the same sum")

common = [num for num in l1 if num in l2]

if len(common) > 0:
	print("Lists have common elements: ",common)
else :
	print("Lists have no common elements")






