#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
  int x_a,y_a,x_b,y_b;
  double dst,agl,agl_2;
  scanf("%d %d",&x_a,&y_a);
  scanf("%d %d",&x_b,&y_b);
  // dst =sqrt (pow((x_a-x_b),2)+pow((y_a-y_b),2));
  dst=hypot(x_a-x_b,y_a-y_b);
  // agl=acos((y_b-y_a)/dst)*180/acos(-1)
  agl=atan2(x_b-x_a,y_b-y_a)*180/acos(-1);
  agl_2=fmod(agl+360,360);
  
printf("%.4f %.4f",dst,agl_2);
    
    return 0;
}
 