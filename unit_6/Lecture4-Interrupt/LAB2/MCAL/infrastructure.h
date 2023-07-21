#ifndef _INFRASTRUCTURE_H_
#define _INFRASTRUCTURE_H_
/*-------------------main tools ----------------------*/
#define clear_bit(reg,bit_num)	(reg &=~(1<<bit_num))
#define toggle_bit(reg,bit_num)	(reg ^= 1<<bit_num)
#define read_bit(reg,bit_num)	((reg & (1<<bit_num))>>bit_num)

#endif
