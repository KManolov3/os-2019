#include <unistd.h>
#include <stdio.h>
int main()
{
  int x = 1;

  char *y = (char*)&x;

  printf("%c\n",*y+48);
}
