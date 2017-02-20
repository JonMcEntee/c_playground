# Chapter 3 Exercises
Completed exercises from Chapter 3 of 'Accelerated C++' by Andrew Koenig and Barbara E. Moo.

# 3-2
Write a program to compute and print the quartiles (that is, the quarter of the numbers with the largest values, the next highest quarter, and so on) of a set of integers.

# 3-3
Write a program to count how many times each distinct word appears in its input.

# 3-4
Write a program to report the length of the longest and shortest string in its input.

# 3-5
Write a program that will keep track of grades for several students at once. The program could keep two vectors in sync: The first should hold the student's names, and the second the final grades that can be computed as input is read. For now, you should assume a fixed number of homework grades. We'll see in §4.1.3/56 how to handle a variable number of grades intermixed with student names.

# 3-6
The average-grade computation in §3.1/36 might divide by zero if the student didn't enter any grades. Division by zero is undefined in C++, which means that the implementation is permitted to do anything it likes. What does your C++ implementation do in this case? Rewrite the program so that its behavior does not depend on how the implementation treats division by zero