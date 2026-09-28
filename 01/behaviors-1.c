#include <stdio.h>

int main(void){
    int n;
    int num[20]={0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1};

    
    scanf("%d",&n);
    if (num[n-1]==1){
        printf("True");
    }
    else {printf("False");}
    return 0;
}