################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mini\ Project\ 2.c 

OBJS += \
./Mini\ Project\ 2.o 

C_DEPS += \
./Mini\ Project\ 2.d 


# Each subdirectory must supply rules for building sources it contributes
Mini\ Project\ 2.o: ../Mini\ Project\ 2.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"Mini Project 2.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


