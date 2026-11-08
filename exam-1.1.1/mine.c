#include <stdio.h>
char board[105][105]={0};
int cboard[105][105]={0};

int main(void) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf(" %c",&board[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
           if(board[i][j]=='*'){
            cboard[i-1][j-1]++;
            cboard[i-1][j]++;
            cboard[i-1][j+1]++;
            cboard[i][j-1]++;
            cboard[i][j]++;
            cboard[i][j+1]++;
            cboard[i+1][j-1]++;
            cboard[i+1][j]++;
            cboard[i+1][j+1]++;//这里还要用vector吗
           }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(board[i][j]=='*'){
                printf("*");
            }
            else{printf("%d",cboard[i][j]);}
        }
        printf("\n");
    }
    return 0;
}