#include <stdio.h>
int main(void) {
    int n;
    scanf("%d",&n);
    int num[13]={0};
    num[1]=-1;
    num[2]=-2;
    num[3]=-3;
    num[4]=-4;
    num[5]=-5;
    num[6]=-6;
    num[7]=-7;
    num[8]=8;
    num[9]=9;
    num[10]=-10;
    num[11]=11;
    num[12]=12;
    
    int choose;
    int temp1=-1;
    int temp2=0;
    int temp3=0;
    while(scanf("%d",&choose)==1){
       temp1=num[choose]&temp1;
       temp2=num[choose]|temp2;
       temp3=num[choose]^temp3;

            
    }
    printf("%d %d %d",temp1,temp2,temp3);

    //010000010111

    return 0;
}