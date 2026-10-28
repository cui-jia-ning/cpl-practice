#include <stdio.h>
int main(void) {
    int m,n,p;
    scanf("%d %d %d",&m,&n,&p);
    int a[105][105];
    int ai=0;
    int aj=0;
    while(scanf(" %d",a[ai])==1){
        if(ai==m-1&&aj==n-1){break;}
        
        aj++;  
        if(aj==n-1){ai++;aj=0;}
    }
    
    int b[105][105];
    int bi=0;
    int bj=0;
    while(scanf(" %d",b[bi])==1){
        if(bi==n-1&&bj==p-1){break;}
        
        bj++;  
        if(bj==p-1){bi++;bj=0;}
    }
    int ci=0;
    int cj=0;
    int c[105][105];
    for(ci=0;ci<m;ci++){
        for(cj=0;cj<p;cj++){
            for(int k=0;k<n;k++){
                c[ci][cj]+=a[ci][k]*b[k][cj];
            }
        }
    }
    
    
    for(ci=0;ci<m;ci++){
        for(cj=0;cj<p;cj++){
            printf("%d ",c[ci][cj]);
        }
        printf("\n");
    }
    return 0;
}