OUTPUT_ARCH(riscv)
ENTRY(main)

SECTIONS {
    . = 0x80000000; /* QEMU virt 机器的 RAM 起始地址 */
    
    .text : {
        *(.text*)
    }

    .data : {
        *(.data*)
    }

    .bss : {
        *(.bss*)
    }
}
