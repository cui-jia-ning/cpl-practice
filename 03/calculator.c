#include <stdio.h>
int main(void) {
    char s[5];
     int a,b;
    while(scanf("%d %4s %d", &a,s,&b) ==3){
        if(s[0]=='+')           printf("%d\n",a+b);
        if(s[0]=='-')           printf("%d\n",a-b);
        if(s[0]=='*'&&s[1]=='\0')  printf("%d\n",a*b);
        if(s[0]=='/'&&s[1]=='\0')  printf("%d\n",a/b);
        if(s[0]=='/'&&s[1]=='*')  printf("%.3f\n",(float)a/b);
        if(s[0]=='*'&&s[1]=='*')  {
            int r=1;
            for(int i=0;i<b;i++){
                r*=a;
            }                   printf("%d\n",r);
        }
        if(s[0]=='%')  printf("%d\n",a%b);
      
    }
  
    return 0;
}
