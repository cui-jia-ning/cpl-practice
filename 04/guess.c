#include <stdio.h>
#include <stdlib.h>

int main() {
    char res[10];
  
    
    long long unsigned int guess = 2147483648;
    int maxguess=4294967296;
    int minguess=0;

    while (1) {
        printf("%llu\n", guess);
        fflush(stdout);
        scanf("%s", res);

        switch (res[0]) {
            case 'G': {
                maxguess=guess;
                guess=(maxguess+minguess)/2;

                break;
            }
            case 'L': {
                minguess=guess;
                guess=(maxguess+minguess)/2;

                break;
            }
            case 'E': return 0;
            case 'O': return 0;
        }
    }
}
