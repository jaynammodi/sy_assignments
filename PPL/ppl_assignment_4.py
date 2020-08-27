
# PPL Lab Assignment 4, PG43 Jaynam Modi, G3

# Write a Python Program to input a Numpy Array and print it's transpose.

import numpy as np


def printmatrix( arr ):
	for i in range(arr.shape[0]):
		for j in range(arr.shape[1]):
			print("    ", arr[i][j], end = "")
		print("\n")
		
def issymetric( arr ):
	flag = True
	t = arr.transpose()
	for i in range(arr.shape[0]):
		for j in range(arr.shape[1]):
			if arr[i][j] != t[i][j]:
				flag = False
	return flag
	

i, j = (int(a) for a in input(" > Enter dimensions of the Array : ").split(" ") if a != "")
inpar = np.array([int(x) for x in input(" > Enter Elements of {} × {} matrix : ".format(i, j)).split(" ") if x != ""]).reshape((i, j))

print(" > Stored Array : \n")
printmatrix(inpar)

transar = inpar.transpose()

print(" > Transpose of the Array : \n")
printmatrix(transar)

if issymetric(inpar):
	print(" > The given Array is symmetric.")
else:
	print(" > The given Array is NOT symmetric.")
	
	
# PRACTICE PROBLEMS.

# 1. Python Program to Swap the First and Last Value of a List.

def swap(lst):
	lst[0], lst[-1] = lst[-1], lst[0]
	return lst
	
# 2. Python Program to Find the Second Largest Number in a List Using Bubble Sort.

def find2ndLargest(lst):
	for i in range(2):
		for j in range(len(lst)-1):
			if lst[j] > lst[j+1]:
				lst[j], lst[j+1] = lst[j+1], lst[j]
	return lst[-2]
				
# 3. Python Program to create list of Tuples with first element as the number and the Second element as the Square of the Number.

def createSquareList(n):
	return [(x, x * x) for x in range(1, n+1)]
	
# 4. Python Program to put Even & Odd Elements of a list into two seperate lists.

def sortEvenOdd(lst):
	return {"even":[x for x in lst if x // 2 == 0], "odd":[x for x in lst if x // 2 == 1]}

# 5. Python Program to remove Duplicate Items from a list.

def removeDuplicates(lst):
	y = []
	for x in lst:
		if x not in y:
			y.append(x)
	return y
	
# 6. Python Program to calculate average of Numbers is list.

def calcAverage(lst):
	avg = 0
	for x in lst:
		avg += x
	return(avg/len(lst))