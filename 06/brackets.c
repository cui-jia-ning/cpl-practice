#include <stdio.h>
#include <string.h>

char st[100005];     // 栈：装等待配对的左括号
int top;             // 下一个空位下标

int main(void) {
    int n;
    scanf("%d", &n);
    char s[100005];
    while (n--) {
        scanf("%s", s);
        top = 0;                 // 每组数据重置栈
        int ok = 1;              // 先假设合法（还记得 flag 的用法吗）
        for (int i = 0; s[i] != '\0'; i++) {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') {
                st[top++]=c;
            } else {
                if(top==0){ok=0;break;}// 空②：右括号。栈空 → ok=0 并跳出循环；
                else if(!((st[top-1]=='('&&c==')'||
                         st[top-1]=='{'&&c=='}'||
                         st[top-1]=='['&&c==']'))){
                            ok=0;
                            break;
                         }//       栈顶和 c 不匹配 → ok=0 并跳出；
                else{top--;}//       匹配 → 出栈
            }
        }
        if(top!=0){ok=0;}// 空③：循环结束后，还要检查什么条件才说明栈里没有"剩"的左括号？
        //       （提示：ok 为 1 且 ____ 才输出 True）
        printf(ok ? "True\n" : "False\n");
    }
    return 0;
}