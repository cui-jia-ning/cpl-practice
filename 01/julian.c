#include <stdio.h>

int main() {
    int a,y,m,JDN,year,month,day;
    scanf("%4d %d %d",&year,&month,&day );
    a=(14-month)/12;
    y=year+4800-a;
    m=month +12*a -3;
    JDN=day+(int )(153*m+2)/5+365*y +(int)(y/4)-(int)(y/100)+(int)(y/400)-32045;
    printf("%d",JDN);
    
    return 0;
}