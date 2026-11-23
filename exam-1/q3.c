#include <stdio.h>
int m,n,q;
char id[2005][30]={0};
// int menu[200000][3]={0};
// int idtoOut[2005][2]={0}; 
int product[2005][2005]={0};
int bowl[500040]={0};
int top=0;
int main(){
    scanf("%d %d %d",&m,&n,&q);
    for(int i=1;i<=m;i++){
        scanf("%s",id[i]);
    }
    for(int i=0;i<n;i++){
        int i1,i2,i3;
        scanf("%d",&i1);
        // menu[i][0]=i1;

        getchar();
        getchar();
        getchar();
        scanf("%d",&i2);
        // menu[i][1]=i2;
       getchar();
        getchar();
        getchar();
        scanf("%d",&i3);
        product[i1][i2]=i3;
        product[i2][i1]=i3;

        // menu[i][2]=i3;
        // idtoOut[i1][1]=i3;
        // idtoOut[i2][1]=i3;
        // idtoOut[i1][0]=i2;
        // idtoOut[i2][0]=i1;

    }
    
    
    while(q--){
        char req[10]={0};
        scanf("%s",req);
        if(req[0]=='A'){
                int temp;
                scanf("%d",&temp);
                bowl[top++]=temp;
        }
        // if(req[0]=='B'){
        //    int read=0;
        //    int write=0;
        //    for(;read<top;read++){
        //     if( read+1<top&&product[bowl[read]][bowl[read+1]]==0){
        //         bowl[write++]=bowl[read];
        //         continue;
        //     }
        //     if(product[bowl[read]][bowl[read+1]]>0){
        //         bowl[write++]=product[bowl[read]][bowl[read+1]];
        //         read++;
        //     }
        //    }
        //    top=write;
        // }
        if (req[0] == 'B') {
    int read = 0;
    int write = 0;

    for (; read < top; read++) {
        int a = bowl[read];

        if (read + 1 < top) {
            int b = bowl[read + 1];
            int c = product[a][b];

            if (c > 0) {
                bowl[write++] = c;
                read++;       // 再加循环末尾的 read++，共前进两层
                continue;
            }
        }

        // 没有上层，或者与上层没有配方：原样保留
        bowl[write++] = a;
    }

    top = write;
}
    }
    if(top==0){
        printf("EMPTY");    
    }
    else{
        for(int i=0;i<top;i++){
            for(int j=0;j<30;j++){
                if(id[bowl[i]][j]=='\0'){
                    break;
                }
                printf("%c",id[bowl[i]][j]);
            }
            printf("\n");
        }
    }


    return 0;
}   