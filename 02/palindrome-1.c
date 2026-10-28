#include <stdio.h>
int main(void) {
    int n;
    scanf("%d",&n);
    char c;
    scanf("%c",&c);
    char s[2500]={0};
    for(int i=0;i<=2500;i++){
         scanf("%c",&s[i]);
         if(s[i]==10) {
            s[i]='!';
            break;
         }
    }
    for (int i=0;i<=2500&&s[i]!='!';i++){
        printf("%c",s[i]=='?'?s[n-1-i]:s[i]);
    }
   
  
    return 0;
}