################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Custom/Src/effects.c \
../Drivers/Custom/Src/pcm3010.c 

OBJS += \
./Drivers/Custom/Src/effects.o \
./Drivers/Custom/Src/pcm3010.o 

C_DEPS += \
./Drivers/Custom/Src/effects.d \
./Drivers/Custom/Src/pcm3010.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Custom/Src/%.o Drivers/Custom/Src/%.su Drivers/Custom/Src/%.cyclo: ../Drivers/Custom/Src/%.c Drivers/Custom/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Inc -I/home/ryanjeronimus/projects/stm_projects/audio_codec_v0/Drivers/Custom/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Custom-2f-Src

clean-Drivers-2f-Custom-2f-Src:
	-$(RM) ./Drivers/Custom/Src/effects.cyclo ./Drivers/Custom/Src/effects.d ./Drivers/Custom/Src/effects.o ./Drivers/Custom/Src/effects.su ./Drivers/Custom/Src/pcm3010.cyclo ./Drivers/Custom/Src/pcm3010.d ./Drivers/Custom/Src/pcm3010.o ./Drivers/Custom/Src/pcm3010.su

.PHONY: clean-Drivers-2f-Custom-2f-Src

