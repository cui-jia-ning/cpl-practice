#include <stdio.h>
int n,m;
int id[105]={0};//default 0  test=false 1 test=true 2 
int ID[505][105][2]={0};//ID[组数][xu号][0阳性候选，编号]      ID id1 id2 id3 ...
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int c,r;
        scanf("%d %d",&c,&r);
        if(r==0){
            for(int k=0;k<c;k++){
                int temp;
                scanf("%d",&temp);
                id[temp]=1;
            }
        }
        else{
            for(int k=0;k<c;k++){
                int tempid;
                scanf("%d",&tempid);
                id[tempid]=2;
                ID[i][k][0]=0;
                ID[i][k][1]=tempid;
            }
        }
    }
    
    return 0;
}