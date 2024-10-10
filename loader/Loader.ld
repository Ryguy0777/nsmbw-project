ENTRY(LoaderMain)

SECTIONS {
    . = 0x800047E4;
    .text : {
        *(.start)
        *(.text*)
        *(.rodata*)
        *(.data*)
        *(.sdata*)
        *(.bss*)
    }
}
