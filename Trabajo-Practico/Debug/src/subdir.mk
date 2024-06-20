################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/barrio.cpp \
../src/inicializar_datos.cpp \
../src/lecturaDeArchivos.cpp \
../src/linea.cpp \
../src/main.cpp \
../src/menu.cpp \
../src/parada.cpp \
../src/punto_2.cpp \
../src/punto_3.cpp \
../src/punto_4.cpp \
../src/punto_5.cpp 

CPP_DEPS += \
./src/barrio.d \
./src/inicializar_datos.d \
./src/lecturaDeArchivos.d \
./src/linea.d \
./src/main.d \
./src/menu.d \
./src/parada.d \
./src/punto_2.d \
./src/punto_3.d \
./src/punto_4.d \
./src/punto_5.d 

OBJS += \
./src/barrio.o \
./src/inicializar_datos.o \
./src/lecturaDeArchivos.o \
./src/linea.o \
./src/main.o \
./src/menu.o \
./src/parada.o \
./src/punto_2.o \
./src/punto_3.o \
./src/punto_4.o \
./src/punto_5.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/barrio.d ./src/barrio.o ./src/inicializar_datos.d ./src/inicializar_datos.o ./src/lecturaDeArchivos.d ./src/lecturaDeArchivos.o ./src/linea.d ./src/linea.o ./src/main.d ./src/main.o ./src/menu.d ./src/menu.o ./src/parada.d ./src/parada.o ./src/punto_2.d ./src/punto_2.o ./src/punto_3.d ./src/punto_3.o ./src/punto_4.d ./src/punto_4.o ./src/punto_5.d ./src/punto_5.o

.PHONY: clean-src

