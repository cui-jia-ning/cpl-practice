#include <stdio.h>
#define G 6.674e-11
#define M 77.15



int main(){
    double m, R,Force;
    scanf("%lf %lf",&m,&R);
    Force= (G*M*m)/(R*R);
    // if(Force>=1){
        printf("%.3e",(G*M*m)/(R*R));
    // }
    // else if (Force>=0.1){
    //      printf("%.3e",(G*M*m)/(R*R));
    // }






    
    
    
    
    
    return 0;



}