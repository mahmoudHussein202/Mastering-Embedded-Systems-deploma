extern void main();
extern unsigned int _stack_pointer;
extern unsigned int E_TEXT;
extern unsigned int S_DATA;
extern unsigned int E_DATA;
extern unsigned int S_BSS;
extern unsigned int E_BSS;
typedef volatile unsigned int vuint32_t;
typedef unsigned int uint32_t;
void _reset_handler();
void _vector_handler() __attribute__((weak,alias("_reset_handler")));


uint32_t vector_table[] __attribute__((section(".vectors"))) = {
	(uint32_t)	&_stack_pointer,
	(uint32_t)	_reset_handler,
	(uint32_t)	_vector_handler
};


void _reset_handler()
{
	/*copy data section from rom to ram*/
	unsigned volatile char* p_src = (unsigned char*)&E_TEXT;
	unsigned volatile char* p_dst = (unsigned char)&S_DATA;
	uint32_t DATA_SIZE = (uint32_t)&E_DATA - (uint32_t)&S_DATA;

	for (int i = 0 ; i <DATA_SIZE ; i++){
		*(p_dst++) = * (p_src++);
	}

	/* initialize .bss section with zeros */
	p_src = (unsigned char*)&S_BSS;
	uint32_t BSS_SIZE = (uint32_t)&E_BSS - (uint32_t)&S_BSS;

	for (int i = 0 ; i < BSS_SIZE ; i++ )
	{
		*(p_src ++ ) = 0 ;
	}

	main();
}
