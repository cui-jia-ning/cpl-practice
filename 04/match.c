#include <stdio.h>
int main(void) {
    int n,m;
    scanf("%d %d",&n,&m);
    int board[505][505]={0};
    int num[125010][2][2]={0};
    for(int i=0;i<n;i++){    
        for(int j=0;j<m;j++){
            scanf(" %d",&board[i][j]);
            (num[board[i][j]][0][0]==num[board[i][j]][1][0]&&
            num[board[i][j]][0][1]==num[board[i][j]][1][1])?
            (num[board[i][j]][0][0]=i,num[board[i][j]][0][1]=j):
            (num[board[i][j]][1][0]=i,num[board[i][j]][1][1]=j);

        }
    }
    for(int k=1;k<=(m*n/2);k++){
        //num[k][0][0] k,first,i
        //num[k][0][1] k,first,j
        for(int down=1;down+num[k][0][0]<n;down++){
            if(board[down+num[k][0][0]][num[k][0][1]]!=0)break;
            if(board[n-1][num[k][0][1]]==0){
                for(int down=1;down+num[k][1][0]<n;down++){
                    if(board[down+num[k][1][0]][num[k][1][1]]!=0)break;
                    if(board[n-1][num[k][1][1]]==0){printf("%d",k);
                                                    board[num[k][0][0]][num[k][0][1]]=0;
                                                    board[num[k][1][0]][num[k][1][1]]=0;}
                }
            }  
        }//down
        for(int up=1;num[k][0][0]-up>=0;up++){
            if(board[up-num[k][0][0]][num[k][0][1]]!=0)break;
            if(board[0][num[k][0][1]]==0){
                for(int down=1;num[k][1][0]-down>=0;down++){
                    if(board[num[k][1][0]-down][num[k][1][1]]!=0)break;
                    if(board[0][num[k][1][1]]==0){printf("%d",k);
                                                    board[num[k][0][0]][num[k][0][1]]=0;
                                                    board[num[k][1][0]][num[k][1][1]]=0;}
                }
            }  
        }//up
        for(int down=1;down+num[k][0][0]<n;down++){
            if(board[down+num[k][0][0]][num[k][0][1]]!=0)break;
            if(board[n-1][num[k][0][1]]==0){
                for(int down=1;down+num[k][1][0]<n;down++){
                    if(board[down+num[k][1][0]][num[k][1][1]]!=0)break;
                    if(board[n-1][num[k][1][1]]==0){printf("%d",k);
                                                    board[num[k][0][0]][num[k][0][1]]=0;
                                                    board[num[k][1][0]][num[k][1][1]]=0;}
                }
            }  
        }//left
        for(int down=1;down+num[k][0][0]<n;down++){
            if(board[down+num[k][0][0]][num[k][0][1]]!=0)break;
            if(board[n-1][num[k][0][1]]==0){
                for(int down=1;down+num[k][1][0]<n;down++){
                    if(board[down+num[k][1][0]][num[k][1][1]]!=0)break;
                    if(board[n-1][num[k][1][1]]==0){printf("%d",k);
                                                    board[num[k][0][0]][num[k][0][1]]=0;
                                                    board[num[k][1][0]][num[k][1][1]]=0;}
                }
            }  
        }//right





    }



    return 0;
}