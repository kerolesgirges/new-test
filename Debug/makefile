################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/WDT/subdir.mk
-include MCAL/UART/subdir.mk
-include MCAL/Timer/subdir.mk
-include MCAL/ICU/subdir.mk
-include MCAL/I2C/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXINT/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC_NEW_config/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/WIFI/subdir.mk
-include HAL/SSD/subdir.mk
-include HAL/Relay/subdir.mk
-include HAL/PushButton/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/LDR/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/Keypad/subdir.mk
-include HAL/EEPROM/subdir.mk
-include HAL/Buzzer/subdir.mk
-include APP/Projects/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
CCS_SYS.lss \
CCS_SYS.lss \

FLASH_IMAGE += \
CCS_SYS.hex \

SIZEDUMMY += \
sizedummy \
sizedummy \


# All Target
all: CCS_SYS.elf secondary-outputs

# Tool invocations
CCS_SYS.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,CCS_SYS.map -mmcu=atmega32 -o "CCS_SYS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

CCS_SYS.lss: CCS_SYS.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S CCS_SYS.elf  >"CCS_SYS.lss"
	@echo 'Finished building: $@'
	@echo ' '

CCS_SYS.hex: CCS_SYS.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex CCS_SYS.elf  "CCS_SYS.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: CCS_SYS.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 CCS_SYS.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) CCS_SYS.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
