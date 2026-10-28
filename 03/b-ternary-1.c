#include <stdio.h>
#include <string.h>
int power(int a,int b){
    int r=1;
    for(int i=0;i<b;i++){
        r*=a;
    }return r;
}
int main(void) {
  int n;
  scanf("%d",&n);
  char s[20];
  int sum=0;
  int len=0;
  while(scanf("%s",s)==1&&n>0){    
    len=strlen(s);
    int flag=1;
    for(int i=0;i<len;i++){
        if(s[i]=='0'||s[i]=='1'||s[i]=='Z'||s[i]=='\0'){
            switch(s[i]){
                case '0':s[i]='0'-'0';break;
                case '1':s[i]='1'-'0';break;
                case 'Z':s[i]='0'-'1';break;
            }
            
        }
        else{flag=0;break;}
    }
    if(flag==0){printf("Radix Error\n");}
    if(flag==1){
        for(int i=0;i<len;i++){
            sum+=s[i]*power(3,len-1-i);
        }
        for(int i=0;i<len;i++){
            s[i]=0;
        }
        printf("%d\n",sum);
    }
    sum=0;
    n--;
  }
    return 0;
}