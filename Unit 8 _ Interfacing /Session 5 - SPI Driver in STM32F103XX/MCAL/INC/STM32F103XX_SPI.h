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
//@ref SPI_slave_select_mode
#define SPI_SW_Mode						0
#define SPI_HW_Mode						1
//@ref Master_Enable
#define SPI_Master_Disable				0
#define SPI_Master_Enable				1
//@ref SPI_Clock_phase
#define SPI_CLK_first_edge				0
#define SPI_CLK_second_edge				1
//@ref SPI_Clock_Polarity
#define SPI_CLK_idle_low				0
#define SPI_CLK_idle_high				1
//@ref SPI_Baud_Rate_Control
//@ref SPI_Clock_Polarity
#define SPI_8_bit_data					0
#define SPI_16_bit_data					1
//@ref SPI_Frame_format
#define SPI_MSB_transmitted_first		0
#define SPI_LSB_transmitted_first		1
//@ref SPI_Interrupt_Enable
#define SPI_TXEIE_Enable				0xA
#define SPI_RXNEIE_Enable				0xB
//@ref SPI_Polling_Enable
#define SPI_Polling_Enable				0xC
#define SPI_Polling_Disable				0xD
//@ref SPI_Clock_Polarity
#define  fPCLK_2						0b000
#define  fPCLK_4						0b001
#define  fPCLK_8						0b010
#define  fPCLK_16						0b011
#define  fPCLK_32						0b100
#define  fPCLK_64						0b101
#define  fPCLK_128						0b110
#define  fPCLK_256						0b111
/***********************************************************
 ---------------Configurations and Registers---------------
 ***********************************************************/
typedef struct
{
	uint32_t SPI_CR1;
	uint32_t SPI_CR2;
	uint32_t SPI_SR;
	uint16_t SPI_DR;
}SPI_typedef;
typedef struct
{
	SPI_typedef* SPI_num; 					//choose between SPI0 or SPI1    @ref SPI_NUM_ref
	uint32_t SPI_mode;
	uint32_t master_enable;					//@ref Master_Enable
	uint32_t baud_rate_select;				//@ref SPI_Baud_Rate_Control
	uint32_t slave_select_mode;				//@ref SPI_slave_select_mode
	uint8_t clock_polarity; 				//@ref SPI_Clock_Polarity
	uint8_t clock_phase;					//@ref SPI_Clock_phase
	uint8_t data_size;						//@ref SPI_Data_size
	uint8_t frame_format;					//@ref SPI_Frame_format
	uint8_t polling_enable;					//@ref SPI_Polling_Enable
	uint8_t transmit_interrupt_enable;		//@ref SPI_Interrupt_Enable
	uint8_t recevie_interrupt_enable;		//@ref SPI_Interrupt_Enable
	void (*SPI_callback)();
}SPI_Config_t;

/***********************************************************
 --------------------Peripheral instants-------------------
 ***********************************************************/
//@ref SPI_NUM_ref
#define SPI_1  ((SPI_typedef *) SPI1_base_address)
#define SPI_2  ((SPI_typedef *) SPI2_base_address)
/***********************************************************
 ---------------------------APIs----------------------------
 ***********************************************************/
void SPI_init(SPI_Config_t* SPI_config);
void SPI_deinit(SPI_Config_t* SPI_config);
void SPI_send_data(SPI_Config_t* SPI_config, uint16_t data);
void SPI_recevie_data(SPI_Config_t* SPI_config, uint16_t* data);

#endif /* INC_STM32F103XX_SPI_H_ */
