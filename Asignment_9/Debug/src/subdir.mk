################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Asignment_9.cpp \
../src/LinkedList.cpp \
../src/queue.cpp 

OBJS += \
./src/Asignment_9.o \
./src/LinkedList.o \
./src/queue.o 

CPP_DEPS += \
./src/Asignment_9.d \
./src/LinkedList.d \
./src/queue.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


