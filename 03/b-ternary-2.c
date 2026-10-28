// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     int n;
//     scanf("%d", &n);
//     char s[20];

//     while (scanf("%s", s) == 1 && n > 0) {
//         // 第 1 步：校验
//         int flag = 1;
//         for (int i = 0; s[i] != '\0'; i++) {
//             if (s[i] < '0' || s[i] > '9') {
//                 if (!(i == 0 && s[i] == '-')) flag = 0;
//             }
//         }

//         if (flag == 0) {
//             printf("Radix Error\n");
//         } else {
//             // 第 2 步：字符串 → 整数
//             int neg = 0, start = 0;
//             if (s[0] == '-') { neg = 1; start = 1; }
//             int temp = 0;
//             for (int i = start; s[i] != '\0'; i++) {
//                 temp = temp * 10 + (s[i] - '0');
//             }

//             // 第 3 步：转平衡三进制
//             int t[25] = {0};
//             if (neg) temp = -temp;          // 转正
//             for (int i = 0; ; i++) {
//                 t[i] = temp % 3;
//                 if (temp == 0) break;
//                 temp /= 3;
//             }
//             if (t[0] == 0) {
//                 printf("0");
//             } else {
//             for (int i = 0; i < 24; i++) {
//                 switch (t[i]) {
//                     case 0: break;
//                     case 1: break;
//                     case 2: t[i] = -1; t[i + 1]++; break;
//                     case 3: t[i] = 0;  t[i + 1]++; break;
//                 }
//             }

//                 int k = 24;
//                 while (t[k] == 0) k--;
//                 for (int i = k; i >= 0; i--) {
//                     int d = t[i];
//                     if (neg) d = -d;        // 负数：1↔-1 互换，0 不变
//                     if (d == -1) printf("Z");
//                     else printf("%d", d);
//                 }
//             }
//             printf("\n");
//         }
//         n--;                                // 每行结束无条件减一
//     }
//     return 0;
// }
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXD 64

/* 判断是不是合法十进制串（不含Z！） */
int is_valid_decimal(char *s) {
    int len = strlen(s);
    if (len == 0) return 0;

    int start = 0;
    if (s[0] == '-') {
        if (len == 1) return 0;          // 光一个 '-'
        start = 1;
    }

    /* 检查字符集 */
    for (int i = 0; i < len; i++) {
        if (s[i] == '-' && i == 0) continue;
        if (!isdigit((unsigned char)s[i])) return 0; /* 有Z就这里毙掉 */
    }

    /* 负号后面不能跟 0 再加别的 (-0xxx / -0 题目说没有-0) */
    if (s[0] == '-') {
        if (s[1] == '0' && len > 2) return 0;
    } else {
        if (s[0] == '0' && len > 1) return 0; /* 前导零 */
    }
    return 1;
}

/*
 * 正整数 n -> 平衡三进制（结果写进 res）
 * 内部用 dig[] 存：-1=Z, 0, 1
 */
void pos_to_bt(int n, char *res) {
    int dig[MAXD] = {0};
    int len = 0;
    int tmp = n;
    while (tmp > 0) {
        dig[len++] = tmp % 3;
        tmp /= 3;
    }

    /* 从低位向高位修 */
    for (int i = 0; i < len; i++) {
        if (dig[i] == 2) {
            dig[i] = -1;
            dig[i + 1]++;
        } else if (dig[i] == 3) {   /* 被低位进位上来的 */
            dig[i] = 0;
            dig[i + 1]++;
        }
    }
    /* 最高位可能又产生进位 */
    if (dig[len] != 0) len++;

    /* 拼字符串（从高位往低位） */
    int idx = 0;
    int saw_nonzero = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (dig[i] == 0 && !saw_nonzero && i != 0) continue; /* 去前导零 */
        saw_nonzero = 1;
        if (dig[i] == -1)      res[idx++] = 'Z';
        else if (dig[i] == 0)  res[idx++] = '0';
        else                   res[idx++] = '1';
    }
    res[idx] = '\0';
}

/* 负数：先算 |n|，再 Z<->1 */
void neg_to_bt(int n, char *res) {
    pos_to_bt(-n, res);
    for (int i = 0; res[i]; i++) {
        if (res[i] == 'Z')      res[i] = '1';
        else if (res[i] == '1') res[i] = 'Z';
        /* 0 不动 */
    }
}

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    char buf[128];
    char ans[MAXD];
    for (int k = 0; k < T; k++) {
        scanf("%s", buf);
        if (!is_valid_decimal(buf)) {
            printf("Radix Error\n");
            continue;
        }
        /* 到这里一定是纯十进制串了 */
        long long llv = atoll(buf);   /* 用long long防边界抖动 */
        if (llv == 0) {
            printf("0\n");
        } else if (llv > 0) {
            pos_to_bt((int)llv, ans);
            printf("%s\n", ans);
        } else {
            neg_to_bt((int)llv, ans);
            printf("%s\n", ans);
        }
    }
    return 0;
}