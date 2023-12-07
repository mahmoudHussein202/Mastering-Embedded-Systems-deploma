/*
 * Stm32F103XX_SPI.c
 *
 *  Created on: Nov 24, 2023
 *      Author: Mahmoud Hussein
 */
#include "STM32F103XX.h"
#include "STM32F103XX_SPI.h"
#include "STM32F103XX_RCC.h"
#include "STM32F103XX_GPIO.h"
#include "peripherals_interfaces.h"
uint16_t*	user_data_address;
void SPI_init(SPI_Config_t* SPI_config)
{
	/*[1] clock enable
	 -------------------*/
	if (SPI_config->SPI_num == SPI_1)
		RCC_SPI1_clk_EN;
	else if (SPI_config->SPI_num == SPI_2)
		RCC_SPI2_clk_EN;

	/*[2] configure the pins
	 ------------------------*/
	if (SPI_config->SPI_num == SPI_1)
	{
		//[a]SCK
		if (SPI_config->master_enable == SPI_Master_Enable)
			GPIO_set_pin_mode(GPIO_A, 5, GPIO_Mode_outout_10MHZ, AFIO_Mode_push_pull);
		else if (SPI_config->master_enable == SPI_Master_Disable)
			GPIO_set_pin_mode(GPIO_A, 5, GPIO_input_mode, GPIO_Mode_Floating);
		//[b]MISO
		if (SPI_config->master_enable == SPI_Master_Enable)
			GPIO_set_pin_mode(GPIO_A, 6, GPIO_input_mode, GPIO_Mode_Floating);
		else if (SPI_config->master_enable == SPI_Master_Disable)
			GPIO_set_pin_mode(GPIO_A, 6, GPIO_Mode_outout_10MHZ, AFIO_Mode_push_pull); // in point to point slave
		//[c]MOSI
		if (SPI_config->master_enable == SPI_Master_Enable)
			GPIO_set_pin_mode(GPIO_A, 7, GPIO_Mode_outout_10MHZ, AFIO_Mode_push_pull);
		else if (SPI_config->master_enable == SPI_Master_Disable)
			GPIO_set_pin_mode(GPIO_A, 7, GPIO_input_mode, GPIO_Mode_Floating); // in point to point slave
		//[d]SCK
		if (SPI_config->slave_select_mode == SPI_SW_Mode)
		{
			// NSS is not used so no action needed
		}
		else
		{
			// further implementation for the Hardware NSS
		}
	}
	else if  (SPI_config->SPI_num == SPI_2)
	{
		//[a]SCK
		if (SPI_config->master_enable == SPI_Master_Enable)
			GPIO_set_pin_mode(GPIO_B, 13, GPIO_Mode_outout_10MHZ, AFIO_Mode_push_pull);
		else if (SPI_config->master_enable == SPI_Master_Disable)
			GPIO_set_pin_mode(GPIO_B, 13, GPIO_input_mode, GPIO_Mode_Floating);
		//[b]MISO
		if (SPI_config->master_enable == SPI_Master_Enable)
			GPIO_set_pin_mode(GPIO_B, 14, GPIO_input_mode, GPIO_Mode_Floating);
		else if (SPI_config->master_enable == SPI_Master_Disable)
			GPIO_set_pin_mode(GPIO_B, 14, GPIO_Mode_outout_10MHZ, AFIO_Mode_push_pull); // in point to point slave
		//[c]MOSI
		if (SPI_config->master_enable == SPI_Master_Enable)
			GPIO_set_pin_mode(GPIO_B, 15, GPIO_Mode_outout_10MHZ, AFIO_Mode_push_pull);
		else if (SPI_config->master_enable == SPI_Master_Disable)
			GPIO_set_pin_mode(GPIO_B, 15, GPIO_input_mode, GPIO_Mode_Floating); // in point to point slave
		//[d]SCK
		if (SPI_config->slave_select_mode == SPI_SW_Mode)
		{
			// NSS is not used so no action needed
		}
		else
		{
			// further implementation for the Hardware NSS
		}
	}
	/*[3]Enable the SPI
	 --------------------*/
	SPI_config->SPI_num->SPI_CR1|=1<<6;

	/*[4]Select Master or slave
	 *--------------------------*/
	if (SPI_config->master_enable == SPI_Master_Enable)
		SPI_config->SPI_num->SPI_CR1 |= 1<<2 ;
	else if  (SPI_config->master_enable == SPI_Master_Disable)
		SPI_config->SPI_num->SPI_CR1 &= ~(1<<2) ;
	/*[5] enable interrupt ( NVIC and Module )
	 -------------------------------------------*/

	/*[6] set the controls from the SPI_config
	 ------------------------------------------*/
		//[a]clock_phase
	if(SPI_config->clock_phase == SPI_CLK_first_edge)
		SPI_config->SPI_num->SPI_CR1 &=~(1<<0);
	else if (SPI_config->clock_phase == SPI_CLK_second_edge)
		SPI_config->SPI_num->SPI_CR1 |= (1<<0);
		//[b]clock_Polarity
	if(SPI_config->clock_polarity == SPI_CLK_idle_low)
		SPI_config->SPI_num->SPI_CR1 &=~(1<<1);
	else if (SPI_config->clock_polarity == SPI_CLK_idle_high)
		SPI_config->SPI_num->SPI_CR1 |= (1<<1);
		//[c] Baudrate
	set_bits_once(SPI_config->SPI_num->SPI_CR1,3,SPI_config->baud_rate_select);
		//[d] Data_size
	if (SPI_config->data_size == SPI_8_bit_data)
		set_bit(&(SPI_config->SPI_num->SPI_CR1),8);
	else if (SPI_config->data_size == SPI_16_bit_data)
		clear_bit(&(SPI_config->SPI_num->SPI_CR1),8);
		//[E] Frame_Format
	if (SPI_config->frame_format == SPI_LSB_transmitted_first)
		set_bit(&(SPI_config->SPI_num->SPI_CR1),7);
	else if (SPI_config->data_size == SPI_MSB_transmitted_first)
		clear_bit(&(SPI_config->SPI_num->SPI_CR1),7);
		//[F] Interrupt_Enable
			//-----------------NVIC-------------------

			//----------------from SPI module --------
	if (SPI_config->transmit_interrupt_enable == SPI_TXEIE_Enable)
		set_bit(&(SPI_config->SPI_num->SPI_CR2),7);
	if (SPI_config->transmit_interrupt_enable == SPI_RXNEIE_Enable)
		set_bit(&(SPI_config->SPI_num->SPI_CR2),6);

}

void SPI_send_data(SPI_Config_t* SPI_config, uint16_t data)
{
	SPI_config->SPI_num->SPI_DR = data;
	if(SPI_config->polling_enable == SPI_Polling_Enable)
		while((SPI_config->SPI_num->SPI_SR)&(1<<1)>>1);
}
void SPI_recevie_data(SPI_Config_t* SPI_config, uint16_t* data)
{
	if(SPI_config->polling_enable == SPI_Polling_Enable)
	{
		while((SPI_config->SPI_num->SPI_SR)&(1<<0)>>0);
		*data = SPI_config->SPI_num->SPI_DR ;
	}
	else
		user_data_address = data;		// recieve call back will save the value in this variable
}

