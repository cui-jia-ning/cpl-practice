#include <stdio.h>

int main(void) {
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if((a+b)>c&&(a+c)>b&&(b+c)>a){
        if (a==b&&b==c) printf("equilateral triangle");
        else if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a){
            printf("right triangle");
        }
        else if(a*a+b*b<=c*c||a*a+c*c<=b*b||b*b+c*c<=a*a){
            printf("obtuse%s",a==b||a==c||b==c?" isosceles triangle":" triangle");}
        else printf("acute%s",a==b||a==c||b==c?" isosceles triangle":" triangle");


    }
    else printf("not triangle");

  
    return 0;
}