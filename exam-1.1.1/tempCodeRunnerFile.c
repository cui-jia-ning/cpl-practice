#include <stdio.h>
#include <stdbool.h>
#define Start 5
int n;

char board[105][105][105]={0};
bool cboard[105][105][105]={0};
int vectors[6][3]={{-1,0,0},{1,0,0},{0,0,1},{0,0,-1},{0,-1,0},{0,1,0}};
int count(int i,int j,int k,int q){//q=0  ? -> * :number
    int cnt=0;
    for(int a=0;a<6;a++){
        if(board[i+vectors[a][0]][j+vectors[a][1]][k+vectors[a][2]]=='*'){
            cnt++;
        }
        if(q==0){
            if(board[i+vectors[a][0]][j+vectors[a][1]][k+vectors[a][2]]=='?'){
                cnt++;
            }
        }
    }
    return cnt;
}
int  versify(int q){
    int ok=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(board[Start+i][Start+j][Start+k]>='0'&&
                   board[Start+i][Start+j][Start+k]<='9'&&
                   board[Start+i][Start+j][Start+k]-'0'!=count(Start+i,Start+j,Start+k, q)){
                    ok=0;
                }
                
            }
        }
    }
    return ok;
}
int main(void) {
    int n;
    int x,y,z;
    scanf("%d",&n);
    for(int i=Start;i<Start+n;i++){
        for(int j=Start;j<Start+n;j++){
            for(int k=Start;k<Start+n;k++){
                scanf(" %c",&board[i][j][k]);
                if(board[i][j][k]=='?'){
                    x=i;
                    y=j;
                    z=k;
                }
            }
        }
    }
    if(versify(1)){
        printf("valid\n");
        printf("%d\n",count(x,y,z,1));
    }
    else if(versify(0)){
        printf("valid\n");
        printf("*");
    }
    else{
        printf("invalid\n");
        board[x][y][z]='*';
        for(int i=Start;i<Start+n;i++){
            for(int j=Start;j<Start+n;j++){
                for(int k=Start;k<Start+n;k++){
                    if(board[Start+i][Start+j][Start+k]>='0'&&
                       board[Start+i][Start+j][Start+k]<='9'&&
                       count(i,j,k,0)!=board[i][j][k]){
                        printf("%d %d %d\n",i,j,k);
                    }
                }
            }
    }
    }
    

  
    return 0;
}