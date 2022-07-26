ENTRY(reset)
MEMORY 
{
	myMem (rwx) : ORIGIN = 0x00000000 , LENGTH = 64M
}

SECTIONS {
	
	. = 0x10000;

	.startup . :
	{
		startup.o(.text)
	}>myMem

	.text :
	{
		*(.text) *(.rodata)
	}>myMem

	.data :
	{
		*(.data)
	}>myMem

	.bss :
	{
		*(.bss) *(comment)

	}>myMem

	. = . + 0x1000;
	stack_top = . ;

}