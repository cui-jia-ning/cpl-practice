#include <stdio.h>
int main(void) {
    int n,m,t;
    scanf("%d %d %d",&n,&m,&t);
    
    int a[1000007];
    int b[1000007];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }

    int sum=-1;
    for(int i=0;i<m;i++){
        if(b[i]>t)continue;
        else{
            for(int j=0;j<n;j++){
                if(a[j]>t-b[i])break;
                else{
                    if(sum<a[j]+b[i]){
                        sum=a[j]+b[i];
                    }
                }
            }
        }
    }
    printf("%d",sum!=-1?t-sum:sum);

    return 0;
}