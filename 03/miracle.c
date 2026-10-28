#include <stdio.h>
#include <string.h>
int main(void) {
    char s[10005];
    while(scanf("%s",s)==1){
        int  len=strlen(s);
        int is_num[10005]={0};
        
        for(int i=0;i<len;i++){
            if(s[i]<'A'){
                is_num[i]=1;
            }
        }//区分字母和数字
        long long int temp=0;//数
        int cnt=0;
        for(int i=0;i<len;i++){
            
            if(is_num[i]==1){
                temp+=s[i]-'0';
                cnt++;
                if(is_num[i+1]==1){
                    temp*=10;
                }
                else{
                    long long int sum=0;
                    int convert_sum=0;
                    if(cnt>1){
                        int k=1;
                        while(temp!=0){
                             sum+=temp/k;
                            k*=10;
                            if(temp/k==0){
                                temp%=k/10;
                                k=1;
                            }
                            
                        }
                        // 翻转
                        while(sum>0){
                            sum%=10;
                            printf("%d",sum);
                            sum/=10;
                        }

                        
                        
                    }
                    
                    else{printf("%c",s[i]);}
                    cnt=0;
                }
            }
            else{printf("%c",s[i]);}
        }

        printf("\n");
    }
    
     
    return 0;
}