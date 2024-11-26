#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(double** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int N, M, k1, k2;
    printf("Enter the number of rows (N): ");
    scanf("%d", &N);
    printf("Enter the number of columns (M): ");
    scanf("%d", &M);

    if (N <= 0 || M <= 0) {
        printf("Matrix dimensions must be positive!\n");
        return 1;
    }

    double** matrix = (double**)malloc(N * sizeof(double*));
    for (int i = 0; i < N; i++) {
        matrix[i] = (double*)malloc(M * sizeof(double));
    }

    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = (double)(rand() % 100) / 10.0;
        }
    }

    printf("Initial matrix:\n");
    printMatrix(matrix, N, M);

    printf("Enter the index k1 (starting row to delete): ");
    scanf("%d", &k1);
    printf("Enter the index k2 (ending row to delete): ");
    scanf("%d", &k2);

    if (k1 < 0 || k2 >= N || k1 > k2) {
        printf("Invalid indices!\n");
        freeMatrix(matrix, N);
        return 1;
    }

    int newRows = N - (k2 - k1 + 1);
    double** newMatrix = (double**)malloc(newRows * sizeof(double*));
    int newIndex = 0;

    for (int i = 0; i < N; i++) {
        if (i < k1 || i > k2) {
            newMatrix[newIndex++] = matrix[i];
        } else {
            free(matrix[i]);
        }
    }

    free(matrix);

    printf("Matrix after deleting rows:\n");
    printMatrix(newMatrix, newRows, M);

    freeMatrix(newMatrix, newRows);

    return 0;
}
