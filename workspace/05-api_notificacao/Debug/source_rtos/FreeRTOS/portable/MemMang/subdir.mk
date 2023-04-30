################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source_rtos/FreeRTOS/portable/MemMang/heap_4.c 

OBJS += \
./source_rtos/FreeRTOS/portable/MemMang/heap_4.o 

C_DEPS += \
./source_rtos/FreeRTOS/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
source_rtos/FreeRTOS/portable/MemMang/%.o source_rtos/FreeRTOS/portable/MemMang/%.su source_rtos/FreeRTOS/portable/MemMang/%.cyclo: ../source_rtos/FreeRTOS/portable/MemMang/%.c source_rtos/FreeRTOS/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"/home/isaac/Documents/SO-TempoReal/workspace/05-api_notificacao/source_rtos/FreeRTOS" -I"/home/isaac/Documents/SO-TempoReal/workspace/05-api_notificacao/source_rtos/FreeRTOS/include" -I"/home/isaac/Documents/SO-TempoReal/workspace/05-api_notificacao/source_rtos/FreeRTOS/portable/GCC/ARM_CM3" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-source_rtos-2f-FreeRTOS-2f-portable-2f-MemMang

clean-source_rtos-2f-FreeRTOS-2f-portable-2f-MemMang:
	-$(RM) ./source_rtos/FreeRTOS/portable/MemMang/heap_4.cyclo ./source_rtos/FreeRTOS/portable/MemMang/heap_4.d ./source_rtos/FreeRTOS/portable/MemMang/heap_4.o ./source_rtos/FreeRTOS/portable/MemMang/heap_4.su

.PHONY: clean-source_rtos-2f-FreeRTOS-2f-portable-2f-MemMang

