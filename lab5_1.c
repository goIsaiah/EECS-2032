#include <stdio.h>
#include <ctype.h>
 
int main(int argc, char **argv){
    char input[30]; 
    int isNotLower = 1;
    int isNotCon = 1;
    int isNotUpper = 1;
    scanf("%s", input);
 
    for(int i=0; i<30; i++){
        if (input[i] >= 'A' && input[i] <= 'Z'){
            isNotLower=0;
 
        }
 
        if (input[i] >= 'a' && input[i] <= 'z'){
            isNotUpper=0;
 
        }
 
        if (input[i] >= '0' && input[i] <= '9'){
            isNotCon=0;
            break;
        }
 
        if (input[i+1] <= 0) {
            break;
        }
 
        if (input[i] >= input[i+1]){
            printf("Not consecutive\n");
            isNotCon=0;
            break;
        }
 
    }
 
    if (isNotLower == 1 && isNotCon == 1) {
        printf("Consecutive and all small letters\n");
    }
 
    if (isNotCon == 1 && isNotUpper == 1){
        printf("Consecutive and all capital letters\n");
    }
 
    return 0;
}