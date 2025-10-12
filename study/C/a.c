// // a.c
// #include <stdio.h>
// #define MSG "Hello \
// World!\n"
// #define _str(x) #x
// #define _concat(a, b) a##b
// int main() {
//   printf(MSG /* "hi!\n" */);
// #ifdef __riscv
//   printf("Hello RISC-V!\n");
// #endif
//   _concat(pr, intf)(_str(RISC-V));
//   return 0;
// }

// #include <stdio.h>
// int main() { // compute 10 + 20
//   int x = 10, y = 20;
//   int z = x + y;
//   printf("z = %d\n", z);
//   return 0;
// }

// #include <stdlib.h>
// int main() {
//   int *p = malloc(sizeof(*p) * 10);
//   free(p);
//   return 0;
// }

// a.c
// #include <stdio.h>
// void f(int x, int y) {
//   printf("x = %d, y = %d\n", x, y);
// }
// int main() {
//   int i = 1;
//   f(i ++, i ++);
//   return 0;
// }

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <assert.h>

// #define 主函数 main
// #define 返回 return

// char* 字符串拼接(char *串1, char *串2) {
//   char *新串 = malloc(strlen(串1) + strlen(串2) + 1);
//   assert(新串);
//   strcpy(新串, 串1);
//   strcat(新串, 串2);
//   返回 新串;
// }

// int 主函数() {
//   char *信息 = 字符串拼接("一生一芯", "很简单");
//   printf("%s\n", 信息);
//   free(信息);
//   返回 0;
// }

// a.c
// #include <stdio.h>
// int main() {
//   int a[10] = {0};
//   printf("a[10] = %d\n", a[10]);
//   return 0;
// }
