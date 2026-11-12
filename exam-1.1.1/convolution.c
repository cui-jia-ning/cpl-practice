#include <stdio.h>
int h,w;
int matrix[50][50]={0};
int result[50][50]={0};
int kernel[3][3]={0};
void cacu(int i,int j){
    for(int m=0;m<3;m++){
        for(int n=0;n<3;n++){
            result[i][j]+=  matrix[i+m][j+n]*kernel[m][n];
        }
    }
}
int main(){
    scanf("%d %d",&h,&w);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&kernel[i][j]);
        }
    }
    for(int i=0;i<h-2;i++){
        for(int j=0;j<w-2;j++){
            cacu(i,j);
        }
    }
    for(int i=0;i<h-2;i++){
        for(int j=0;j<w-2;j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }



    return 0;
}