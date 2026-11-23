#include <stdio.h>
int n,m;
int board[105][105]={0};
int slame[20000][2]={0};
int id=0;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&board[i][j]);
            if(board[i][j]>0){
                slame[id][0]=i;
                slame[id][1]=j;
                id++;
            }
        }
    }
    for(int i=0;i<id;i++){
        if(board[slame[i][0]-1][slame[i][1]]<0){
            board[slame[i][0]][slame[i][1]]-=board[slame[i][0]-1][slame[i][1]];
            board[slame[i][0]-1][slame[i][1]]=0;
        }
    }
    for(int i=0;i<id;i++){
        if(board[slame[i][0]][slame[i][1]+1]<0){
            board[slame[i][0]][slame[i][1]]-=board[slame[i][0]][slame[i][1]+1];
            board[slame[i][0]][slame[i][1]+1]=0;
        }
    }for(int i=0;i<id;i++){
        if(board[slame[i][0]+1][slame[i][1]]<0){
            board[slame[i][0]][slame[i][1]]-=board[slame[i][0]+1][slame[i][1]];
            board[slame[i][0]+1][slame[i][1]]=0;
        }
    }for(int i=0;i<id;i++){
        if(board[slame[i][0]][slame[i][1]-1]<0){
            board[slame[i][0]][slame[i][1]]-=board[slame[i][0]][slame[i][1]-1];
            board[slame[i][0]][slame[i][1]-1]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
    return 0;
}
