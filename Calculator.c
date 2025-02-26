#include <stdio.h>
#include <stdlib.h>

int* matrixMultiply(int rows1, int cols1, int rows2, int cols2, int arr1[][cols1], int arr2[][cols2]) {
    if (cols1 != rows2) return NULL;    // Ensure the matrices have compatible dimensions
    
    int* result = (int*)malloc(rows1 * cols2 * sizeof(int));
    if (result == NULL) return NULL;    // Ensure memory allocation was successful
    
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i * cols2 + j] = 0; // Initialize the result matrix to 0 using 1D indexing
            for (int k = 0; k < cols1; k++) {
                result[i * cols2 + j] += arr1[i][k] * arr2[k][j]; // Perform the matrix multiplication
            }
        }
    }
    return result;
}

int* gaussianElimination(int rows, int cols, int arr[][cols]) {
    // Implement Gaussian elimination here
}

int* matrixInverse(int rows, int cols, int arr[][cols]) {
    // Implement matrix inversion here
}

int* matrixTranspose(int rows, int cols, int arr[][cols]) {
    // Implement matrix transposition here
}

int main(void) {
    int rows1, cols1, rows2, cols2;

    printf("Enter the dimensions of the first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    
    printf("Enter the dimensions of the second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    
    if (cols1 != rows2) {
        printf("The matrices are not compatible for multiplication\n");
        return 1;
    }

    int arr1[rows1][cols1], arr2[rows2][cols2];

    printf("Enter the values for the first matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            printf("\t");
            scanf("%d", &arr1[i][j]);
        }
        printf("\n");
    }

    printf("Enter the values for the second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("\t");
            scanf("%d", &arr2[i][j]);
        }
        printf("\n");
    }

    int *result = matrixMultiply(rows1, cols1, rows2, cols2, arr1, arr2);
    if (result == NULL) {
        printf("Error during matrix multiplication\n");
        return 1;
    }

    printf("Result matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("%5d ", result[i * cols2 + j]);
        }
        printf("\n");
    }

    free(result);

    return 0;
}