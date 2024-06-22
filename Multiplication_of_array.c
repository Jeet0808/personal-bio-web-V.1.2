#include <stdio.h>

int main() {
    int a[3][3] = {
        {1, 1, 1},
        {2, 2, 2},
        {1, 1, 1}
    };
    int b[3][2] = {
        {1, 1},
        {2, 2},
        {1, 1}
    };
    int c[3][2] = {0}; // Initialize result matrix with zeros

    int n = 3; // Number of rows in matrix a
    int p = 3; // Number of columns in matrix b

    if (n != p) {
        printf("Cannot multiply matrices. Rows of matrix a must be equal to columns of matrix b.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            int sum = 0;
            for (int k = 0; k < p; k++) {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }

    printf("Resultant matrix c:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}

