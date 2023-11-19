/*
 * Stm32_F103C6_GPIO_Driver.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Ahmed & Wessam
 */

#include "Stm32_F103C6_GPIO_Driver.h"


uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	switch(PinNumber)
	{
	case GPIO_PIN_0:
	case GPIO_PIN_8:
		return 0;
		break ;
	case GPIO_PIN_1:
	case GPIO_PIN_9:
		return 4;
		break ;
	case GPIO_PIN_2:
	case GPIO_PIN_10:
		return 8;
		break ;
	case GPIO_PIN_3:
	case GPIO_PIN_11:
		return 12;
		break ;
	case GPIO_PIN_4:
	case GPIO_PIN_12:
		return 16;
		break ;
	case GPIO_PIN_5:
	case GPIO_PIN_13:
		return 20;
		break ;
	case GPIO_PIN_6:
	case GPIO_PIN_14:
		return 24;
		break ;
	case GPIO_PIN_7:
	case GPIO_PIN_15:
		return 28;
		break ;
	}
	return 0;
}

/**==============================================================================
 * @Fn				-MCAL_GPIO_Init
 * @brief			-Initializes the GPIOx PINy according to the specified parameters in the PinConfig
 * @param [in]		-GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in]		-PinConfig pointer to a GPIO_PinConfig_t structure that contains
 * 					 the configuration information for the specified GPIO PIN
 * @retval			-none
 * Note				-Stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 					 But LQFP48 package has only GPIO A,B,PART of C/D
 */
void MCAL_GPIO_Init (GPIO_TypeDef *GPIOx , GPIO_PinConfig_t* PinConfig)
{
	//Port configuration register low (GPIOx_CRL) configure PINS from 0 >>> 7
	//Port configuration register high (GPIOx_CRH) configure PINS from 8 >>> 15
	volatile uint32_t* Config_Reg = NULL;
	Config_Reg = (PinConfig->GPIO_PinNumber < GPIO_PIN_8)?  &GPIOx->CRL : &GPIOx->CRH;
	uint8_t PIN_Config = 0;
	//clear CNF8[1:0]  MODE[1:0]
	(*Config_Reg) &= ~(0xf << Get_CRLH_Position(PinConfig->GPIO_PinNumber));

	//if Pin is output
	if ( (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP)   )
	{
		//set CNF8[1:0]  MODE[1:0]
		PIN_Config = (( ((PinConfig->GPIO_MODE -4) <<2) | (PinConfig->GPIO_Output_Speed) ) &0x0f );
	}
	//if Pin is input
	else
	{
		if ((PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO) || (PinConfig->GPIO_MODE == GPIO_MODE_ANALOG))
		{
			//set CNF8[1:0]  MODE[1:0]0
			PIN_Config = (( ((PinConfig->GPIO_MODE) <<2) | (0x0) ) &0x0f );
		}
		else if (PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT ) //consider it as input floating
		{
			//set CNF8[1:0]  MODE[1:0]0
			PIN_Config = (( ((GPIO_MODE_INPUT_FLO) <<2) | (0x0) ) &0x0f );
		}
		else // PU PD Input
		{
			PIN_Config = (( ((GPIO_MODE_INPUT_PU) <<2) | (0x0) ) &0x0f );
			if (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
			{
				//PxODR = 1 Input pull-up : Table 20. Port bit configuration table
				GPIOx->ODR |= PinConfig->GPIO_PinNumber;
			}
			else
			{
				//PxODR = 0 Input pull-down : Table 20. Port bit configuration table
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
			}

		}
	}
	// write on CRL or CRH
	(*Config_Reg) |= (PIN_Config << Get_CRLH_Position(PinConfig->GPIO_PinNumber));
}


/**==============================================================================
 * @Fn				-MCAL_GPIO_DeInit
 * @brief			-Reset all the GPIO registers
 * @param [in]		-GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @retval			-none
 * Note				-none
 */
void MCAL_GPIO_DeInit (GPIO_TypeDef *GPIOx)
{
	// APB2 peripheral reset register (RCC_APB2RSTR)
	// Set and cleared by software
	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2); // Bit 2 IOPARST: IO port A reset
		RCC->APB2RSTR &= ~(1<<2);
	}else if(GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3); // Bit 3 IOPARST: IO port B reset
		RCC->APB2RSTR &= ~(1<<3);
	}else if(GPIOx == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4); // Bit 4 IOPARST: IO port C reset
		RCC->APB2RSTR &= ~(1<<4);
	}else if(GPIOx == GPIOD)
	{
		RCC->APB2RSTR |= (1<<5); // Bit 5 IOPARST: IO port D reset
		RCC->APB2RSTR &= ~(1<<5);
	}else if(GPIOx == GPIOE)
	{
		RCC->APB2RSTR |= (1<<6); // Bit 6 IOPARST: IO port E reset
		RCC->APB2RSTR &= ~(1<<6);
	}
}


/**==============================================================================
 * @Fn				-MCAL_GPIO_ReadPin
 * @brief			-Read specific Pin
 * @param [in]		-GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in]		-Set PIN number according GPIO_PINS_define
 * @retval			-the input pin value (two values based on @ref GPIO_PIN_State)
 * Note				-none
 */
uint8_t MCAL_GPIO_ReadPin (GPIO_TypeDef *GPIOx , uint16_t PinNumber)
{
	uint8_t Bit_Status;
	if (((GPIOx->IDR) & PinNumber) != (uint32_t)GPIO_PIN_RESET )
	{
		Bit_Status = GPIO_PIN_SET;
	}
	else
	{
		Bit_Status = GPIO_PIN_RESET;
	}
	return Bit_Status;
}


/**==============================================================================
 * @Fn				-MCAL_GPIO_ReadPort
 * @brief			-Read the input port value
 * @param [in]		-GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @retval			-the input port value
 * Note				-none
 */

uint16_t MCAL_GPIO_ReadPort (GPIO_TypeDef *GPIOx)
{
	uint16_t Port_Value;
	Port_Value = (uint16_t)(GPIOx->IDR);
	return Port_Value;
}


/**==============================================================================
 * @Fn				-MCAL_GPIO_WritePin
 * @brief			-write on specific input pin
 * @param [in]		-GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in]		-PinNumber : specifies the port bit to read. Set by @ref GPIO_PINS_define
 * @param [in]		-Value : Pin Value
 * @retval			-none
 * Note				-none
 */
void MCAL_GPIO_WritePin (GPIO_TypeDef *GPIOx , uint16_t PinNumber , uint8_t value)
{
	if (value != GPIO_PIN_RESET)
	{
		//Bits 15:0 BSy: Port x set bit y (y=0 .. 15)
		//These bits are write-only and can be accessed in word mode only
		// 0: No action on the corresponding ODRx bit
		// 1: Set the corresponding ODRx bit
		GPIOx->BSRR = (uint32_t)PinNumber;
	}else
	{
		//Bits 31:16 BSy: Port x set bit y (y=16 .. 31)
		//These bits are write-only and can be accessed in word mode only
		// 0: No action on the corresponding ODRx bit
		// 1: Reset the corresponding ODRx bit
		GPIOx->BRR = (uint32_t)PinNumber;
	}

}


/**==============================================================================
 * @Fn				-MCAL_GPIO_WritePort
 * @brief			-write on output port
 * @param [in]		-GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @retval			-none
 * Note				-none
 */
void MCAL_GPIO_WritePort (GPIO_TypeDef *GPIOx , uint16_t value)
{
	GPIOx->ODR = (uint32_t)value;
}


/**==============================================================================
 * @Fn				-MCAL_GPIO_TogglePin
 * @brief			-toggle the specified GPIO Pin
 * @param [in]		-GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in]		-PinNumber : specifies the port bit to read. Set by @ref GPIO_PINS_define
 * @retval			-none
 * Note				-none
 */
void MCAL_GPIO_TogglePin (GPIO_TypeDef *GPIOx , uint16_t PinNumber)
{
	GPIOx->ODR ^= PinNumber;
}


/**==============================================================================
 * @Fn				-MCAL_GPIO_LockPin
 * @brief			-the locking mechanism allows the IO configuration to be frozen
 * @param [in]		-GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in]		-PinNumber : specifies the port bit to read. Set by @ref GPIO_PINS_define
 * @retval			-OK if pin config is locked or ERROR if pin not locked (defined @ref GPIO_RETURN_LOCK)
 * Note				-none
 */
uint8_t MCAL_GPIO_LockPin (GPIO_TypeDef *GPIOx , uint16_t PinNumber)
{
	/*	Bit 16 LCKK[16]: Lock key
	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	0: Port configuration lock key not active
	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	LOCK key writing sequence:
	Write 1
	Write 0
	Write 1
	Read 0
	Read 1 (this read is optional but confirms that the lock is active)
	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	Any error in the lock sequence will abort the lock.
	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	These bits are read write but can only be written when the LCKK bit is 0.
	0: Port configuration not locked
	1: Port configuration locked.
	 */

	//Set LCKK[16]
	volatile uint32_t tmp = 1<<16;
	//Set LCKy
	tmp |= PinNumber;
	// Write 1
	GPIOx->LCKR = tmp;
	// Write 0
	GPIOx->LCKR = PinNumber;
	// Write 1
	GPIOx->LCKR = tmp;

	//Read 0
	tmp = GPIOx->LCKR;
	//Read 1 (this read is optional but confirms that lock is active)
	if ((uint32_t) (GPIOx->LCKR & 1<<16))
	{
		return GPIO_RETURN_LOCK_ENABLED;
	}else
	{
		return GPIO_RETURN_LOCK_ERROR;
	}

}





