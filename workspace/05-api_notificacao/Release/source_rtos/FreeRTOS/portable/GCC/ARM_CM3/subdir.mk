################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source_rtos/FreeRTOS/portable/GCC/ARM_CM3/port.c 

OBJS += \
./source_rtos/FreeRTOS/portable/GCC/ARM_CM3/port.o 

C_DEPS += \
./source_rtos/FreeRTOS/portable/GCC/ARM_CM3/port.d 


# Each subdirectory must supply rules for building sources it contributes
source_rtos/FreeRTOS/portable/GCC/ARM_CM3/%.o source_rtos/FreeRTOS/portable/GCC/ARM_CM3/%.su source_rtos/FreeRTOS/portable/GCC/ARM_CM3/%.cyclo: ../source_rtos/FreeRTOS/portable/GCC/ARM_CM3/%.c source_rtos/FreeRTOS/portable/GCC/ARM_CM3/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-source_rtos-2f-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM3

clean-source_rtos-2f-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM3:
	-$(RM) ./source_rtos/FreeRTOS/portable/GCC/ARM_CM3/port.cyclo ./source_rtos/FreeRTOS/portable/GCC/ARM_CM3/port.d ./source_rtos/FreeRTOS/portable/GCC/ARM_CM3/port.o ./source_rtos/FreeRTOS/portable/GCC/ARM_CM3/port.su

.PHONY: clean-source_rtos-2f-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM3

