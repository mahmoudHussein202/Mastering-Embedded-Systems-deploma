/*
 * Stm32_F103C6_RCC_Driver.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Wessam
 */

#ifndef INC_STM32_F103C6_USART_DRIVER_H_
#define INC_STM32_F103C6_USART_DRIVER_H_

#include "Stm32_F103C6.h"
#include "Stm32_F103C6_GPIO_Driver.h"
#include "Stm32_F103C6_RCC_Driver.h"

//Configuration structure
typedef struct
{
	uint8_t			USART_Mode;		 	 //specifies TX/RX Enabe/Disable
								   	    //this parameter must be set based on @ref UART_Mode_define

	uint32_t		BaudRate;		    //this member configures the UART communication baudrate
									   //this parameter must be set based on @ref UART_Mode_define

	uint8_t			Payload_Length;	   //specifies the number of data bits transmitted or received in a frame
								      //this parameter must be set based on @ref UART_Payload_Length_define

	uint8_t			Parity;	    	   //specifies the parity mode
								      //this parameter must be set based on @ref UART_Parity_define

	uint8_t			StopBits;         //specifies the number of stop bits transmitted
								     //this parameter must be set based on @ref UART_StopBits_define

	uint8_t			HwFlowCtl;	     //specifies whether the hardware flow control mode is enabled or disabled
								    //this parameter must be set based on @ref UART_HwFlowCtl_define

	uint8_t			IRQ_Enable;     //enable or disable UART IRQ TX/RX
							       //@ref UART_IRQ_Enable_define, you can select more than 1, ex:UART_IRQ_Enable_TXE | UART_IRQ_Enable_TC

	void(* P_IRQ_CallBack)(void);  //set the C Function() which will be called once the IRQ happen
}UART_Config;



//------------------------------------------------------------------
//************************ Refrence Macros *************************
//------------------------------------------------------------------

#define USART_Enable 							(uint32_t)(1<<13)
//@ref UART_Mode_define

#define UART_Mode_RX							(uint32_t)(1<<2)
#define UART_Mode_TX							(uint32_t)(1<<3)
#define UART_Mode_TX_RX							((uint32_t)(1<<2 | 1<<3))

//@ref UART_BaudRate_define

#define UART_BaudRate_2400						2400
#define UART_BaudRate_9600						9600
#define UART_BaudRate_19200						19200
#define UART_BaudRate_57600						57600
#define UART_BaudRate_115200					115200
#define UART_BaudRate_230400					230400
#define UART_BaudRate_460800					460800
#define UART_BaudRate_921600					921600
#define UART_BaudRate_2250000					2250000
#define UART_BaudRate_4500000					4500000

//@ref UART_Payload_Length_define

#define UART_Payload_Length_8B					(uint32_t)(0)
#define UART_Payload_Length_9B					((uint32_t)(1<<12))

//@ref UART_Parity_define

#define UART_Parity_NONE						(uint32_t)(0)
#define UART_Parity_EVEN						((uint32_t)(1<<10))
#define UART_Parity_ODD							((uint32_t)(1<<10 | 1<<9))

//@ref UART_StopBits_define

#define UART_StopBits_half						((uint32_t)(1<<12))
#define UART_StopBits_1							((uint32_t)(0))
#define UART_StopBits_1_half					((uint32_t)(3<<12))
#define UART_StopBits_2							((uint32_t)(2<<12))

//@ref UART_HwFlowCtl_define

#define UART_HwFlowCtl_NONE						((uint32_t)(0))
#define UART_HwFlowCtl_RTS						((uint32_t)(1<<8))
#define UART_HwFlowCtl_CTS						((uint32_t)(1<<9))
#define UART_HwFlowCtl_RTS_CTS					((uint32_t)(1<<8 | 1<<9))


//@ref UART_IRQ_Enable_define
#define UART_IRQ_Enable_NONE					((uint32_t)(0))
#define UART_IRQ_Enable_TXE						((uint32_t)(1<<7)) //Transmit data register empty
#define UART_IRQ_Enable_TC						((uint32_t)(1<<6)) // Transmission complete
#define UART_IRQ_Enable_RXNEIE					((uint32_t)(1<<5))	//Received data ready to be read
#define UART_IRQ_Enable_PE						((uint32_t)(1<<8)) //Parity error


enum Polling_mechism{
	enable,
	disable
};

//BaudRate Calculation
//USARTDIV = fclk / (16*Baudrate)
//USARTDIV_MUL100 = uint32((100*fclk) / (16*Baudrate) == (25*fclk) / (4*Baudrate))
//DIV_Mantissa_MUL100 = Integer Part (USARTDIV) * 100
//DIV_Mantissa = Integer Part (USARTDIV)
//DIV_Fraction = ((  USARTDIV_MUL100 - DIV_Mantissa_MUL100 ) *16)/100

#define USARTDIV(_PCLK_,_BAUD_) 				(uint32_t) (_PCLK_/(16*_BAUD_))
#define USARTDIV_MUL100(_PCLK_,_BAUD_) 			(uint32_t) ((25*_PCLK_) / (4*_BAUD_))
#define Mantissa_MUL100(_PCLK_,_BAUD_) 			(uint32_t) (USARTDIV(_PCLK_,_BAUD_) * 100)
#define Mantissa(_PCLK_,_BAUD_) 				(uint32_t) (USARTDIV(_PCLK_,_BAUD_))
#define DIV_Fraction(_PCLK_,_BAUD_) 			(uint32_t) (((USARTDIV_MUL100(_PCLK_,_BAUD_) - Mantissa_MUL100(_PCLK_,_BAUD_) ) *16) /100)
#define UART_BRR_Register(_PCLK_,_BAUD_)		(( Mantissa(_PCLK_,_BAUD_) ) <<4)|( (DIV_Fraction(_PCLK_,_BAUD_)) &0xF)







/*
 * =============================================================================================
 * 										APIs Supported by "MCAL GPIO DRIVER"
 * =============================================================================================
 */

void MCAL_UART_Init(USART_TypeDef* USARTx, UART_Config* UART_Config);
void MCAL_UART_DeInit(USART_TypeDef* USARTx);

void MCAL_UART_GPIO_Set_Pins(USART_TypeDef* USARTx);

void MCAL_UART_SendData(USART_TypeDef* USARTx, uint16_t* pTxBuffer, enum Polling_mechism PollingEn);
void MCAL_UART_ReceiveData(USART_TypeDef* USARTx, uint16_t* pTxBuffer, enum Polling_mechism PollingEn);

void MCAL_UART_WAIT_TC(USART_TypeDef* USARTx);

//todo MCAL_USART_LIN_Init()			LIN
//todo MCAL_USART_Init()				Synchronous
//todo MCAL_USART_DMA_Init()			Multibuffer communication


#endif /* INC_STM32_F103C6_USART_DRIVER_H_ */
