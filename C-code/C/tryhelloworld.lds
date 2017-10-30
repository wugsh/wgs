ENTRY(nomain)
	SECTIONS
{
	. = 0x080480000 +SIZEOF_HEADERS;
	tinytext : {*(.text) *(.data) *(.rodata)}
	/DISCARD/ : {*(.comment)}
}
