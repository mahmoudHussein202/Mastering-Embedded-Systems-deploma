################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32F103C6_Drives/Stm32_F103C6_EXTI_Driver.c \
../Stm32F103C6_Drives/Stm32_F103C6_GPIO_Driver.c \
../Stm32F103C6_Drives/Stm32_F103C6_RCC_Driver.c \
../Stm32F103C6_Drives/Stm32_F103C6_SPI_Driver.c \
../Stm32F103C6_Drives/Stm32_F103C6_USART_Driver.c 

OBJS += \
./Stm32F103C6_Drives/Stm32_F103C6_EXTI_Driver.o \
./Stm32F103C6_Drives/Stm32_F103C6_GPIO_Driver.o \
./Stm32F103C6_Drives/Stm32_F103C6_RCC_Driver.o \
./Stm32F103C6_Drives/Stm32_F103C6_SPI_Driver.o \
./Stm32F103C6_Drives/Stm32_F103C6_USART_Driver.o 

C_DEPS += \
./Stm32F103C6_Drives/Stm32_F103C6_EXTI_Driver.d \
./Stm32F103C6_Drives/Stm32_F103C6_GPIO_Driver.d \
./Stm32F103C6_Drives/Stm32_F103C6_RCC_Driver.d \
./Stm32F103C6_Drives/Stm32_F103C6_SPI_Driver.d \
./Stm32F103C6_Drives/Stm32_F103C6_USART_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32F103C6_Drives/Stm32_F103C6_EXTI_Driver.o: ../Stm32F103C6_Drives/Stm32_F103C6_EXTI_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Ahmed & Wessam/STM32CubeIDE/workspace_1.4.0/Drives/MY_RTOS/inc" -I"C:/Users/Ahmed & Wessam/STM32CubeIDE/workspace_1.4.0/Drives/CMSIS_V5" -I"C:/Users/Ahmed & Wessam/STM32CubeIDE/workspace_1.4.0/Drives/HAL/includes" -I"C:/Users/Ahmed & Wessam/STM32CubeIDE/workspace_1.4.0/Drives/Stm32F103C6_Drives/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32F103C6_Drives/Stm32_F103C6_EXTI_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32F103C6_Drives/Stm32_F103C6_GPIO_Driver.o: ../Stm32F103C6_Drives/Stm32_F103C6_GPIO_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Ahmed & Wessam/STM32CubeIDE/workspace_1.4.0/Drives/MY_RTOS/inc" -I"C:/Users/Ahmed & Wessam/STM32CubeIDE/workspace_1.4.0/Drives/CMSIS_V5" -I"C:/Users/Ahmed & Wessam/STM32CubeIDE/workspace_1.4.0/Drives/HAL/includes" -I"C:/Users/Ahmed & Wessam/STM32CubeIDE/workspace_1.4.0/Drives/Stm32F103C6_Drives/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32F103C6_Drives/Stm32_F103C6_GPIO_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32F103C6_Drives/Stm32_F103C6_RCC_Driver.o: ../Stm32F103C6_Drives/Stm32_F103C6_RCC_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Ahmed & Wessam/STM32CubeIDE/workspace_1.4.0/Drives/MY_RTOS/inc" -I"C:/Users/Ahmed & Wessam/STM32CubeIDE/workspace_1.4.0/Drives/CMSIS_V5" -I"C:/Users/Ahmed & Wessam/STM32CubeIDE/workspace_1.4.0/Drives/HAL/includes" -I"C:/Users/Ahmed & Wessam/STM32CubeIDE/workspace_1.4.0/Drives/Stm32F103C6_Drives/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32F103C6_Drives/Stm32_F103C6_RCC_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32F103C6_Drives/Stm32_F103C6_SPI_Driver.o: ../Stm32F103C6_Drives/Stm32_F103C6_SPI_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Ahmed & Wessam/STM32CubeIDE/workspace_1.4.0/Drives/MY_RTOS/inc" -I"C:/Users/Ahmed & Wessam/STM32CubeIDE/workspace_1.4.0/Drives/CMSIS_V5" -I"C:/Users/Ahmed & Wessam/STM32CubeIDE/workspace_1.4.0/Drives/HAL/includes" -I"C:/Users/Ahmed & Wessam/STM32CubeIDE/workspace_1.4.0/Drives/Stm32F103C6_Drives/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32F103C6_Drives/Stm32_F103C6_SPI_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32F103C6_Drives/Stm32_F103C6_USART_Driver.o: ../Stm32F103C6_Drives/Stm32_F103C6_USART_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Ahmed & Wessam/STM32CubeIDE/workspace_1.4.0/Drives/MY_RTOS/inc" -I"C:/Users/Ahmed & Wessam/STM32CubeIDE/workspace_1.4.0/Drives/CMSIS_V5" -I"C:/Users/Ahmed & Wessam/STM32CubeIDE/workspace_1.4.0/Drives/HAL/includes" -I"C:/Users/Ahmed & Wessam/STM32CubeIDE/workspace_1.4.0/Drives/Stm32F103C6_Drives/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32F103C6_Drives/Stm32_F103C6_USART_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

