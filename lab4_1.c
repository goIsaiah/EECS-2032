#include <stdio.h>
int main()
{
    int num;
    int i;
    int j;
    int final;
    int x;
    int y;

    printf("Enter an integer, followed by two integers: \n");
    scanf("%d %d %d", &num, &i, &j);
    
    x = 1;
    for (int k = 0; k < i; k++) {
        x *= 10;
    }
    y = 1;
    for (int k = 0; k < j - i + 1; k++) {
        y *= 10;
    }
    final = (num / x) % y;

    printf("%d \n", final);
    return 0;
}