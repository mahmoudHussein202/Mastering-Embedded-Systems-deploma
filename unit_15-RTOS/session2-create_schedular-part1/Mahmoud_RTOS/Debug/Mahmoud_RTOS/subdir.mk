################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mahmoud_RTOS/CortexMX_OS_Porting.c \
../Mahmoud_RTOS/fifo.c \
../Mahmoud_RTOS/schedular.c 

OBJS += \
./Mahmoud_RTOS/CortexMX_OS_Porting.o \
./Mahmoud_RTOS/fifo.o \
./Mahmoud_RTOS/schedular.o 

C_DEPS += \
./Mahmoud_RTOS/CortexMX_OS_Porting.d \
./Mahmoud_RTOS/fifo.d \
./Mahmoud_RTOS/schedular.d 


# Each subdirectory must supply rules for building sources it contributes
Mahmoud_RTOS/CortexMX_OS_Porting.o: ../Mahmoud_RTOS/CortexMX_OS_Porting.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Courses/Mastering_Embedded/unit14 - rtos/2- create schedular -part1/Lecture lab/Mahmoud_RTOS/CMSIS_V5" -I"D:/Courses/Mastering_Embedded/unit14 - rtos/2- create schedular -part1/Lecture lab/Mahmoud_RTOS/Mahmoud_RTOS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Mahmoud_RTOS/CortexMX_OS_Porting.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Mahmoud_RTOS/fifo.o: ../Mahmoud_RTOS/fifo.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Courses/Mastering_Embedded/unit14 - rtos/2- create schedular -part1/Lecture lab/Mahmoud_RTOS/CMSIS_V5" -I"D:/Courses/Mastering_Embedded/unit14 - rtos/2- create schedular -part1/Lecture lab/Mahmoud_RTOS/Mahmoud_RTOS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Mahmoud_RTOS/fifo.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Mahmoud_RTOS/schedular.o: ../Mahmoud_RTOS/schedular.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Courses/Mastering_Embedded/unit14 - rtos/2- create schedular -part1/Lecture lab/Mahmoud_RTOS/CMSIS_V5" -I"D:/Courses/Mastering_Embedded/unit14 - rtos/2- create schedular -part1/Lecture lab/Mahmoud_RTOS/Mahmoud_RTOS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Mahmoud_RTOS/schedular.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

