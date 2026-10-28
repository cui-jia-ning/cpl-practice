// #include <stdio.h>
// #define len 505

// int main(void) {
//   int n,k;
//   scanf("%d %d",&n,&k);
//   int N=n;

//   int num[len]={0};
//   int count=1;
//   while(n>1){
//    for(int step=1;step<k;step++){
    
//     do{
//       count++;
//       count=(count-1)%N+1;
//     }while (num[count]==1);
    
//     }
    
    
//   n--;
//     num[count]=1;

//    do {
//             count = count % N + 1;
//         } while (num[count] == 1);

 
//   } for(int i=1;i<=N;i++)
//     if(num[i]==0){printf("%d",i); break;}

// return 0;
// }
#include <stdio.h>

int main() {
    int n,k;
    scanf("%d %d",&n,&k);

    int ap=1;
    int actemp=1;
    for(int i=2;i<=n;i++){
        actemp=(k%i+1)%i+1;
        if(ap==actemp)continue;
        else if(ap<actemp)ap++;
        else continue;
    }
    printf("%d",ap);


    
    return 0;
}