#include <stdio.h>
int main() {
    char str[50];
    int x, len, flag;
    scanf("%s", str);
    x = 0;
    while(str[x++]) {
        len = x - 1;
    }

    int i = 0;
    int j = len;

    flag = 1;
    while (i <= len && j >= 0) {
        if (str[i] != str[j]) {
            flag = 0;
            break;
        }
        i++;
        j--;
    }

    if (flag == 1) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}