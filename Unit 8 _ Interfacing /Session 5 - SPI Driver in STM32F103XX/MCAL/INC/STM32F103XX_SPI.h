/*
 * STM32F103XX_SPI.h
 *
 *  Created on: Nov 24, 2023
 *      Author: Mahmoud Hussein
 */

#ifndef INC_STM32F103XX_SPI_H_
#define INC_STM32F103XX_SPI_H_
#include "std_typedef.h"
#include "STM32F103XX.h"
/***********************************************************
 ------------------------references-------------------------
 ***********************************************************/
//@ref SPI_NUM_ref
#define SPI_1			0
#define SPI_2			1
//@ref SPI_slave_select_mode
#define SPI_SW_Mode		0
#define SPI_HW_Mode		1
//@ref Master_Enable
#define SPI_Master_Disable		0
#define SPI_Master_Enable		1

/***********************************************************
 ---------------Configurations and Registers---------------
 ***********************************************************/
typedef struct
{
	uint32_t SPI_num; //choose between SPI0 or SPI1    @ref SPI_NUM_ref
	uint32_t SPI_mode;
	uint32_t master_enable;
	uint32_t baud_rate_select;
	uint32_t slave_select_mode;
	uint8_t clock_polarity;
	uint8_t clock_phase;
	uint8_t data_size;
	uint8_t frame_format;
	uint8_t interrupt_enable;
	void (*SPI_callback)();
}SPI_Config_t;
typedef struct
{
	uint32_t SPI_CR1;
	uint32_t SPI_CR2;
	uint32_t SPI_SR;
	uint16_t SPI_DR;
}SPI_typedef;
/***********************************************************
 --------------------Peripheral instants-------------------
 ***********************************************************/
#define SPI_1_P  ((SPI_typedef *) SPI1_base_address)
#define SPI_2_P  ((SPI_typedef *) SPI2_base_address)
/***********************************************************
 ---------------------------APIs----------------------------
 ***********************************************************/
void SPI_init(SPI_Config_t* SPI_config);
void SPI_deinit(SPI_Config_t* SPI_config);
void SPI_send_data(SPI_Config_t* SPI_config, uint16_t data);
void SPI_recevie_data(SPI_Config_t* SPI_config, uint16_t* data);

#endif /* INC_STM32F103XX_SPI_H_ */
