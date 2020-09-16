
; PPL Lab Assignment 6, PG43 Jaynam Modi, G3

; PRACTICE PROBLEMS

; 1. Write a program that prints ‘Hello World’ to the screen.

(print "Hello World")
(terpri)

; 2. Write a lisp function to perform addition of two numbers.

(princ " > Enter First Number : ")
(setq a (read))
(princ " > Enter Second Number : ")
(setq b (read))
(print(+ a b))
(terpri)

; 3. Write a lisp function to calculate the cube of number.

(princ " > Enter Number to cube : ")
(setq c (read))
(print(* c c c))
(terpri)

; 4. Write a lisp function to which returns maximum of three numbers.

(defun getMax(x y z) (if (and(> x y)(> x z)) x (if (and(> y x)(> y z)) y (if (and(> z x)(> z y)) z 'equal))))

(princ " > Enter First Number : ")
(setq d (read))
(princ " > Enter Second Number : ")
(setq e (read))
(princ " > Enter Third Number : ")
(setq f (read))

(print(getMax d e f ))
(terpri)