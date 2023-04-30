################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source_rtos/FreeRTOS/event_groups.c \
../source_rtos/FreeRTOS/list.c \
../source_rtos/FreeRTOS/queue.c \
../source_rtos/FreeRTOS/stream_buffer.c \
../source_rtos/FreeRTOS/tasks.c \
../source_rtos/FreeRTOS/timers.c 

OBJS += \
./source_rtos/FreeRTOS/event_groups.o \
./source_rtos/FreeRTOS/list.o \
./source_rtos/FreeRTOS/queue.o \
./source_rtos/FreeRTOS/stream_buffer.o \
./source_rtos/FreeRTOS/tasks.o \
./source_rtos/FreeRTOS/timers.o 

C_DEPS += \
./source_rtos/FreeRTOS/event_groups.d \
./source_rtos/FreeRTOS/list.d \
./source_rtos/FreeRTOS/queue.d \
./source_rtos/FreeRTOS/stream_buffer.d \
./source_rtos/FreeRTOS/tasks.d \
./source_rtos/FreeRTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
source_rtos/FreeRTOS/%.o source_rtos/FreeRTOS/%.su source_rtos/FreeRTOS/%.cyclo: ../source_rtos/FreeRTOS/%.c source_rtos/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-source_rtos-2f-FreeRTOS

clean-source_rtos-2f-FreeRTOS:
	-$(RM) ./source_rtos/FreeRTOS/event_groups.cyclo ./source_rtos/FreeRTOS/event_groups.d ./source_rtos/FreeRTOS/event_groups.o ./source_rtos/FreeRTOS/event_groups.su ./source_rtos/FreeRTOS/list.cyclo ./source_rtos/FreeRTOS/list.d ./source_rtos/FreeRTOS/list.o ./source_rtos/FreeRTOS/list.su ./source_rtos/FreeRTOS/queue.cyclo ./source_rtos/FreeRTOS/queue.d ./source_rtos/FreeRTOS/queue.o ./source_rtos/FreeRTOS/queue.su ./source_rtos/FreeRTOS/stream_buffer.cyclo ./source_rtos/FreeRTOS/stream_buffer.d ./source_rtos/FreeRTOS/stream_buffer.o ./source_rtos/FreeRTOS/stream_buffer.su ./source_rtos/FreeRTOS/tasks.cyclo ./source_rtos/FreeRTOS/tasks.d ./source_rtos/FreeRTOS/tasks.o ./source_rtos/FreeRTOS/tasks.su ./source_rtos/FreeRTOS/timers.cyclo ./source_rtos/FreeRTOS/timers.d ./source_rtos/FreeRTOS/timers.o ./source_rtos/FreeRTOS/timers.su

.PHONY: clean-source_rtos-2f-FreeRTOS

