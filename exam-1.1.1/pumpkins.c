#include <stdio.h>
#define begin 5
int m,n;
int board[505][505]={0};
int time[2600000][2]={0};
int vectors[4][3][2]={{{-1,-1},{-1,0},{0,-1}},
                        {{-1,0},{-1,1},{0,1}} , 
                        {{0,-1},{1,-1},{1,0}},
                        {{0,1},{1,1},{1,0}}};
float output[2600000][4]={0};//[0/1][t][r][c]

int total=0;
int timeMax=0;
int makebig(int i,int j,int t){
    board[i][j]=-1;
    int combined=0;
    for(int a=0;a<4;a++){
        if(combined)break;
        int cnt=0;
        for(int k=0;k<3;k++){
            
            if(board[i+vectors[a][k][0]][j+vectors[a][k][1]]!=-1){
                break;
            }
            else{
                cnt++;
            }
            if(cnt==3){
                combined=1;
                for(int k=0;k<3;k++){
                    board[i+vectors[a][k][0]][j+vectors[a][k][1]]=0;
                    board[i][j]=0;
                }

                float ri,ci;
                switch(a){
                    case 0:ri=i-0.5;ci=j-0.5;break;
                    case 1:ri=i-0.5;ci=j+0.5;break;
                    case 2:ri=i+0.5;ci=j-0.5;break;
                    case 3:ri=i+0.5;ci=j+0.5;break;
                }
                output[t][0]=1;
                output[t][1]=t;
                output[t][2]=ri;
                output[t][3]=ci;
                
                return 1;
            }
            
        }
    }
    
    return 0;
}
int main(){
    scanf("%d %d",&m,&n);
    for(int i=0+begin;i<m+begin;i++){
        for(int j=0+begin;j<n+begin;j++){
            scanf("%d",&board[i][j]);
            if(board[i][j]!=0){
                time[board[i][j]][0]=i;
                time[board[i][j]][1]=j;
                if(board[i][j]>timeMax){
                    timeMax=board[i][j];
                }
            }
        }
    }
    for(int i=0;i<=timeMax;i++){
        if(time[i][0]==0&&time[i][1]==0){
            continue;
        }
        if(makebig(time[i][0],time[i][1],i)){
            total++;
        }
    }
    printf("%d\n",total);
    for(int i=0;i<=timeMax;i++){
        if(output[i][0]<0.05&&output[i][0]>-0.05){
            continue;
        }
        else{
            printf("%d ",(int)(output[i][1]+0.5));
            printf("%.1f ",output[i][2]-4);
            printf("%.1f ",output[i][3]-4);
            printf("\n");
        }
    }




    return 0;
}