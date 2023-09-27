################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Projects/M_USART_NEW_Prog.c \
../APP/Projects/main.c 

OBJS += \
./APP/Projects/M_USART_NEW_Prog.o \
./APP/Projects/main.o 

C_DEPS += \
./APP/Projects/M_USART_NEW_Prog.d \
./APP/Projects/main.d 


# Each subdirectory must supply rules for building sources it contributes
APP/Projects/%.o: ../APP/Projects/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\NTI\last_ver\CCS_sys\APP" -I"F:\NTI\last_ver\CCS_sys\MCAL\ICU" -I"F:\NTI\week2\D2\CCS_sys\APP\Projects" -I"F:\NTI\last_ver\CCS_sys\MCAL\ADC_NEW_config" -I"F:\NTI\last_ver\CCS_sys\HAL\EEPROM" -I"F:\NTI\last_ver\CCS_sys\HAL\WIFI" -I"F:\NTI\last_ver\CCS_sys\HAL" -I"F:\NTI\last_ver\CCS_sys\MCAL" -I"F:\NTI\last_ver\CCS_sys\LIB" -I"F:\NTI\last_ver\CCS_sys\APP\Projects" -I"F:\NTI\last_ver\CCS_sys\HAL\Buzzer" -I"F:\NTI\last_ver\CCS_sys\HAL\Keypad" -I"F:\NTI\last_ver\CCS_sys\HAL\LCD" -I"F:\NTI\last_ver\CCS_sys\HAL\LDR" -I"F:\NTI\last_ver\CCS_sys\HAL\LED" -I"F:\NTI\last_ver\CCS_sys\HAL\PushButton" -I"F:\NTI\last_ver\CCS_sys\HAL\Relay" -I"F:\NTI\last_ver\CCS_sys\HAL\SSD" -I"F:\NTI\last_ver\CCS_sys\MCAL\ADC" -I"F:\NTI\last_ver\CCS_sys\MCAL\DIO" -I"F:\NTI\last_ver\CCS_sys\MCAL\EXINT" -I"F:\NTI\last_ver\CCS_sys\MCAL\GIE" -I"F:\NTI\last_ver\CCS_sys\MCAL\I2C" -I"F:\NTI\last_ver\CCS_sys\MCAL\Timer" -I"F:\NTI\last_ver\CCS_sys\MCAL\UART" -I"F:\NTI\last_ver\CCS_sys\MCAL\WDT" -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


