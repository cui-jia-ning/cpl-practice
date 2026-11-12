#include <stdio.h>
int n;
int power[10005]={0};
int maxPower=0;
int flag=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&power[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int k=i+1;k<n;k++){
            if(power[k]<power[i]){
                continue;
            }
            else{
                flag=1;
                if(power[k]-power[i]>maxPower){
                    maxPower=power[k]-power[i];
                }
            }
        }
    }
    if(flag==0){
        printf("0");
    }
    else{
        printf("%d",maxPower);
    }




    return 0;
}