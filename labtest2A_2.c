#include <stdio.h>

int main() {
    int n;
    int arr[50];
    int max;
    int maxIndex;
    int max2;
    int max2Index;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    max = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }

    arr[maxIndex] = 0;
    max2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max2) {
            max2 = arr[i];
            max2Index = i;
        }
    }

    printf("%d   %d\n", max, max2);
}