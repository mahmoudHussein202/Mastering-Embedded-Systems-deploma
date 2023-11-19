/*
 * Stm32_F103C6_SPI_Driver.h
 *
 *  Created on: Sep 10, 2023
 *      Author: Wessam
 */

#ifndef INC_STM32_F103C6_SPI_DRIVER_H_
#define INC_STM32_F103C6_SPI_DRIVER_H_

//includes
#include "Stm32_F103C6.h"
#include "Stm32_F103C6_GPIO_Driver.h"

struct S_IRQ_SRC
{
	uint8_t TXE:1;	//TX buffer empty interrupt
	uint8_t RXNE:1;	//RX buffer not empty interrupt
	uint8_t ERRI:1;	//Error interrupt
	uint8_t Reserved:5;

};
//Configuration structure
typedef struct
{
	uint16_t	Device_Mode;							//specifies the SPI operating mode @ref SPI_Device_Mode
	uint16_t	Communication_Mode; 					//specifies the SPI bidirectional mode state @ref SPI_Communication_Mode
	uint16_t	Frame_Format;							//specifies LSB or MSB @ref SPI_Frame_Format
	uint16_t	DataSize;								//@ref SPI_DataSize
	uint16_t	CLKPolarity;							//@ref SPI_CLKPolarity
	uint16_t	CLKPhase;								//@ref SPI_CLKPhase
	uint16_t	NSS;									//specifies whether the NSS signal is managed by HW Pin or by SW (using SSI), @ref SPI_NSS
	uint16_t	BaudratePrescaler;						//specifies the baudrate prescaler value which will be used to configure the transmit
														//recevie SCK clock, this parameter set by @ref SPI_BaudratePrescaler
														//the communication clock is derived from the master clock
	uint16_t	IRQ_Enable;								//@ref SPI_IRQ_Enable
	void (*P_IRQ_CallBack)(struct S_IRQ_SRC irq_src);	//set the C Function which will be called once IRQ happen
}SPI_Config;


//------------------------------------------------------------------------------------------------------------------------

//@ref SPI_Device_Mode
#define SPI_Device_Mode_SLAVE				(0x00000000U)
#define SPI_Device_Mode_MASTER				(0x1U<<2) //CR1.MSTR: 1: Master Configuration

//@ref SPI_Communication_Mode
#define SPI_DIRECTION_2LINES				(0x00000000U)
#define SPI_DIRECTION_2LINES_RXONLY			(0x1U<<10)//CR1.Bit 10 RXONLY: Receive only
#define SPI_DIRECTION_1LINES_Receive		(0x1U<<15)//CR1.Bit 15 BIDIMODE: bidirectional data mode enable
#define SPI_DIRECTION_1LINES_Transmit		((0x1U<<15)|(0x1U<<14))//CR1.Bit 15 BIDIMODE: bidirectional data mode enable & Bit 14 BIDIOE: output enable in bidirectional

//@ref SPI_DataSize
#define SPI_DataSize_8BIT					(0x00000000U)
#define SPI_DataSize_16BIT					(0x1U<<11)//CR1. Bit:11 DFF: Data frame format

//@ref SPI_Frame_Format
#define SPI_Frame_Format_MSB_First			(0x00000000U)
#define SPI_Frame_Format_LSB_First 			(0x1U<<7)//Bit 7 LSBFIRST: Frame format

//@ref SPI_CLKPolarity
#define SPI_CLKPolarity_Idle_lOW			(0x00000000U)
#define SPI_CLKPolarity_Idle_HIGH			(0x1U<<1)//Bit1 CPOL: clock polarity

//@ref SPI_CLKPhase
#define SPI_Clock_Phase_1EDGE_Sampling		(0x00000000U)
#define SPI_Clock_Phase_2EDGE_Sampling		(0x1U<<0)//Bit 0 CPHA: clock phase

//===================================NSS===================================
//@ref SPI_NSS
//Hardware
#define SPI_NSS_Hard_Slave					(0x00000000U)
#define SPI_NSS_Hard_Master_SS_OP_Enable	(0x1U<<2) //CR2 Bit 2 SSOE: SS output enable
#define SPI_NSS_Hard_Master_SS_OP_Disable	~(0x1U<<2) //CR2 Bit 2 SSOE: SS output disable

//Software (Master or Slave)
#define SPI_NSS_Soft_NSSInternalSoft_Reset	(0x1U<<9)
#define SPI_NSS_Soft_NSSInternalSoft_Set	((0x1U<<9) | (0x1U<<8))


//@ref SPI_BaudratePrescaler
#define SPI_BaudratePrescaler_2				(0x00000000U)
#define SPI_BaudratePrescaler_4				(0b001U << 3)
#define SPI_BaudratePrescaler_8				(0b010U << 3)
#define SPI_BaudratePrescaler_16			(0b011U << 3)
#define SPI_BaudratePrescaler_32			(0b100U << 3)
#define SPI_BaudratePrescaler_64			(0b101U << 3)
#define SPI_BaudratePrescaler_128			(0b110U << 3)
#define SPI_BaudratePrescaler_256			(0b111U << 3)

//@ref SPI_IRQ_Enable
#define SPI_IRQ_Enable_NONE					(uint32_t)(0)
#define SPI_IRQ_Enable_TXEIE				(uint32_t)(1<<7) // CR2 Bit 7 TXEIE: Tx buffer empty interrupt enable
#define SPI_IRQ_Enable_RXNEIE				(uint32_t)(1<<6) // CR2 Bit 6 RXNEIE: Rx buffer not empty interrupt enable
#define SPI_IRQ_Enable_ERRIE				(uint32_t)(1<<5) // CR2 Bit 5 ERRIE: Error interrupt enable


enum Polling_Mechism{
	Enable,
	Disable
};

/*
 * =============================================================================================
 * 										APIs Supported by "MCAL GPIO DRIVER"
 * =============================================================================================
 */

void MCAL_SPI_Init(SPI_TypeDef* SPIx, SPI_Config* SPI_Config);
void MCAL_SPI_DeInit(SPI_TypeDef* SPIx);

void MCAL_SPI_GPIO_Set_Pins(SPI_TypeDef* SPIx);

void MCAL_SPI_SendData(SPI_TypeDef* SPIx, uint16_t* pTxBuffer,enum Polling_Mechism PollingEn);
void MCAL_SPI_ReceiveData(SPI_TypeDef* SPIx, uint16_t* pRxBuffer,enum Polling_Mechism PollingEn);

void MCAL_SPI_TX_RX(SPI_TypeDef* SPIx, uint16_t* pTxBuffer,enum Polling_Mechism PollingEn);






#endif /* INC_STM32_F103C6_SPI_DRIVER_H_ */



