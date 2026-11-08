#include <stdio.h>
#define start 55

int board[700][700]={0};//把i=55,j=55作为起点
int maxpoint[50005][2];
int maxValue=0;
int x_move=0;
int y_move=0;
int isright=1;
int ansN=1;//可以取到最大价值的落锤中心点坐标的数量
int n,m,d;
int goback=1;//默认未翻转
int move(int x_move,int y_move,int isright);//普通情况下根据开关决定方向，返回差，1向右
void Clear(void);//清空当前maxpoint
void judge(void);
int main(void) {
    scanf("%d %d %d",&n,&m,&d);
    for(int i=start;i<start+n;i++){
        for(int j=start;j<start+m;j++){
            scanf(" %c",&board[i][j]);
        }
    }
   
    for(int i=start-d;i<=start+d;i++){
        for(int j=start-d;i<=start+d;i++){
            maxValue+=board[i][j];
        }
    }
    maxpoint[0][0]=start;
    maxpoint[0][1]=start;

    
    while (!(x_move==m&&y_move==n))  {
        
        judge(); 
    }





  
    return 0;
}

int move(int x_move, int y_move, int isright)
{
    int minus=0;
    int plus=0;
    if(goback==1){
        x_move+=isright*1;
        if(x_move==m||x_move==0){
            goback*=-1;    
            isright*=-1;

            }  

        for(int i=-d;i<=d;i++){
            plus+=board[start+x_move+isright*i][start+y_move+i];
            minus+=board[start+x_move-isright*i][start+y_move+i];
        }
        return plus-minus;
    }
    else{
        for(int i=0;i<=d;i++){
            plus+=board[start+x_move+i ][start+y_move+d-i];
            plus+=board[start+x_move-i ][start+y_move+d-i];
            plus--;
            minus+=board[start+x_move+i ][start+y_move+i-d];
            minus+=board[start+x_move-i ][start+y_move+i-d];
            minus--;
            
        }

    }

}
void Clear(void)
{
for(int i=0;i<ansN;i++){
    maxpoint[i][0]=0;
    maxpoint[i][1]=0;
}
}
void judge(void)
{
    
    
            int temp=move(x_move,y_move,isright);
            if(temp<0){
                /*move on*/
            }
            else if(temp==0){
                maxpoint[ansN][0]=start+ x_move; 
                maxpoint[ansN][1]=start+ y_move; 
                ansN+=1;/*append*/
            }
            else{
                Clear();
                ansN=1;
                maxpoint[0][0]=start+ x_move;
                maxpoint[0][1]=start+ y_move;
                maxValue+=temp;
            }/*replace*/
        
}