#include <stdio.h>
int colTotal[400];
int n,m,k;
int board[90][310]={0};

int check(int C) {
    int up[400] = {0};

    // 枚举横线，r 表示第 r 行进入上半部分
    for (int r = 0; r < n - 1; r++) {
        for (int j = 0; j < m; j++) {
            up[j] += board[r][j];
        }

        int lines = 0;     // 已使用的竖线数量
        int sumUp = 0;
        int sumDown = 0;
        int ok = 1;

        for (int j = 0; j < m; j++) {
            int u = up[j];
            int d = colTotal[j] - u;

            // 单列本身就装不下
            if (u > C || d > C) {
                ok = 0;
                break;
            }

            // 当前列放不进原来的区域，在它左侧切一刀
            if (sumUp + u > C || sumDown + d > C) {
                lines++;
                sumUp = u;
                sumDown = d;
            } else {
                sumUp += u;
                sumDown += d;
            }
        }

        if (ok && lines <= k - 1) {
            return 1;
        }
    }

    return 0;
}
int main(){
    
    int total=0;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&board[i][j]);
            total+=board[i][j];
            colTotal[j] += board[i][j];
        }
    }

    // int top = 0;
    // int vmin = total;

    // for (int r = 0; r < n - 1; r++) {
    //     // 横线下移一行，第 r 行进入上半部分
    //     for (int j = 0; j < m; j++) {
    //         top += board[r][j];
    //     }

    //     int bottom = total - top;

    //     int capacity;
    //     if (top > bottom) {
    //         capacity = top;
    //     } else {
    //         capacity = bottom;
    //     }

    //     if (capacity < vmin) {
    //         vmin = capacity;
    //     }
    // }

    // printf("%d", vmin);


    // for(int i=0;i<total;i++){
    //     if(check(i)==1){
    //         printf("%d",i);
    //         break;
    //     }
    // }
    


    // if(check(11)==1){printf("ok");}else{printf("false");}
    // if(check(10)==0){printf("ok");}else{printf("false");}
    int left = 0;
int right = total;

while (left < right) {
    int mid = left + (right - left) / 2;

    if (check(mid)) {
        right = mid;       // mid 可行，答案可能是 mid，不能丢掉
    } else {
        left = mid + 1;    // mid 太小，答案一定更大
    }
}

printf("%d\n", left);

    return 0;
}