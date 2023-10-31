/*
 * Eng: Mahmoud Hussein
 */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CAN_Init(void);
void HAL_CAN_TxMailbox0CompleteCallback(CAN_HandleTypeDef *hcan);
void can_filter_config(uint16_t ID);
uint8_t can_tx_message(uint16_t ID , uint8_t DLC , uint8_t aData[] , uint8_t polling_enable) ;
CAN_HandleTypeDef hcan;
enum {
	can_polling_disable,
	can_polling_enable
}can_polling_state;

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();
	MX_CAN_Init();
	HAL_CAN_Init(&hcan);
	HAL_CAN_ActivateNotification(&hcan, CAN_IT_TX_MAILBOX_EMPTY);
	can_filter_config(0x03F); // Receiving ID
	if (HAL_CAN_Start(&hcan) != HAL_OK)
		Error_Handler();
	uint8_t frame_num = 0 ;
	uint8_t data_frame[] = {'F','R','A','M','E',':',' ',' '};
	char counter = 0 ;

	while (1)
	{
		data_frame[6] = frame_num;
		frame_num++ ;
		can_tx_message(0x03F, 8, data_frame, can_polling_disable);
		counter++;
		HAL_Delay(1000);

	}
}
















void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}
	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
			|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
	{
		Error_Handler();
	}
}

static void MX_CAN_Init(void)
{
	hcan.Instance = CAN1;
	hcan.Init.Prescaler = 1;
	hcan.Init.Mode = CAN_MODE_LOOPBACK;
	hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
	hcan.Init.TimeSeg1 = CAN_BS1_6TQ;
	hcan.Init.TimeSeg2 = CAN_BS2_1TQ;
	hcan.Init.TimeTriggeredMode = DISABLE;
	hcan.Init.AutoBusOff = DISABLE;
	hcan.Init.AutoWakeUp = DISABLE;
	hcan.Init.AutoRetransmission = DISABLE;
	hcan.Init.ReceiveFifoLocked = DISABLE;
	hcan.Init.TransmitFifoPriority = DISABLE;
	if (HAL_CAN_Init(&hcan) != HAL_OK)
	{
		Error_Handler();
	}
}
static void MX_GPIO_Init(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
}

void Error_Handler(void)
{

}

void can_filter_config(uint16_t ID)
{
	CAN_FilterTypeDef sFilterConfig;
	sFilterConfig.FilterActivation = CAN_FILTER_ENABLE ;
	sFilterConfig.FilterBank = 0;
	sFilterConfig.FilterFIFOAssignment = CAN_FILTER_FIFO0;
	sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
	sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
	sFilterConfig.FilterIdHigh = ID << 5 ;
	sFilterConfig.FilterIdLow = 0x0000;
	sFilterConfig.FilterMaskIdHigh = 0xFFE0;
	sFilterConfig.FilterMaskIdLow = 0x0000;
	HAL_CAN_ConfigFilter(&hcan, &sFilterConfig);
}

uint8_t can_tx_message(uint16_t ID , uint8_t DLC , uint8_t aData[] , uint8_t polling_enable)
{
	CAN_TxHeaderTypeDef pHeader;
	uint32_t used_mailBox_num ;
	pHeader.StdId = ID ;
	pHeader.DLC = DLC;
	pHeader.RTR = CAN_RTR_DATA ;
	pHeader.IDE = CAN_ID_STD;
	// wait until at least one of the transmit mailboxes are free
	while(HAL_CAN_GetTxMailboxesFreeLevel(&hcan)==0);
	HAL_CAN_AddTxMessage(&hcan, &pHeader, aData, &used_mailBox_num) ;
	if (polling_enable == can_polling_enable)
	{
		while(HAL_CAN_IsTxMessagePending(&hcan, 0));
		while(HAL_CAN_IsTxMessagePending(&hcan, 1));
		while(HAL_CAN_IsTxMessagePending(&hcan, 2));
	}

	return used_mailBox_num ;
}

void HAL_CAN_TxMailbox0CompleteCallback(CAN_HandleTypeDef *hcan)
{
	// im here
}
