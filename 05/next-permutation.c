#include <stdio.h>
int main(void) {
    int n;
    scanf("%d",&n);
    int num[2008];
    int i=0;
    while(scanf("%d",&num[i])==1){
        i++;
        if(i>n-1)break;
    }
    
    int m=1;
    if(n==2){
        int k;
        k=num[0];
        num[0]=num[1];
        num[1]=k;
    }
    for(int k=n-1;k>=1;k--){
        if(num[k]<num[k-1]){
            m++;
        }
        else{break;}
    }
    
    int max=2008;
    int max_d;
    for(int k=n-m;k<n;k++){
        if(num[k]>num[n-m-1]&&num[k]<max){max=num[k];max_d=k;}
    }



    int temp=num[n-m-1];
    num[n-m-1]=max;
    num[max_d]=temp;


    
    if(m%2==0){
        for(int k=0;k<m/2;k++){
            int s=0;
            s=num[n-m+k];
            num[n-m+k]=num[n-1-k];
            num[n-1-k]=s;

        }


    }
    else{
        for(int k=0;k<(m-1)/2;k++){
            int s=0;
            s=num[n-m+k];
            num[n-m+k]=num[n-1-k];
            num[n-1-k]=s;

        }

    }
    for(int i=0;i<n;i++){
        printf("%d ",num[i]);
    }
  
    return 0;
}