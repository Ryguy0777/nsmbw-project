ENTRY(_prolog)

SECTIONS {
	.text : {
		*(.text*)
		KEEP(*(replaced))
		KEEP(*(extern))
	}

	.data : {
        . = ALIGN(4);
        _replarray = .;
        KEEP(*(replace_array))
        _replarray_end = .;

        . = ALIGN(4);
        _replrelarray = .;
        KEEP(*(replace_data_array))
        _replrelarray_end = .;

        . = ALIGN(4);
        _replinsertarray = .;
        KEEP(*(.replinsertarray))
        _replinsertarray_end = .;

        . = ALIGN(4);
        _externarray = .;
        KEEP(*(extern_array))
        _externarray_end = .;

        *(.rodata*)

        . = ALIGN(4);
		*(.data*)
		*(.sdata*)
		*(.sdata2*)

		. = ALIGN(4);
		_ctors = .;
		*(.ctors)
		*(.init_array)
		_ctors_end = .;
	}

	.bss : {
		*(.bss*)
		*(.sbss*)
	}
}
