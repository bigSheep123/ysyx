// #include <stdint.h>
// void _start() {
//   volatile uint8_t *p = (uint8_t *)(uintptr_t)0x10000000;
//   *p = 'A';
//   while (1);
// }

// #include <stdint.h>
// void _start() {
//   volatile uint8_t *p = (uint8_t *)(uintptr_t)0x10000000;
//   *p = 'A';
// //   volatile uint32_t *exit = (uint32_t *)(uintptr_t)0x100000;
// //   *exit = 0x5555; // magic number
//   _start();
// }

// RISC-V 64 位裸机程序，向 UART0 发送 "Hello, RISC-V!"
// #define UART_BASE 0x10000000
// volatile char *const UART_THR = (char *)UART_BASE;

// void uart_putchar(char c) {
//     *UART_THR = c; // 直接写入 UART
// }

// void uart_puts(const char *s) {
//     while (*s) {
//         uart_putchar(*s++);
//     }
// }

// void main() {
//     uart_puts("Hello, RISC-V!\n");
// }


static void ebreak(long arg0,long arg1){
    asm volatile("addi a0, x0, %0;"
                 "addi a1, x0, %1;"
                 "ebreak" : : "i"(arg0), "i"(arg1));
}

static void putch(char ch) {ebreak(0,ch);}
static void halt(int code) {ebreak(1,code);while(1);}

void _start(){
    putch('A');
    halt(0);
}