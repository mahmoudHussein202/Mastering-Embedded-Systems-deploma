extern void main();
extern int _stack_pointer;
void _reset_handler();


typedef volatile unsigned int vuint32_t


vuint32_t vector_table[] __attribute__((section(".vector"))) {
	&_stack_pointer,
	_reset_handler,
	_vector_handler
};


void _reset_handler()
{
	main();
}

void _vector_handler()
{
	_reset_handler();
}