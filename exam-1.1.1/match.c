#include <stdio.h>
int board[505][505]={0};
int seen[505][505]={0};//1被消除
int num[200000][2][2];
int flag[200000]={0};
int n,m;

int vectors[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
// 从 (x,y) 沿方向 d 走到边界，全空返回 1，否则 0
int clear_path(int x, int y, int d)
{
    int nx = x + vectors[d][0], ny = y + vectors[d][1];
    while (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
        if (board[nx][ny] != 0) return 0;   // 有未消除方块挡住
        nx += vectors[d][0];
        ny += vectors[d][1];
    }
    return 1;
}

int main(void) {
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&board[i][j]);
            if(flag[board[i][j]]==0){
                num[board[i][j]][0][0]=i;
                num[board[i][j]][0][1]=j;
            }
            else{
                num[board[i][j]][1][0]=i;
                num[board[i][j]][1][1]=j;
            }
        }
    }  
    for(int i=0;i< n*m/2;i++){
        check(i);
    }

    return 0;
}