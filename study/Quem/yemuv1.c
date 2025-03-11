#include <stdbool.h>
#include<stdint.h>
#include<stdio.h>
uint32_t R[32],PC;
/// @brief  M[64] 模拟的是内存，里面存储的是二进制指令

// 00000000 <_start>:
//    0:   00000513  addi    a0,zero,0
//    4:   04100593  addi    a1,zero,65
//    8:   00100073  ebreak
//    c:   00100513  addi    a0,zero,1
//   10:   00000593  addi    a1,zero,0
//   14:   00100073  ebreak
//   18:   0000006f  jal     zero,18 <_start+0x18>

uint8_t M[64] = {
    0x13,0x05,0x00,0x00,0x93,0x05,0x10, 0x04, 0x73, 0x00, 0x10, 0x00,
    0x13, 0x05, 0x10, 0x00, 0x93, 0x05, 0x00, 0x00, 0x73, 0x00, 0x10, 0x00,
    0x6f, 0x00, 0x00, 0x00,
};
bool halt = false;
///                           & 0x7f  111 1111 同为1才为1，其余为0
///  addi    imm  rs1 000 rd 0010011
///  break   0000 0000 0001     0000 0     000     0000 0     111 0011
void inst_cycle(){
    uint32_t inst = *(uint32_t*)&M[PC];
    if(((inst & 0x7f) == 0x13) && (((inst>>12)&0x7)==0)) 
    {
        if(((inst>>7)& 0x1f)!=0) {
            R[(inst >> 7)& 0x1f] = R[(inst>>15)& 0x1f] +
            (((inst>>20)& 0x7ff) - ((inst & 0x80000000)? 4096 :0));
        }
    }
    else if(inst == 0x00100073)//break
    {
        
    }
    else {printf("Unsupported instuction\n");}
}

int main(){
    PC = 0; R[0] = 0;
    while(!halt) {inst_cycle();}
    return 0;
}