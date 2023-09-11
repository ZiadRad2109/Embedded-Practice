ENTRY(reset) 
MEMORY
{
AY_ESM (rwx): ORIGIN =0x00000000 , LENGTH = 64M
}


SECTIONS
{
	.startup :
	{
		startup.o(.text)
	}
	.text :
	{
		*(.text)
	}
	.data :
	{
		*(.data)
	}
	.bss :
	{
		*(.bss)
	}
}
