################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/DIO_program.c \
../Src/RCC_main.c \
../Src/RCC_program.c \
../Src/RTOS_program.c \
../Src/STK_program.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/DIO_program.o \
./Src/RCC_main.o \
./Src/RCC_program.o \
./Src/RTOS_program.o \
./Src/STK_program.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/DIO_program.d \
./Src/RCC_main.d \
./Src/RCC_program.d \
./Src/RTOS_program.d \
./Src/STK_program.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/DIO_program.d ./Src/DIO_program.o ./Src/DIO_program.su ./Src/RCC_main.d ./Src/RCC_main.o ./Src/RCC_main.su ./Src/RCC_program.d ./Src/RCC_program.o ./Src/RCC_program.su ./Src/RTOS_program.d ./Src/RTOS_program.o ./Src/RTOS_program.su ./Src/STK_program.d ./Src/STK_program.o ./Src/STK_program.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

