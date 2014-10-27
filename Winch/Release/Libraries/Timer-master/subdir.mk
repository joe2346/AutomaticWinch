################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/joe/Desktop/New\ folder/Timer-master/Event.cpp \
C:/Users/joe/Desktop/New\ folder/Timer-master/Timer.cpp 

LINK_OBJ += \
./Libraries/Timer-master/Event.cpp.o \
./Libraries/Timer-master/Timer.cpp.o 

CPP_DEPS += \
./Libraries/Timer-master/Event.cpp.d \
./Libraries/Timer-master/Timer.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Timer-master/Event.cpp.o: C:/Users/joe/Desktop/New\ folder/Timer-master/Event.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:/Program Files/arduino-1.5.2/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=152    -I"C:\Program Files\arduino-1.5.2\hardware\arduino\avr\cores\arduino" -I"C:\Program Files\arduino-1.5.2\hardware\arduino\avr\variants\mega" -I"C:\Users\joe\Desktop\New folder\Encoder" -I"C:\Users\joe\Desktop\New folder\Timer-master" -I"C:\Program Files\arduino-1.5.2\hardware\arduino\avr\libraries\Servo" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Timer-master/Timer.cpp.o: C:/Users/joe/Desktop/New\ folder/Timer-master/Timer.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:/Program Files/arduino-1.5.2/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=152    -I"C:\Program Files\arduino-1.5.2\hardware\arduino\avr\cores\arduino" -I"C:\Program Files\arduino-1.5.2\hardware\arduino\avr\variants\mega" -I"C:\Users\joe\Desktop\New folder\Encoder" -I"C:\Users\joe\Desktop\New folder\Timer-master" -I"C:\Program Files\arduino-1.5.2\hardware\arduino\avr\libraries\Servo" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


