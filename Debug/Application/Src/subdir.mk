################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/Src/EC_Api.c \
../Application/Src/EC_Comm.c \
../Application/Src/EC_Manager.c 

OBJS += \
./Application/Src/EC_Api.o \
./Application/Src/EC_Comm.o \
./Application/Src/EC_Manager.o 

C_DEPS += \
./Application/Src/EC_Api.d \
./Application/Src/EC_Comm.d \
./Application/Src/EC_Manager.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Src/%.o Application/Src/%.su Application/Src/%.cyclo: ../Application/Src/%.c Application/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H753xx -c -I../Core/Inc -I../Application/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-Src

clean-Application-2f-Src:
	-$(RM) ./Application/Src/EC_Api.cyclo ./Application/Src/EC_Api.d ./Application/Src/EC_Api.o ./Application/Src/EC_Api.su ./Application/Src/EC_Comm.cyclo ./Application/Src/EC_Comm.d ./Application/Src/EC_Comm.o ./Application/Src/EC_Comm.su ./Application/Src/EC_Manager.cyclo ./Application/Src/EC_Manager.d ./Application/Src/EC_Manager.o ./Application/Src/EC_Manager.su

.PHONY: clean-Application-2f-Src

