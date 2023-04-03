#include <stdio.h>
#define abs(a) (a<0)?(-(a)):(a)

int main() {
    int n, max, cur, index;
    int arr[50];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    max = 0;
    for (int i = 0; i < n-1; i++) {
        cur = abs(arr[i] - arr[i+1]);
        if (cur > max) {
            max = cur;
            index = i;
        }
    }

    printf("%d %d %d\n", arr[index], arr[index+1], max);
}