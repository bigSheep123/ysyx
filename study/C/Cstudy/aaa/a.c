// #include <stdio.h>
// int main() { // compute 1 + 2
//   int x = 1, y = 2;
//   int z = x + y;
//   printf("z = %d\n", z);
//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>
int main() {
  int *p = malloc(sizeof(*p) * 10);
  free(p);
  *p = 0;
  printf("hello");
  return 0;
}