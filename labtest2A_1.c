#include <stdio.h>

int main() {
    int row, col;
    int arr[50][50];
    scanf("%d %d", &row, &col);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < row; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < col; j++) {
                printf("%5d", arr[i][j]);
            }
            printf("\n");
        }
    }
}