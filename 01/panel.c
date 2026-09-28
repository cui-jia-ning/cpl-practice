#include <stdio.h>
int main() {
  int W;

  char id[100];
  char username[100];
  char email[100];
  scanf("%d",&W);

 while (getchar() != '\n'); 

  // scanf("%s ,%s ,%s",id,username,email);
  scanf("%[^,]%*[,]%[^,]%*[,]%[^\n]",id,username,email );
  // printf("%s |%s |%s\n",id,username,email);
  // printf("| ID       |%-*s|\n| Username |%-*s|\n| Email    |%-*s|\n",W,id,W,username,W,email);
  printf("| ID       | %-*.*s |\n", W,W, id);
  printf("| Username | %-*.*s |\n", W, W,username);
  printf("| Email    | %-*.*s |\n", W,W, email);



  
    return 0;
}