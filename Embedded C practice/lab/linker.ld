ENTRY(reset) 
MEMORY
{
AY_ESM (rwx): ORIGIN =0x00000000 , LENGTH = 64M
}


SECTIONS
{
	. = 0x10000;
	.startup . :
	{
		startup.o(.text)
	}> AY_ESM
	.text :
	{
		*(.text) *(.rodata)
	}> AY_ESM
	.data :
	{
		*(.data)
	}> AY_ESM
	.bss :
	{
		*(.bss) *(COMMON)
	}> AY_ESM
	. = . + 0x1000;
	stack_top = . ;
}
