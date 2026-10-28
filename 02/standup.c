#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 1;

    int s[100001];
    for (int i = 0; i <= n; i++) {       // n+1 个数：s=0 到 s=n
        scanf("%d", &s[i]);
    }

    long long standing = s[0];           // 社恐值为 0 的直接起立
    long long tuos = 0;

    for (int i = 1; i <= n; i++) {
        if (standing < i) {              // 起立人数不够触发社恐值为 i 的人
            tuos += i - standing;         // 加托补差
            standing = i;
        }
        standing += s[i];                // 这批人也起立了
    }

    printf("%lld\n", tuos);
    return 0;
}