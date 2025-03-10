
prog:     file format elf64-littleriscv


Disassembly of section .text:

0000000000000000 <_start>:
   0:	4501                	c.li	a0,0
   2:	04100593          	addi	a1,zero,65
   6:	9002                	c.ebreak
   8:	4505                	c.li	a0,1
   a:	4581                	c.li	a1,0
   c:	9002                	c.ebreak
   e:	a001                	c.j	e <_start+0xe>
