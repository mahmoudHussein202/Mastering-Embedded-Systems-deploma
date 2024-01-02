################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
setting_clock_frequency.axf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
setting_clock_frequency.list \

OBJCOPY_BIN += \
setting_clock_frequency.bin \


# All Target
all: setting_clock_frequency.axf secondary-outputs

# Tool invocations
setting_clock_frequency.axf: $(OBJS) $(USER_OBJS) D:\Courses\Mastering_Embedded\unit6\Lecture_3\lab2-setting\ the\ system\ frequency\setting_clock_frequency\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "setting_clock_frequency.axf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\Courses\Mastering_Embedded\unit6\Lecture_3\lab2-setting the system frequency\setting_clock_frequency\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="setting_clock_frequency.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

setting_clock_frequency.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "setting_clock_frequency.list"
	@echo 'Finished building: $@'
	@echo ' '

setting_clock_frequency.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "setting_clock_frequency.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
