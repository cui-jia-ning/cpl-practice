#include <stdio.h>
int repeat(int a); //检查加入食材是否与锅中食材一致，若是返回1
void clear(void);  //清空锅
void push(int a); //把食材放到锅里
int total(void); //统计锅中数量
int pair(int j);//菜谱检查 做完返回1，继续烹饪返回0,当前菜谱不匹配返回-1

int temp_input[10005]={0}; //锅
int menu[205][13]={0};
int msize[205];
int main(void) {
    int n; //有n种不同的食材
    int m; //待完成的订单
    int k; //表示按顺序加入的所有食材
    scanf("%d %d %d",&n,&m,&k);
    
    int step=0;
    int step_ok[205]={0};
    int num_fire=0; //起火次数
    while(m--){
        int size;
        scanf(" %d",&size);
        msize[step]=size;
        for(int i=0;i<size;i++){
            scanf("%d",&menu[step][i]);
        }
        step++;
    }
    int input[10005];
    for(int i=0;i<k;i++){
        scanf("%d",&input[i]);
        if(repeat(input[i])){//判断加入的食材是否与锅里已有的食材重合
            num_fire++;
            clear();
        }
        else{
            push(input[i]); //加入食材
            int flag=0;
            for(int j=0;j<step;j++){
                if(step_ok[j]==1){continue;}
                else{//对于所有还未完成订单的菜谱检查
                    if(pair(j)==1){
                        step_ok[j]=1;
                        clear();
                        flag=1;
                        break;
                    }
                    else if(pair(j)==0){
                        flag=1;
                        continue;
                    }
                    else{
                        continue;
                    }

                }
            }
            if(flag==0){
                num_fire++;
                clear();
            }
        }
    }
    int ok=1;
    int score=0;
    for(int i=0;i<step;i++){
    if(step_ok[i]==0){
        ok=0;            // 有未完成的 
    } else {
        score++;         // 已完成的 
    }
}
    if(ok==1){
        printf("Well Done!\n");
    }
    else if(num_fire==0){
        printf("Not Bad!\n");
    }
    else{
        printf("Cooked!\n");
    }
    
    
    
    printf("%d\n",score);
    printf("%d\n",num_fire);

    
  
    return 0;
}

int repeat(int a)
{
    for(int i=0;i<total();i++){
        if(temp_input[i]==a){
            return 1;
        }
    }
    return 0;
}

void clear(void)
{
    int t = total();        // 先把数量存下来，再动手清
    for(int i=0;i<t;i++){
        temp_input[i]=0;
    }
}

void push(int a)
{
    temp_input[total()]=a;
}

int total(void)
{
    int sum=0;
    for(int i=0;i<10005;i++){
        if(temp_input[i]!=0){
            sum++;
        }
        else{break;}
    }
    return sum;
}

int pair(int j)
{
    for(int i=0;i<total();i++){          
    int found=0;
    for(int p=0;menu[j][p]!=0;p++){  
        if(temp_input[i]==menu[j][p]){ found=1; break; }
    }
    if(!found) return -1;            // 有食材不在菜谱里 → 不匹配
}
// 走到这里：锅是菜谱的子集
if(total()==msize[j]) return 1; // 子集且数量相等 → 完全相同
return 0;                            // 真子集 → 继续烹饪


}
