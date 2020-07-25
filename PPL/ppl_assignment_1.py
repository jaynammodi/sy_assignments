
# PPL Lab Assignment 1, PG43 Jaynam Modi, G3


# 1.Implement program in python for collecting 4 subject marks from user and find out average it and display result in grades.
#	<40: failed
#	>40 and <50 : C grade
#	50 and <60 :B grade
#	>66 and <70 :A grade
#	>70 and < 90: A+grade
#	>90 : Excellent grade


def calcGrade():
	marks = [0,0,0,0]
	average = 0.0
	grade = None
	
	print(" > Please Enter the Marks for : ")
	
	for a in range(4):
		marks[a] = float(input("\t> Subject {} : ".format(a+1)))
		average = average + marks[a]
		
	average = average/4
	
	if average > 90.0:
		grade = "Excellent"
	elif average > 70.0:
		grade = "A+"
	elif average > 60.0:
		grade = "A"
	elif average > 50.0:
		grade = "B"
	elif average > 40.0:
		grade = "C"
	else:
		grade = "Failed"
		
	print(" > Average : {}".format(average))
		
	print(" > Grade : {}".format(grade))
	
calcGrade()


# 2.Display the table of 5 by using for and while loop in Python.

x = 5

for i in range(1,11):
	print(" > {} × {} = {}".format(x, i, x*i))
	
j = 11
	
while j <= 20:
	print(" > {} × {} = {}".format(x, j, x*j))
	j += 1