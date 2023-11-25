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
	if (SPI_config->SPI_num == SPI_1)
		SPI_1_P->SPI_CR1 |= 1<<6;
	else if (SPI_config->SPI_num == SPI_2)
		SPI_2_P->SPI_CR1 |= 1<<6;

	/*[4] enable interrupt ( NVIC and Module )
	 -------------------------------------------*/

	/*[5] set the controls from the SPI_config
	 ------------------------------------------*/
	if (SPI_config->SPI_num == SPI_1)
	{

	}
}
