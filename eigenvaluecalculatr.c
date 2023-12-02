#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to perform matrix-vector multiplication
void matrixVectorMultiply(double matrix[][10], double vector[], double result[], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = 0;
        for (int j = 0; j < size; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
}

// Function to normalize a vector i.e vector magnitude = 1
void normalizeVector(double vector[], int size) {
    double norm = 0;
    for (int i = 0; i < size; i++) {
        norm += vector[i] * vector[i];
    }
    norm = sqrt(norm);

    for (int i = 0; i < size; i++) {
        vector[i] /= norm;
    }
}

// Function to compute the eigenvalues and eigenvectors using power iteration
void powerIteration(double matrix[][10], int size) {
    double eigenvector[10];
    double tempVector[10];
    double eigenvalue, prevEigenvalue = 0;

    // Initialize eigenvector to a random vector
    for (int i = 0; i < size; i++) {
        eigenvector[i] = (double)rand() / RAND_MAX;
    }
    // max iterator is defined to prevent forever loops and very long computation
    int maxIter = 1000;
    double epsilon = 1e-6;

    // Iterate until convergence or maximum iterations
    for (int iter = 0; iter < maxIter; iter++) {
        matrixVectorMultiply(matrix, eigenvector, tempVector, size);

        // Find the eigenvalue
        eigenvalue = 0;
        for (int i = 0; i < size; i++) {
            eigenvalue += tempVector[i] * eigenvector[i];
        }

        // Check for convergence
        if (fabs(eigenvalue - prevEigenvalue) < epsilon) {
            break;
        }

        // Normalize the eigenvector
        normalizeVector(tempVector, size);

        // Update eigenvector and eigenvalue
        for (int i = 0; i < size; i++) {
            eigenvector[i] = tempVector[i];
        }
        prevEigenvalue = eigenvalue;
    }

    // Print the results
    printf("Eigenvalue: %lf\n", eigenvalue);
    printf("Eigenvector: ");
    for (int i = 0; i < size; i++) {
        printf("%lf ", eigenvector[i]);
    }
    printf("\n");
}

int main() {
    int size;

    // Get the size of the matrix from the user
    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);

    // Declare the matrix with a fixed size
    double matrix[10][10];

    // Get the matrix elements from the user or generate random matrices for testing
    printf("Enter the elements of the matrix (row-wise):\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    // Call the powerIteration function to compute eigenvalues and eigenvectors
    powerIteration(matrix, size);

    return 0;
}
