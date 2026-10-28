// #include <stdio.h>
// void to_dec_num(int a,int b);
// int main(void) {
//     int p,q,r;
//     scanf("%d %d %d",p,q,r);
//     for(int i=2;i<41;i++){
//         if(to_dec_num(p,i)&&to_dec_num(q,i)&&to_dec_num(r,i)){
//             if(to_dec_num(p,i)*to_dec_num(q,i)==to_dec_num(r,i)){
//                 printf("%d",i);
//             }
//             else if(i==40)printf("0");
//         }
//     }
  
//     return 0;
// }
// void to_dec_num(int x, int R) {
//     if (x == 0) return;
//     to_dec_num(x / R, R);      // 先走到最高位
//     putchar('0' + x % R);      // 回溯时输出，天然顺序正确
// }