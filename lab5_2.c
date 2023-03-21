#include <stdio.h>

int main(int argc, char **argv){
    int m; //columns
    int n; //rows
    scanf("%d%d", &m, &n);
 
    int matrix[n][m];
 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
 
    for(int i=0; i<n; i++){
        int flag = 1;
        for(int j=0; j<m-1; j++){
            if(matrix[i][j] > matrix[i][j+1]){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            for(int j=0; j<m; j++){
                printf("%5d", matrix[i][j]); 
            }
            printf("\n"); 
        }
    }
    return 0;
}