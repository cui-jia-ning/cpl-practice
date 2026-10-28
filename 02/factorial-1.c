#include <stdio.h>
#define M 10007
int main(void) {
    int n;
    scanf("%d",&n);

    int sum=0;
    
    for(int k=1;k<=n;k++)
    {
        int fact=1;
        for(int i=1;i<=k;i++){
        fact*=i;
        fact=fact%M;
     }

    
     sum+=fact;
     sum=sum%M;
    }
    
    printf("%d",sum);


    return 0;
}