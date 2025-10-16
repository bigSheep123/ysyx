#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// 用C语言来实现程序执行的过程
uint8_t PC = 0;
uint8_t R[4];
uint8_t M[16];

// 0:li rθ，10   # 这里是十进制的10
// l:li rl，θ
// 2:li r2，θ
// 3: li r3,1
// 4: add rl,rl,r3
// 5: add r2,r2,r1
// 6:bner0 r1，4
// 7:out  
// 8:bnere r3,7

// Regs:  R[0-3]  00 01 10 11
//  00 rd rs1 rs2    add 指令        add
//  10 rd imm        R[rd]=imm       li
//  11 addr   rs2    bner0           bner0
//  01                               out  

void init_Mem() {
    M[0] = 0b10001010,M[1] = 0b10010000,M[2] = 0b10100000,M[3] = 0b10110001,
    M[4] = 0b00010111,M[5] = 0b00101001,M[6] = 0b11010100,M[7] = 0b01000000,
    M[8] = 0b11111000;
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
        uint8_t reg = (inst >> 4)&(0x03);
        uint8_t newPC = inst &(0xF);
        if (R[0] != R[reg])
            PC = --newPC; 
    } else if (opCode == 0x1) {
        printf("PC:%d\n",PC);
        printf("R[0]:%d\n",R[0]);
        printf("R[1]:%d\n",R[1]);
        printf("R[2]:%d\n",R[2]);
        printf("R[3]:%d\n",R[3]);
    } 
    else 
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