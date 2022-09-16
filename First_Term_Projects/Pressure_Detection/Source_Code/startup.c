#include <stdint.h>

extern int main(void);

void reset_Handler(void);

void Default_Handler(){

	reset_Handler();
}

void NMI_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void H_fault_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void NM_fault_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void Bus_fault(void)__attribute__((weak,alias ("Default_Handler")));;
void Usage_fault_Handler(void)__attribute__((weak,alias ("Default_Handler")));;


extern unsigned int _stack_top;
uint32_t vectors[] __attribute__((section(".vectors")))  = {

(uint32_t) &_stack_top,
(uint32_t) &reset_Handler,
(uint32_t) &NMI_Handler,
(uint32_t) &H_fault_Handler,
(uint32_t) &NM_fault_Handler,
(uint32_t) &Bus_fault,
(uint32_t) &Usage_fault_Handler

};

extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void reset_Handler(){

	// Copy Data From ROM Ro RAM;
	unsigned int size_data =  (unsigned char*)&_E_data - (unsigned char*)&_S_data;
	unsigned char* src_data   =  (unsigned char*)&_E_text;
	unsigned char* dst_data   =  (unsigned char*)&_S_data;
	for(int i =0 ; i < size_data ; i++){
		*((unsigned char*)dst_data++) = *((unsigned char*)src_data++);
	}

	// initialize bss In RAM With Zero;
	unsigned int size_bss =  (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	dst_data =  (unsigned char*)&_S_bss;
	for(int i =0 ; i < size_bss ; i++){
		*((unsigned char*)dst_data++) = (unsigned char) 0;
	}

	// Jump To main
	main();
}
