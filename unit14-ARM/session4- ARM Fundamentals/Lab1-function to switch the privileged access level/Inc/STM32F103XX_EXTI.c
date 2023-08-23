#include <Cortex_M3_NVIC.h>
#include <STM32F103XX_EXTI.h>
#include "infrastructure.h"
void Enable_NVIC_Mask(char line_number)
{
	set_bit(NVIC_ISER0,line_number);
}
void disable_NVIC_Mask(char line_number)
{
	clear_bit(NVIC_ISER0,line_number);
}
void Enable_Interrupt_Mask(char line_number)
{
	set_bit(EXTI_IMR,line_number);
}
void Disable_Interrupt_Mask(char line_number)
{
	clear_bit(EXTI_IMR,line_number);
}
void Enable_Event_Mask(char line_number)
{
	set_bit(EXTI_EMR,line_number);
}
void Disable_Event_Mask(char line_number)
{
	clear_bit(EXTI_EMR,line_number);
}
void Enable_Rising_Trigger(char line_number)
{
	set_bit(EXTI_RTSR,line_number);
}
void Disable_Rising_Trigger(char line_number)
{
	clear_bit(EXTI_RTSR,line_number);
}
void Enable_Falling_Trigger(char line_number)
{
	set_bit(EXTI_FTSR,line_number);
}
void Disable_Falling_Trigger(char line_number)
{
	clear_bit(EXTI_FTSR,line_number);
}
void Clear_pending_Trigger(char line_number)
{
	clear_bit(EXTI_PR,line_number);
}
