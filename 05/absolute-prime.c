#include <stdio.h>
#include <math.h>
int is_ap(int x);
int conv(int x);
int main(void) {
    int n;
    scanf("%d",&n);

    int sum=0;
    for(int i=2;i<=n;i++){
        if(is_ap(conv(i))&&is_ap(i))sum++;
    }
    printf("%d",sum);   
        
    return 0;
}   
    int is_ap(int x){
        int flag = 1; // 1 表示该数是素数
        for (int i = 2; i <= sqrt(x + 0.5); i++) {
            if (x % i == 0) {
                flag = 0;
            }   
        }
        return flag;
    }
    // int conv(int x){
    //     int temp=0;
    //     while(1){
    //         temp=x%10;
    //         x/=10;
    //         if(x!=0)temp*=10;
    //         else{break;}
            
    //     }
    //     return temp;

    // }
    int conv(int x) {
    int r = 0;
    while (x > 0) {
        r = r * 10 + x % 10;
        x /= 10;
    }
    return r;
}