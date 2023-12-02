# eigenvalue-calculator
calculator
Include Necessary Libraries: Include the necessary libraries in your program. You will need the standard input/output library (stdio.h), the math library (math.h), and if you want to use dynamic memory allocation, the standard library (stdlib.h).
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

Define Matrix Size: Define the size of the matrix. For simplicity, let’s assume we’re working with a n x n matrix.
we take the inpur from the user about the value of n where n>10.

Input Matrix: Create a function to input the elements of the matrix from the user.

we use Power Iteration method to find the eigenvalues of a matrx.
The power iteration method is an algorithm to find an approximation of the dominant eigenvalue (the one with the largest absolute value) of a matrix. Here’s a basic outline of the process:
Initialize a vector: Start with a non-zero vector b0 with n elements . This can be a random vector or simply a vector of ones.
where A is the matrix.
Iterate: For each iteration k, do the following:

Calculate the matrix-vector product yk = A * bk.
Normalize this to get the next vector bk+1 = yk / ||yk||.
Calculate the Rayleigh quotient λk = bk+1' * A * bk+1.
Check for convergence: If λk is not changing significantly with each iteration, you’ve found the dominant eigenvalue of the matrix, and bk is its corresponding eigenvector.
we limit the maximum iterations to 1000 to save on memory as we do not seek that much precision.
