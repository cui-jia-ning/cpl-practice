#include <stdio.h>
int main(void) {
  unsigned int addr ,data;
  scanf("%u %u",&addr,&data);
  printf("0x%08x:  %02x %02x %02x %02x",
        addr,
        (data>>24) & 0xFF,
        (data>>16) & 0xFF,
        (data>>8) & 0xFF,
        data & 0xFF)
    ;
  
  return 0;
}