
# PPL Lab Assignment 2, PG43 Jaynam Modi, G3

# Write a Python Program to check if a Number is a Strong Number.

def factorial(inp):
	fact = 1
	for x in range(1, inp+1):
		fact = fact * x
	return fact

def isStrong(inp):
	strong_check = 0
	inp = str(inp)
	
	for x in inp:
		strong_check += factorial(int(x))
		
	return int(inp) == strong_check
		
	
n = input(" > Enter Number to check : ")

if isStrong(n):
	print(" > The Number you Entered is a Strong Number.")
else:
	print(" > The Number you Entered is NOT a Strong Number.")
	
# PRACTICE PROBLEMS.

# 1. Python Program to Check Whether a Number is Positive or Negative.

def checkPositivity(n):
	if n == 0:
		print(" > The number is neither Positive nor Negative.")
	elif n > 0:
		print(" > The number is Positive.")
	else:
		print(" > The number is Negative.")
		
# 2. Python Program to Check if a Number is a Palindrome.

def checkPalindrome(n):
	rev = str(n)[::-1]
	return n == rev
	
# 3. Python Program to Check if a Number is a Perfect Number.

def isPerfect(n):
	perfect_check = 0
	for x in range(1, n):
		if n // x == 0:
			perfect_check += x
	return n == perfect_check
	
# 4. Python Program to Check if a Number is a Prime Number.

def isPrime(n):
	flag = 0
	for x in range(2, n):
		if n // x == 0:
			flag += 1
	return flag == 0
	
# 5. Python Program to Find the Sum of the Digits of the Number.

def sumOfDigits(n):
	sum_digits = 0
	for x in str(n):
		sum_digits += int(x)
	return sum_digits
	
# 6. Python Program to Find the Factorial of the Number.

def factorial(inp):
	fact = 1
	for x in range(1, inp+1):
		fact = fact * x
	return fact