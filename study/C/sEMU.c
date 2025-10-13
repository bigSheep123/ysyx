#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// 用C语言来实现程序执行的过程
uint8_t PC = 0;
uint8_t R[4];
uint8_t M[16];

// Regs:  R[0-3]  00 01 10 11
//  00 rd rs1 rs2    add 指令 
//  10 rd imm        R[rd]=imm
//  11 addr   rs2    

void init_Mem() {
    M[0] = 0b10000001;
    M[1] = 0b10010010;
    M[2] = 0b00110001;
    M[3] = 0b11000000; 
}

void inst_cycle() {
    uint8_t inst = M[PC];
    uint8_t opCode = inst >> 6;
    if( opCode == 0x0 ) {
        uint8_t rd = (inst >> 4)&(0x03), rs1 = (inst >> 2)&(0x03), rs2 = inst&(0x03);
        R[rd] = R[rs1] + R[rs2];
    } else if ( opCode == 0x2 ){
        uint8_t reg = (inst >> 4)&(0x03);
        R[reg] = (inst)&(0x0F); 
    } else if (opCode == 0x3) {
        printf("PC:%d\n",PC);
        printf("R[0]:%d\n",R[0]);
        printf("R[1]:%d\n",R[1]);
        printf("R[2]:%d\n",R[2]);
        printf("R[3]:%d\n",R[3]);
        exit(-1);
    } else 
        assert("can't recognize opCode");
    PC++;
}

int main() 
{
    init_Mem();
    while(1) {
        inst_cycle();
    }
}