#include <stdio.h>
int main() {
    int day, year, hour, minute, second;
    char month[10];
    char weekday[10];
    scanf("%s %d %d %s %d %d %d", month, &day, &year, weekday, &hour, &minute, &second);
    printf("%.3s %.3s %2d %02d:%02d:%02d %04d\n", weekday, month, day, hour, minute, second, year);
    return 0;
}
