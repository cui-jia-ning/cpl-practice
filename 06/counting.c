#include <stdio.h>
char board[102][102];
int find_square(int i,int j,int r,int c);
int is_square(int i,int j,int k);//k表示对角线长度的一半
int main(void) {
    int r,c;
    scanf("%d %d",&r,&c);

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf(" %c",&board[i][j]);
        }
    }

    int cnt=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j]=='/'&&board[i][j+1]=='\\'){
                cnt+=find_square(i,j,r,c);
            }
        }
    }
    
    printf("%d",cnt);
    return 0;
}

int find_square(int i, int j,int r,int c)
{
    int temp=0;
    for(int k=1;k<100;k++){
        if(i+2*k-1>r-1||j+k>c-1||j-k+1<0){
            break;
        }
        if(is_square(i,j,k)){
            temp++;
        }
        

    }
    return temp;
}

int is_square(int i, int j, int k)
{
    int flag=1;
    for(int s=1;s<k;s++){
        if(board[i+s][j-s]!='/'){
            flag=0;
            break;
        }
        if(board[i+k-1+s][j+k+1-s]!='/'){
            flag=0;
            break;
        }
        if(board[i+s][j+1+s]!='\\'){
            flag=0;
            break;
        }
        if(board[i+s+k-1][j+s-k]!='\\'){
            flag=0;
            break;
        }
    }
    // 底角相邻的最后两格
if (board[i+2*k-1][j+1] != '/')  flag = 0;   // 右下边的最后一格
if (board[i+2*k-1][j]   != '\\') flag = 0;   // 左下边的最后一格

    return flag;
}
