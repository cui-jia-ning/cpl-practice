#include <stdio.h>
int main(void) {
    int n;
    scanf("%d",&n);
    char board[105][105];
    
    int i=0;
    int j=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf(" %c",&board[i][j]);
            
        }
    }
    int sum=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(board[i][j]!='*'){
                sum=0;
                if(i-1>=0&&j-1>=0&&board[i-1][j-1]=='*')sum++;
                if(j-1>=0&&board[i][j-1]=='*')sum++;
                if(i-1>=0&&board[i-1][j]=='*')sum++;
                if(i-1>=0&&j+1<n&&board[i-1][j+1]=='*')sum++;
                if(j+1>=0&&board[i][j+1]=='*')sum++;
                if(i+1<n&&j+1<n&&board[i+1][j+1]=='*')sum++;
                if(i+1<n&&board[i+1][j]=='*')sum++;
                if(i+1<n&&j-1>=0&&board[i+1][j-1]=='*')sum++;
                printf("%d",sum);
              
            }
            else{printf("*");}
        }
        printf("\n");
    }

    
  
    return 0;
}