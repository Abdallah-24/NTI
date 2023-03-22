################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/DIO_program.c \
../Src/Delay.c \
../Src/LCD_prg.c \
../Src/PB_prg.c \
../Src/RCC_main.c \
../Src/RCC_program.c \
../Src/SSD_prg.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/DIO_program.o \
./Src/Delay.o \
./Src/LCD_prg.o \
./Src/PB_prg.o \
./Src/RCC_main.o \
./Src/RCC_program.o \
./Src/SSD_prg.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/DIO_program.d \
./Src/Delay.d \
./Src/LCD_prg.d \
./Src/PB_prg.d \
./Src/RCC_main.d \
./Src/RCC_program.d \
./Src/SSD_prg.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/DIO_program.d ./Src/DIO_program.o ./Src/DIO_program.su ./Src/Delay.d ./Src/Delay.o ./Src/Delay.su ./Src/LCD_prg.d ./Src/LCD_prg.o ./Src/LCD_prg.su ./Src/PB_prg.d ./Src/PB_prg.o ./Src/PB_prg.su ./Src/RCC_main.d ./Src/RCC_main.o ./Src/RCC_main.su ./Src/RCC_program.d ./Src/RCC_program.o ./Src/RCC_program.su ./Src/SSD_prg.d ./Src/SSD_prg.o ./Src/SSD_prg.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

