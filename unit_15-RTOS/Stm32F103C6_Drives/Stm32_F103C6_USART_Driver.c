/*
 * Stm32_F103C6_RCC_Driver.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Wessam
 */

#include "Stm32_F103C6_USART_Driver.h"


/*
 * ==========================================================================================
 * 									Generic Variables
 * ==========================================================================================
 */

UART_Config* Global_UART_Config = NULL;

/*
 * ==========================================================================================
 * 									APIs
 * ==========================================================================================
 */
/**==============================================================================
 * @Fn				-MCAL_UART_Init
 * @brief			-Initializes USART (supported feature ASYNCH. ONLY)
 * @param [in]		-USARTx: where x can be (1..3 depending on device used)
 * @param [in]		-UART_Config: All UART Configuration UART_Config
 * @retval			-none
 * Note				-Support for now Asynch mode & Clock 8MHZ
 */

void MCAL_UART_Init(USART_TypeDef* USARTx, UART_Config* UART_Config)
{
	uint32_t pclk,BRR;

	Global_UART_Config = UART_Config;
	//enable the clock for given USART preipheral
	if (USARTx == USART1)
		RCC_USART1_CLK_EN();

	else if (USARTx == USART2)
		RCC_USART2_CLK_EN();

	else if (USARTx == USART3)
		RCC_USART3_CLK_EN();

	//Enable USART Module
	//Bit 13UE: USART enable
	USARTx->CR1 |= USART_Enable;

	//Enable USART TX and RX engines according to the USART_Mode configuration item
	//USART_CR1 Bit 3 TE: Transmitter enable & Bit 2 RE: Receiver enable
	USARTx->CR1 |= UART_Config->USART_Mode;

	//Payload Width
	//Bit 12 M: word length
	USARTx->CR1 |= UART_Config->Payload_Length;

	//configuration of parity control bit fields
	//Bit 10 PCE: Parity control enable, Bit 9 PS:Parity selection
	USARTx->CR1 |= UART_Config->Parity;

	//configure the number of stop bits
	//Bits 13:12 STOP Bits
	USARTx->CR2 |= UART_Config->StopBits;

	//USART hardware flow control
	//Bit 9 CTSE: CTS enable, Bit 8 RTSE: RTS enable
	USARTx->CR3 |= UART_Config->HwFlowCtl;

	//Configuration of BRR(Baudrate register)
	//PCLK1 for USART2,3
	//PCLK2 for USART1

	if (USARTx == USART1)
		pclk = MCAL_RCC_GetPCLK2Freq();
	else
		pclk = MCAL_RCC_GetPCLK1Freq();

	BRR = UART_BRR_Register(pclk, UART_Config->BaudRate);
	USARTx->BRR = BRR;

	//Enable/Disable Interrput
	//USART_CR1
	if(UART_Config->IRQ_Enable != UART_IRQ_Enable_NONE)
	{
		USARTx->CR1 |= (UART_Config->IRQ_Enable);
		//Enable NVIC for USARTx IRQ
		if(USARTx == USART1)
			NVIC_IRQ37_USART1_Enable;
		else if(USARTx == USART2)
			NVIC_IRQ38_USART2_Enable;
		else if(USARTx == USART3)
			NVIC_IRQ39_USART3_Enable;
	}

}


/**==============================================================================
 * @Fn				-MCAL_UART_DeInit
 * @brief			-DeInitializes USART (supported feature ASYNCH. ONLY)
 * @param [in]		-USARTx: where x can be (1..3 depending on device used)
 * @retval			-none
 * Note				-Reset the model by RCC
 */

void MCAL_UART_DeInit(USART_TypeDef* USARTx)
{
	if(USARTx == USART1)
	{
		RCC_USART1_CLK_Reset();
		NVIC_IRQ37_USART1_Disable;
	}
	else if(USARTx == USART2)
	{
		RCC_USART2_CLK_Reset();
		NVIC_IRQ38_USART2_Disable;
	}
	else if(USARTx == USART3)
	{
		RCC_USART3_CLK_Reset();
		NVIC_IRQ39_USART3_Disable;
	}

}

/**==============================================================================
 * @Fn				-MCAL_UART_SendData
 * @brief			-Send Buffer on UART
 * @param [in]		-USARTx: where x can be (1..3 depending on device used)
 * @param [in]		-pTxBuffer Buffer
 * @param [in]		-PollingEn Enable pooling or disable it
 * @retval			-none
 * Note				-Should initialize UART first,  when tansmitting with parity enable
 * 					-(PCE bit ser to 1 in the USART_CR1 register), the value written in
 * 					-the MSB (bit 7 or 8 depending on the data length) has no effect
 * 					-because it's replaced by the parity. when receiving with the parity
 * 					-the value read in MSB bit is the received parity bit.
 */

void MCAL_UART_SendData(USART_TypeDef* USARTx, uint16_t* pTxBuffer, enum Polling_mechism PollingEn)
{
	//wait until TXE flag is set in the SR
	if(PollingEn == enable)
		while(! (USARTx->SR & 1<<7));

	/*check the USART_WordLength item for 9Bit or 8Bit in a frame
	-When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
	-the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect
	-because it is replaced by the parity.
	-When receiving with the parity enabled, the value read in the MSB bit is the received parity
	-bit.*/

	if (Global_UART_Config->Payload_Length == UART_Payload_Length_9B)
	{
		USARTx->DR = (*pTxBuffer & (uint16_t)0x01FF);
	}
	else
	{
		//8 Bit transfer
		USARTx->DR = (*pTxBuffer & (uint8_t)0xFF);
	}

}


void MCAL_UART_WAIT_TC(USART_TypeDef* USARTx)
{
	//wait yill TC flag is set in the SR
	while (! (USARTx->SR & 1<<6));
}


void MCAL_UART_ReceiveData(USART_TypeDef* USARTx, uint16_t* pRxBuffer, enum Polling_mechism PollingEn)
{
	//wait untill RXNE flag is set in the SR
	if (PollingEn == enable)
	{
		while(! (USARTx->SR & 1<<5));
	}
	//check the USART_WordLength item for 9Bit or 8Bit in a frame

	if(Global_UART_Config->Payload_Length == UART_Payload_Length_9B)
	{
		if (Global_UART_Config->Parity == UART_Parity_NONE)
		{
			//no parity so all 9bit are considered data
			*((uint16_t*) pRxBuffer) = USARTx->DR;
		}else
		{
			//parity is used, so 8bits will be user data and 1 bit for parity
			*((uint16_t*) pRxBuffer) = (USARTx->DR & (uint8_t)0xFF);
		}
	}

	else
	{
		//this 8bit data
		if (Global_UART_Config->Parity == UART_Parity_NONE)
		{
			//no parity so all 8 bit are considered data
			*((uint16_t*) pRxBuffer) = (USARTx->DR & (uint8_t)0xFF);
		}else
		{
			//parity is used, so 7bit will be user data and 1 bit is parity
			*((uint16_t*) pRxBuffer) = (USARTx->DR & (uint8_t)0x7F);
		}
	}
}


/**==============================================================================
 * @Fn				-MCAL_UART_GPIO_Set_Pins
 * @brief			-intialize GPIO Pins
 * @param [in]		-USARTx: where x can be (1..3 depending on device used)
 * @retval			-none
 * Note				-Should enable the corresponding ALT&GPIO in RCC clock also called after MCAL_UART_init()
 */


void MCAL_UART_GPIO_Set_Pins(USART_TypeDef* USARTx)
{
	GPIO_PinConfig_t PinCFG;
	if(USARTx == USART1)
	{
		//PA9 >> TX  -  PA10 >> RX  -  PA11 >> CTS  -  PA12 >> RTS
		//PA9 TX
		PinCFG.GPIO_PinNumber = GPIO_PIN_9;
		PinCFG.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinCFG.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &PinCFG);

		//PA10 RX
		PinCFG.GPIO_PinNumber = GPIO_PIN_11;
		PinCFG.GPIO_MODE = GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_Init(GPIOA, &PinCFG);

		if(Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_CTS || Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
		{
			//PA11 CTS
			PinCFG.GPIO_PinNumber = GPIO_PIN_10;
			PinCFG.GPIO_MODE = GPIO_MODE_AF_INPUT;
			MCAL_GPIO_Init(GPIOA, &PinCFG);
		}
		if(Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_RTS || Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
		{
			//PA12 RTS
			PinCFG.GPIO_PinNumber = GPIO_PIN_12;
			PinCFG.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCFG.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCFG);
		}

	}

}




//ISR

void USART1_IRQHandler (void)
{
	Global_UART_Config->P_IRQ_CallBack();
}

void USART2_IRQHandler (void)
{
	Global_UART_Config->P_IRQ_CallBack();
}

void USART3_IRQHandler (void)
{
	Global_UART_Config->P_IRQ_CallBack();
}

