#include <stdio.h>

int main() {
    int a[3][4] = {{1, 2, 3, 4}, {1, 1, 1, 1}, {0, 0, 0, 0}};
    int b[4][3];

    printf("Original matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // Calculate the transpose
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            b[i][j] = a[j][i];
        }
    }

    printf("\nTransposed matrix:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}
