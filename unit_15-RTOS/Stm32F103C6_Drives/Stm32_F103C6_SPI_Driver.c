/*
 * Stm32_F103C6_SPI_Driver.c
 *
 *  Created on: Sep 10, 2023
 *      Author: Wessam
 */

#include "Stm32_F103C6_SPI_Driver.h"


/*
 * ==========================================================================================
 * 									Generic Variables
 * ==========================================================================================
 */

SPI_Config* Global_SPI_Config[2] = {NULL,NULL};

SPI_Config Global_SPI_Config1;
SPI_Config Global_SPI_Config2;
/*
 * ==========================================================================================
 * 									Generic Macros
 * ==========================================================================================
 */

#define		SPI1_INDEX				0
#define		SPI2_INDEX				1

#define 	SPI_SR_TXE				((uint8_t)0x02) //transmit buffer empty
#define 	SPI_SR_RXNE				((uint8_t)0x01) //receive buffer not empty


/*
 * ==========================================================================================
 * 									APIs
 * ==========================================================================================
 */

/**==============================================================================
 * @Fn				-MCAL_SPI_Init
 * @brief			-Initializes SPI according to the specified parameters
 * @param [in]		-SPIx: where x can be (1..3 depending on device used)
 * @param [in]		-SPI_Config: All SPI Configuration SPI_Config
 * @retval			-none
 * Note				-Support for SPI Full Duplex Master/Slave only & NSS HW/SW
 * 					-in case of master you have to configure pin and drive it
 */

void MCAL_SPI_Init(SPI_TypeDef* SPIx, SPI_Config* SPI_Config)
{
	//Safety for registers
	uint16_t tempreg_CR1 = 0;
	uint16_t tempreg_CR2 = 0;

	if(SPIx == SPI1)
	{
		Global_SPI_Config1 = *SPI_Config;
		Global_SPI_Config[SPI1_INDEX] = &Global_SPI_Config1;
		RCC_SPI1_CLK_EN();
	}else if(SPIx == SPI2)
	{
		Global_SPI_Config2 = *SPI_Config;
		Global_SPI_Config[SPI2_INDEX] = &Global_SPI_Config2;
		RCC_SPI2_CLK_EN();
	}

	//Enable SPI CR1:Bit 6 SPE: SPI Enable
	tempreg_CR1 = (0x1U<<6);

	//Master or Slave
	tempreg_CR1 |= SPI_Config->Device_Mode;

	//SPI_Communication_Mode
	tempreg_CR1 |= SPI_Config->Communication_Mode;

	//SPI_Frame_Format
	tempreg_CR1 |= SPI_Config->Frame_Format;

	//SPI_DataSize
	tempreg_CR1 |= SPI_Config->DataSize;

	//SPI_Clock_Polarity
	tempreg_CR1 |= SPI_Config->CLKPolarity;

	//SPI_Clock_Phase
	tempreg_CR1 |= SPI_Config->CLKPhase;
	//===============================NSS===================================

	if(SPI_Config->NSS == SPI_NSS_Hard_Master_SS_OP_Enable)
	{
		tempreg_CR2 |= SPI_Config->NSS;
	}else if(SPI_Config->NSS == SPI_NSS_Hard_Master_SS_OP_Disable)
	{
		tempreg_CR2 &= SPI_Config->NSS;
	}else
	{
		tempreg_CR1 |= SPI_Config->NSS;
	}
	//==========================================================================
	//SPI_BaudratePrescaler
	tempreg_CR1 |= SPI_Config->BaudratePrescaler;


	if(SPI_Config->IRQ_Enable != SPI_IRQ_Enable_NONE)
	{
		//SPI_IRQ_Enable_define
		tempreg_CR2 |= SPI_Config->IRQ_Enable;

		if(SPIx == SPI1)
		{
			NVIC_IRQ35_SPI1_Enable;
		}else if(SPIx == SPI2)
		{
			NVIC_IRQ36_SPI2_Enable;
		}
	}
	SPIx->CR1 = tempreg_CR1;
	SPIx->CR2 = tempreg_CR2;
}



void MCAL_SPI_DeInit(SPI_TypeDef* SPIx)
{
	if(SPIx == SPI1)
	{
		NVIC_IRQ35_SPI1_Disable;
		RCC_SPI1_Reset();
	}else if(SPIx == SPI2)
	{
		NVIC_IRQ36_SPI2_Disable;
		RCC_SPI2_Reset();
	}
}



void MCAL_SPI_SendData(SPI_TypeDef* SPIx, uint16_t* pTxBuffer,enum Polling_Mechism PollingEn)
{
	//todo receive only

	if(PollingEn == Enable)
		while(!((SPIx)->SR & SPI_SR_TXE));

	SPIx->DR = *pTxBuffer;
}




void MCAL_SPI_ReceiveData(SPI_TypeDef* SPIx, uint16_t* pRxBuffer,enum Polling_Mechism PollingEn)
{
	if(PollingEn == Enable)
		while(!((SPIx)->SR & SPI_SR_RXNE));

	*pRxBuffer = SPIx->DR;
}




void MCAL_SPI_TX_RX(SPI_TypeDef* SPIx, uint16_t* pTxBuffer,enum Polling_Mechism PollingEn)
{
	if(PollingEn == Enable)
		while(!((SPIx)->SR & SPI_SR_TXE));
	SPIx->DR = *pTxBuffer;

	if(PollingEn == Enable)
		while(!((SPIx)->SR & SPI_SR_RXNE));
	*pTxBuffer = SPIx->DR;
}




void MCAL_SPI_GPIO_Set_Pins(SPI_TypeDef* SPIx)
{
	GPIO_PinConfig_t PinCfg;

	if(SPIx == SPI1)
	{
		//PA4:NSS - PA5:SCK - PA6:MISO - PA7:MOSI
		if(Global_SPI_Config[SPI1_INDEX]->Device_Mode == SPI_Device_Mode_MASTER)
		{
			//PA4:NSS
			switch (Global_SPI_Config[SPI1_INDEX]->NSS)
			{
			case SPI_NSS_Hard_Master_SS_OP_Disable:
				//Hardware master / slave input floating
				PinCfg.GPIO_PinNumber = GPIO_PIN_4;
				PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOA, &PinCfg);
				break;

			case SPI_NSS_Hard_Master_SS_OP_Enable:
				//Hardware master / NSS output enabled alternate function push pull
				PinCfg.GPIO_PinNumber = GPIO_PIN_4;
				PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
				PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
				MCAL_GPIO_Init(GPIOA, &PinCfg);
				break;
			}
			//PA5:SCK , Master Alternate function push-pull
			PinCfg.GPIO_PinNumber = GPIO_PIN_5;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

			//PA6:MISO , full duplex / master input floating
			PinCfg.GPIO_PinNumber = GPIO_PIN_6;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
			//todo to support half duplex and simplex

			//PA7:SPI_MOSI , full duplex / alternate function push pull
			PinCfg.GPIO_PinNumber = GPIO_PIN_7;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

		}else //Slave
		{
			//PA4:NSS
			if(Global_SPI_Config[SPI1_INDEX]->NSS == SPI_NSS_Hard_Slave)
			{
				//Hardware master / Slave input floating
				PinCfg.GPIO_PinNumber = GPIO_PIN_4;
				PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOA, &PinCfg);
			}

			//PA5:SCK , Slave input floating
			PinCfg.GPIO_PinNumber = GPIO_PIN_5;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

			//PA6:MISO (only full duplex)
			PinCfg.GPIO_PinNumber = GPIO_PIN_6;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

			//PA7: MOSI , full duplex / Slave input floating
			PinCfg.GPIO_PinNumber = GPIO_PIN_7;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

		}

	}else if (SPIx == SPI2)
	{
		//PB12:NSS - PB13:SCK - PB14:MISO - PB15:MOSI
		if(Global_SPI_Config[SPI2_INDEX]->Device_Mode == SPI_Device_Mode_MASTER)
		{
			//PB12:NSS
			switch (Global_SPI_Config[SPI2_INDEX]->NSS)
			{
			case SPI_NSS_Hard_Master_SS_OP_Disable:
				//Hardware master / slave input floating
				PinCfg.GPIO_PinNumber = GPIO_PIN_12;
				PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOB, &PinCfg);
				break;

			case SPI_NSS_Hard_Master_SS_OP_Enable:
				//Hardware master / NSS output enabled alternate function push pull
				PinCfg.GPIO_PinNumber = GPIO_PIN_12;
				PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
				PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
				MCAL_GPIO_Init(GPIOB, &PinCfg);
				break;
			}

			//PB13:SCK , Master Alternate function push-pull
			PinCfg.GPIO_PinNumber = GPIO_PIN_13;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

			//PX14:MISO , full duplex / master input floating
			PinCfg.GPIO_PinNumber = GPIO_PIN_14;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCfg);
			//todo to support half duplex and simplex

			//PB15:MOSI , full duplex / alternate function push pull
			PinCfg.GPIO_PinNumber = GPIO_PIN_15;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

		}else //Slave
		{
			//PB12:NSS

			switch(Global_SPI_Config[SPI2_INDEX]->NSS)
			{

			case SPI_NSS_Hard_Slave:
				// Slave input floating
				PinCfg.GPIO_PinNumber = GPIO_PIN_12;
				PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOB, &PinCfg);
			}


			//PB13:SCK , Slave input floating
			PinCfg.GPIO_PinNumber = GPIO_PIN_13;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

			//PB14:MISO
			PinCfg.GPIO_PinNumber = GPIO_PIN_14;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

			//PB15: MISO , full duplex / Slave input floating
			PinCfg.GPIO_PinNumber = GPIO_PIN_15;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

		}

	}
}





	/*
	 * ==========================================================================================
	 * 									IRQ
	 * ==========================================================================================
	 */


	void SPI1_IRQHandler (void)
	{
		struct S_IRQ_SRC irq_src;

		irq_src.TXE = ( ( SPI1->SR & (1<<1) ) >>1 );
		irq_src.RXNE = ( ( SPI1->SR & (1<<0) ) >>0 );
		irq_src.ERRI = ( ( SPI1->SR & (1<<4) ) >>4 );

		Global_SPI_Config[SPI1_INDEX]->P_IRQ_CallBack (irq_src);
	}


	void SPI2_IRQHandler (void)
	{
		struct S_IRQ_SRC irq_src;

		irq_src.TXE = ( ( SPI2->SR & (1<<1) ) >>1 );
		irq_src.RXNE = ( ( SPI2->SR & (1<<0) ) >>0 );
		irq_src.ERRI = ( ( SPI2->SR & (1<<4) ) >>4 );

		Global_SPI_Config[SPI2_INDEX]->P_IRQ_CallBack (irq_src);
	}


