#include <stdio.h>

int transpace(int space); 
int sz[10050];
int ID[10050]={0};
int find_exact(int space); //返回在内存中的节点位置,若无对应返回-1
int find_bigger(int space); //返回在内存中的节点位置
void split(int p);  //把p所指的内存对分，重构后续数组
int m=1; //总结点数

int main(void) {
    int n,q;
    scanf("%d %d",&n,&q);
    
    
    sz[0]=n;
    while(q--){
        int fst;
        scanf(" %c",&fst);
         
        if(fst=='A'){
            int space;
            int id;
            scanf("%d %d",&id ,&space);
            space=transpace(space); //space是指数，范围0到m
            
            if(find_exact(space)!=-1&&ID[find_exact(space)]==0){
                ID[find_exact(space)]=id;
            }
            else{
                do{
                    int p;
                    p=find_bigger(space);
                    split(p);
                    m++;
                }while(!(find_exact(space)!=-1&&ID[find_exact(space)]==0));
                ID[find_exact(space)]=id;
                
            }

        }
        else{
            printf("%d\n",m);
            for(int i=0;i<m;i++){
                printf("%d ",ID[i]);
            }
            printf("\n");
            
        }
        
        
    }
   
    return 0;
}

int transpace(int space)
{
    // int i=1;
    // int k=0;
    // while(space>2*i){
    //     i*=2;
    //     k++;
    // }
    // if(space>i&&space<=2*i){
    //     return k+1;
    // }
    // if(space==1){
    //     return 1;
    // }
    int e = 0; while ((1 << e) < space) e++; return e;
    
}

int find_exact(int space)
{
    for(int i=0;i<m;i++){
        if(sz[i]==space&&ID[i]==0){
            return i;
        }
    }
    return -1;
    
}

int find_bigger(int space)
{
    for(int i=0;i<m;i++){
        if(sz[i]>space&&ID[i]==0){
            return i;
            break;
        }
    }
}

void split(int p)
{
    for(int i=m;i>p;i--){
        sz[i+1]=sz[i];
        ID[i+1]=ID[i];
    }
    sz[p]--;
    sz[p+1]=sz[p];
    ID[p+1]=0;
}
