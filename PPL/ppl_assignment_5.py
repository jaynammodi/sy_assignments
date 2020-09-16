
# PPL Lab Assignment 5, PG43 Jaynam Modi, G3

# Write a Python Program to input a List and Remove Duplicate 

lst = []

for x in input(" > Enter List : ").split(" "):
	if x != "" and int(x) not in lst:
		lst.append(int(x))
		
print(lst)

	
# PRACTICE PROBLEMS.

# 1. Python program to calculate Average of numbers in given list.

def average(lst):
	avg = 0.0
	for x in lst:
		avg += x
	avg = avg/len(lst)
	return avg
	
# 2. Python program to get largest element in list.

def getLargest(lst):
	lrgst = lst[0]
	for x in lst:
		if x > lrgst:
			lrgst = x
	return lrgst
				
# 3. Python program to check if list is empty.

def checkEmpty(lst):
	return lst == []
	
# 4. Python program that takes two lists and returns True if they have at least one common member.

def commonMem(lst1, lst2):
	flag = False
	for x in lst1:
		if x in lst2:
			flag = True
	return flag
	
# 5. Python program to print the numbers of a specified list after removing even numbers from it.

def removeEven(lst):
	newlst = []
	for x in lst:
		if not x%2 == 0:
			newlst.append(x)
	return newlst
	
# 6. Python program to get the difference between the two lists.

def getDifference(lst1, lst2):
	diff = []
	for x in lst1:
		if x not in lst2:
			diff.append(x)
	for y in lst2:
		if y not in lst1:
			diff.append(y)
	return diff