#include <stdio.h>
int main(void) {
    int n;
    scanf("%d",&n);
    int len=2*n-1;
    int s[10002]={0};
    for(int i=0;i<2*n-1;i++){
    scanf("%d",&s[i]);}

    int num[10002]={0};
    for(int i=0;i<len;i++){
        num[s[i]]^=1;
    }
    for(int i=0;i<len;i++){
        if(num[s[i]]!=0){
            printf("%d",s[i]);
        }
    }
    
    
    
    
    return 0;
}