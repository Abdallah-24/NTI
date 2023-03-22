################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ADC_prg.c \
../Src/Cooler_program.c \
../Src/DIO_program.c \
../Src/EXTI_program.c \
../Src/Heater_program.c \
../Src/NVIC_program.c \
../Src/RCC_program.c \
../Src/SSD_prg.c \
../Src/STK_program.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/ADC_prg.o \
./Src/Cooler_program.o \
./Src/DIO_program.o \
./Src/EXTI_program.o \
./Src/Heater_program.o \
./Src/NVIC_program.o \
./Src/RCC_program.o \
./Src/SSD_prg.o \
./Src/STK_program.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/ADC_prg.d \
./Src/Cooler_program.d \
./Src/DIO_program.d \
./Src/EXTI_program.d \
./Src/Heater_program.d \
./Src/NVIC_program.d \
./Src/RCC_program.d \
./Src/SSD_prg.d \
./Src/STK_program.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/ADC_prg.d ./Src/ADC_prg.o ./Src/ADC_prg.su ./Src/Cooler_program.d ./Src/Cooler_program.o ./Src/Cooler_program.su ./Src/DIO_program.d ./Src/DIO_program.o ./Src/DIO_program.su ./Src/EXTI_program.d ./Src/EXTI_program.o ./Src/EXTI_program.su ./Src/Heater_program.d ./Src/Heater_program.o ./Src/Heater_program.su ./Src/NVIC_program.d ./Src/NVIC_program.o ./Src/NVIC_program.su ./Src/RCC_program.d ./Src/RCC_program.o ./Src/RCC_program.su ./Src/SSD_prg.d ./Src/SSD_prg.o ./Src/SSD_prg.su ./Src/STK_program.d ./Src/STK_program.o ./Src/STK_program.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

