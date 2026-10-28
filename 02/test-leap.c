#include <stdint.h>
#include <stdio.h>

int main() {
  uint64_t n, k;
  scanf("%llu %llu", &n, &k);
  k += n;

  if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0))
    puts("Leap year!");
  else
    puts("Normal year!");

  if (k % 400 == 0 || (k % 4 == 0 && k % 100 != 0))
    puts("Leap year!");
  else
    puts("Normal year!");
}