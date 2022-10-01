#include <stdint.h>
extern void main () ;
void Reset_Handler (void) ;
void Default_Handler () ;
void NMI_Handrer () __attribute__((weak,alias("Default_Handler")));;
void H_fault_Handler () __attribute__((weak,alias("Default_Handler")));;

static unsigned long _bss[256];

 void (* ptr_vectors[])() __attribute__((section(".vectors")))=
 {
	(void(*)())  ( (unsigned int)&_bss + (unsigned int)sizeof(_bss) ),
	&Reset_Handler,
	&NMI_Handrer,
	&H_fault_Handler 
 } ;

extern unsigned long _S_Data;
extern unsigned long _E_Data;
extern unsigned long _S_bss;
extern unsigned long _E_bss;
extern unsigned long _E_text;


void Reset_Handler (void)
{
	int i;
	/* copy data from ROM to RAM */
	unsigned long Data_size = (unsigned long)&_E_Data - (unsigned long)&_S_Data;

	unsigned char* p_src = (unsigned char*) &_E_text;
	unsigned char* p_dst = (unsigned char*) &_S_Data;

	for (i=0 ; i<Data_size ; i++)
	{
		*p_dst++ = *p_src++ ;
	}	

	/* making the bss in ram */ 

	unsigned long bss_size = (unsigned long)&_E_bss - (unsigned long)&_S_bss ; 

	p_dst = (unsigned char*) &_S_bss ;

	for (i=0 ; i<bss_size ; i++ )
	{
		*p_dst++ = 0 ;  
	}

	
	/* jump to main */ 
	main();
}

void Default_Handler () {
	Reset_Handler() ;

}

