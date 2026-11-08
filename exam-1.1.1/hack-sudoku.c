#include <stdio.h>
int board[9][9];
int main(void) {
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%d",&board[i][j]);
        }
    }
    for(int i=0;i<9;i++){
        int num[9]={0};
        for(int j=0;j<9;j++){
            num[board[i][j]-1]+=1;
        }
        for(int k=0;k<9;k++){
            if(num[k]>1){
                goto NO;
            }
        }
    }
    for(int j=0;j<9;j++){
        int num[9]={0};
        for(int i=0;i<9;i++){
            num[board[i][j]-1]+=1;
        }
        for(int k=0;k<9;k++){
            if(num[k]>1){
                goto NO;
            }
        }
    }
    for(int i=0;i<9;i+=3){
        for(int j=0;j<9;j+=3){
            int num[9]={0};
            for(int s=0;s<3;s++){
                for(int k=0;k<3;k++){
                    num[board[i+s][j+k]-1]++;
                }
            }
            for(int k=0;k<9;k++){
                if(num[k]>1){
                    goto NO;
                }
            }
        }
    }
    printf("YES");
    return 0;
  NO : printf("NO");
    return 0;
}