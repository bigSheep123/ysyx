// #include <stdlib.h>
// int main() {
//   int *p = malloc(sizeof(*p) * 10);
//   free(p);
//   *p = 0;
//   return 0;
// }

#include <stdio.h>
int main() { // compute 1 + 2
  int x = 1, y = 2;
  volatile int z = x + y;
  printf("z = %d\n", z);
  return 0;
}