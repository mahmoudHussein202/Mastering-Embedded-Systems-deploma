#ifndef _STM32F103XX_EXTI_H_
#define _STM32F103XX_EXTI_H_
/*-------------------registers ----------------------*/
#define EXTI_base   0x40010400
#define EXTI_IMR     *((volatile unsigned int*)(EXTI_base+0x00))
#define EXTI_EMR     *((volatile unsigned int*)(EXTI_base+0x04))
#define EXTI_RTSR    *((volatile unsigned int*)(EXTI_base+0x08))
#define EXTI_FTSR    *((volatile unsigned int*)(EXTI_base+0x0C))
#define EXTI_SWIER   *((volatile unsigned int*)(EXTI_base+0x010))
#define EXTI_PR      *((volatile unsigned int*)(EXTI_base+0x14))
#define set_bit(reg,bit_num)	(reg|=1<<bit_num)
/*-------------------APIs ----------------------*/
void Enable_NVIC_Mask(char line_number);
void disable_NVIC_Mask(char line_number);
void Enable_Interrupt_Mask(char line_number);
void Disable_Interrupt_Mask(char line_number);
void Enable_Event_Mask(char line_number);
void Disable_Event_Mask(char line_number);
void Enable_Rising_Trigger(char line_number);
void Disable_Rising_Trigger(char line_number);
void Enable_Falling_Trigger(char line_number);
void Disable_Rising_Trigger(char line_number);
void Clear_pending_Trigger(char line_number);
#endif
