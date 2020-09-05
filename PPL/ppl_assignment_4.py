
# PPL Lab Assignment 4, PG43 Jaynam Modi, G3

# Write a Python Program to input a Numpy Array and print it's transpose and find out whether it is Symmetric or not.

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

# 1. Python program to Add two matrices.

def addMatrix(x, y):
	sumMatrix = x + y
	return sumMatrix
	
# 2. Python program to multiply two matrices.

def productMatrix(x, y):
	return numpy.matmul(x, y)
				
# 3. Python program to find row-wise maximum element of matrix.

def maxElementInRow(arr):
	for x in range(arr.shape[0]):
		m = arr[x][0]
		for y in range(arr.shape[1]):
			if arr[x][y] > m:
				m = arr[x][y]
		print(" > Greatest element in Row {} is : {}".format(x+1, m))
		