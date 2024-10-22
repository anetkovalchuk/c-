#include <stdio.h>

int main() {
    int n, m;

    printf("Enter the number of rows (n): ");
    scanf("%d", &n);
    printf("Enter the number of columns (m): ");
    scanf("%d", &m);

    int matrix[n][m];
    
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int min = matrix[0][0], max = matrix[0][0];
    int min_col = 0, max_col = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                min_col = j;
            }
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                max_col = j;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int temp = matrix[i][min_col];
        matrix[i][min_col] = matrix[i][max_col];
        matrix[i][max_col] = temp;
    }
    
    printf("Matrix after swapping the columns:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
