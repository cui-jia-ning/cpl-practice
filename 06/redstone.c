#include <stdio.h>
#include <string.h>
#define START 5
int m,n;
char board[105][105]={0};
int x,y;
char c;
int tick=0;
int t;
void renew(void);
void renew_repeater(void);
int findmax(int i,int j);
int vectors[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int activate[105][105]={0};
int hexval(char c) {              // '0'~'9','A'~'F' → 0~15
    if (c >= '0' && c <= '9') return c - '0';
    return c - 'A' + 10;          // 'A'→10, 'F'→15
}



int main(void) {
    scanf("%d %d",&m,&n);
    for(int i=0+START;i<m+START;i++){
        for(int j=0+START;j<n+START;j++){
            scanf(" %c",&board[i][j]);
        }
    }
    scanf("%d %d %c",&x,&y,&c);
    scanf("%d",&t);

    if('?'!=c){
        board[x][y]=c;
    }
    while(t--){
        renew_repeater();
        renew();
    }
    for(int i=0+START;i<m+START;i++){
        for(int j=0+START;j<n+START;j++){
            printf("%c",board[i][j]);
        }
        printf("\n");
    }


    
    return 0;
}

void renew(void)
{
    int step=16;
    
    while(step--){
        for(int i=0+START;i<m+START;i++){
            for(int j=0+START;j<n+START;j++){
                if(board[i][j]>='0'&&board[i][j]<='9'||board[i][j]>='A'&&board[i][j]<='F'){
                    board[i][j]=findmax(i,j);
                }
            }
        }
    }
}

void renew_repeater(void)
{
    for (int i = START; i < m + START; i++) {
        for (int j = START; j < n + START; j++) {
            int di = 0, dj = 0;      // 后端相对于中继器的偏移
            char off, on;            // 未激活/激活字符
            switch (board[i][j]) {
                case ')': case '>': dj = -1; off = ')'; on = '>'; break;  // 后端在左
                case '(': case '<': dj = +1; off = '('; on = '<'; break;  // 后端在右
                case 'u': case 'v': di = -1; off = 'u'; on = 'v'; break;  // 后端在上
                case 'n': case '^': di = +1; off = 'n'; on = '^'; break;  // 后端在下
                default: continue;   // 不是中继器，跳过
            }

            // 读后端输入信号
            char b = board[i + di][j + dj];
            int in = 0;
            if (b == '*') in = 15;
            else if ((b >= '0' && b <= '9') || (b >= 'A' && b <= 'F')) in = hexval(b);
            // 后端若是"激活且正对着我"的中继器，输入也是 15（先不管可后补）

            board[i][j] = (in > 0) ? on : off;
        }
    }
}

int findmax(int i, int j)
{
    int max=0;
    for (int k = 0; k < 4; ++k) {
        int newI = i + vectors[k][0];
        int newJ = j + vectors[k][1];
        if(board[newI][newJ]=='*'){
            return 15;
        }
        else if(board[newI][newJ]>='0'&&board[newI][newJ]<='9'||board[newI][newJ]>='A'&&board[newI][newJ]<='F'){
            int v = hexval(board[newI][newJ]) - 1;
            if (v < 0) v = 0;
            if (v > max) max = v;
        }
        else{
            if(k==0&&board[newI][newJ]=='v'){return 15;}
            if(k==1&&board[newI][newJ]=='^'){return 15;}
            if(k==2&&board[newI][newJ]=='<'){return 15;}
            if(k==3&&board[newI][newJ]=='>'){return 15;}

        }
        
    }return max;
}
    
