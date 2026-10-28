#include <stdio.h>

int val(char c, int N) {
    int v;
    if (c >= '0' && c <= '9') v = c - '0';
    else if (c >= 'A' && c <= 'F') v = c - 'A' + 10;
    else return -1;

    if (v >= N) return -1;
    return v;
}

int main(void) {
    int len, N;
    scanf("%d %d", &len, &N);

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    char s[35];
    scanf("%30s", s);

    long long sum = 0;
    for (int i = 0; i < len; i++) {
        int v = val(s[i], N);
        if (v < 0) {
            printf("Error\n");
            return 0;
        }
        sum = sum * N + v;
    }

    printf("%lld\n", sum);
    return 0;
}