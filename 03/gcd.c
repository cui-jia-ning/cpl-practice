    // #include <stdio.h>
    // int main(void) {
    //     long long int a,b;
    //     scanf("%lld %lld",&a,&b);
    //     long long int x=a,y=b;
    //     long long int t;
    //     while(y!=0){
            
    //             t=x%y;
    //             x=y;
    //             y=t;
    //     }
    //     printf("%d",x);

            

        
    //     return 0;
    // }
    #include <stdio.h>

    int main() {
        int a,b;
        scanf("%d %d",&a,&b);
        int temp;
        int max,min;
        if(a>=b){max=a;min=b;}
        else{min=a;max=b;}
        while (1){
            temp=max%min;
            max=min;
            if(temp==0){
                printf("%d",min);
                break;
            }
            min=temp;
        }
        
        return 0;
    }
