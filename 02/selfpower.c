#include <stdio.h>
#include<math.h>
int main(void) {
  int n;
  scanf("%d",&n);
  int count=0;
  int temp=n;

  while(temp>0){
    temp/=10;
    for(int i=0;i<count;i++){
      temp*=temp;
    }
    count+=1;
  
  
    }
 
  
  
    return 0;
}