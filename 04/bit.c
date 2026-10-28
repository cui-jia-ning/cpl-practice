#include <stdio.h>

int main(){
    int a,b;
    scanf("%d %d",&a,&b);

    printf("%d\n",a&b);//1
    printf("%d\n",a|b);//2
    printf("%d\n",a^b);//3
    printf("%d\n",~a);//4
    printf("%d\n",a<<b);//5
    printf("%d\n",a>>b);//6
    printf("%d\n",((a>>b)%2));//7

    int cnt=0;
    while(a>0){
        if(a%2==1){cnt++;}
        // a>>1;空
        a>>=1;
    }
    printf("%d",cnt);//8

    return 0;
}