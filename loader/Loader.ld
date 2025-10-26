ENTRY(LoaderMain)

SECTIONS {
    . = 0x800047E0;
    .text : {
        *(start)
        *(.text*)
        *(.rodata*)
        *(.data*)
        *(.sdata*)
        *(.bss*)
        *(.sbss*)
    }
}
