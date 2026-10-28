    #include <stdio.h>
    #include <string.h>

    void cmd_push(char a);
    void cmd_pop(void);
    void cmd_top(void);
    void cmd_print(void);
    char stack[10005];
    int top=-1;

    int main(void) {
        int n;
        scanf("%d",&n);
        

        
        for(int round=0;round<n;round++){
            char cmd[10]={'\0'};
            scanf("%s",cmd);
            if(strncmp(cmd, "push",4) == 0){
                char m;
                scanf(" %c",&m);
                cmd_push(m);
            }
            if(strncmp(cmd, "pop",3) == 0){
                cmd_pop();
            }
            if(strncmp(cmd, "top",3) == 0){
                cmd_top();
            }if(strncmp(cmd, "print",5) == 0){
                cmd_print();
            }
        }
    
        return 0;
    }

    void cmd_push(char a)
    {
    top++;
    stack[top]=a;
    }

    void cmd_pop(void)
    {
        if(top==-1){
            printf("Empty\n");
        }
        else{
            
            top--;
        }
        
    }

    void cmd_top(void)
    {
        if(top==-1){
            printf("Empty\n");
        }
        else{
            printf("%c\n",stack[top]);
        }
    }

    void cmd_print(void)
    {
        if(top==-1){
            printf("Empty\n");
        }
        else{
            for(int k=top;k>=0;k--){
                printf("| %c |\n",stack[k]);
            }
            printf("|===|\n");
        }
    }
