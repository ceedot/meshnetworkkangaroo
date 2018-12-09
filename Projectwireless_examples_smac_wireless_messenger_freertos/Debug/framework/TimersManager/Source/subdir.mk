################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../framework/TimersManager/Source/TMR_Adapter.c \
../framework/TimersManager/Source/TimersManager.c 

OBJS += \
./framework/TimersManager/Source/TMR_Adapter.o \
./framework/TimersManager/Source/TimersManager.o 

C_DEPS += \
./framework/TimersManager/Source/TMR_Adapter.d \
./framework/TimersManager/Source/TimersManager.d 


# Each subdirectory must supply rules for building sources it contributes
framework/TimersManager/Source/%.o: ../framework/TimersManager/Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKW41Z512CAT4 -DCPU_MKW41Z512CAT4_cm0plus -DDEBUG -DCPU_MKW41Z512VHT4 -DFSL_RTOS_FREE_RTOS -DFRDM_KW41Z -DFREEDOM -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -I../board -I../source -I../ -I../framework/OSAbstraction/Interface -I../framework/common -I../freertos -I../ieee_802.15.4/phy/interface -I../ieee_802.15.4/smac/interface -I../ieee_802.15.4/smac/source -I../ieee_802.15.4/smac/common -I../ieee_802.15.4/phy/source/MKW41Z -I../framework/XCVR/MKW41Z4 -I../framework/GPIO -I../framework/Keyboard/Interface -I../framework/TimersManager/Interface -I../framework/TimersManager/Source -I../framework/LED/Interface -I../framework/SerialManager/Source/SPI_Adapter -I../framework/SerialManager/Source/UART_Adapter -I../framework/SerialManager/Source/I2C_Adapter -I../framework/Flash/Internal -I../framework/MemManager/Interface -I../framework/Lists -I../framework/Messaging/Interface -I../framework/Panic/Interface -I../framework/RNG/Interface -I../framework/SerialManager/Interface -I../framework/ModuleInfo -I../framework/FunctionLib -I../framework/SecLib -I../framework/MWSCoexistence/Interface -I../drivers -I../CMSIS -I../utilities -I../framework/DCDC/Interface -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -imacros "C:/Users/Callum/Documents/MCUXpressoIDE_10.2.1_795/workspace/Projectwireless_examples_smac_wireless_messenger_freertos/source/app_preinclude.h" -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


