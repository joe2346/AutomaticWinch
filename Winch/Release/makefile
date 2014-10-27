################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include arduino/core/subdir.mk
-include Libraries/Timer-master/subdir.mk
-include Libraries/Servo/subdir.mk
-include Libraries/Encoder/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
C:/Users/joe/generalworkspace/Winch/Release/arduino.ar \

ELF += \
Winch.elf \

EEP += \
Winch.eep \

FLASH_IMAGE += \
Winch.hex \


# All Target
all: Winch

# Tool invocations
Winch: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"C:/Program Files/arduino-1.5.2/hardware/tools/avr/bin/avr-size" -A "C:/Users/joe/generalworkspace/Winch/Release/Winch.hex"
	@echo 'Finished building target: $@'
	@echo ' '

C:/Users/joe/generalworkspace/Winch/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"C:/Program Files/arduino-1.5.2/hardware/tools/avr/bin/avr-ar" rcs "C:/Users/joe/generalworkspace/Winch/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

Winch.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"C:/Program Files/arduino-1.5.2/hardware/tools/avr/bin/avr-gcc" -Os -Wl,--gc-sections -mmcu=atmega2560 -o "C:/Users/joe/generalworkspace/Winch/Release/Winch.elf"   $(LINK_OBJ) $(AR)  "C:/Users/joe/generalworkspace/Winch/Release/arduino.ar" "-LC:/Users/joe/generalworkspace/Winch/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

Winch.eep: $(ELF)
	@echo 'Create eeprom image'
	"C:/Program Files/arduino-1.5.2/hardware/tools/avr/bin/avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 "C:/Users/joe/generalworkspace/Winch/Release/Winch.elf" "C:/Users/joe/generalworkspace/Winch/Release/Winch.eep"
	@echo 'Finished building: $@'
	@echo ' '

Winch.hex: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"C:/Program Files/arduino-1.5.2/hardware/tools/avr/bin/avr-objcopy" -O ihex -R .eeprom "C:/Users/joe/generalworkspace/Winch/Release/Winch.elf" "C:/Users/joe/generalworkspace/Winch/Release/Winch.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(C_DEPS)$(AR)$(EEP)$(FLASH_IMAGE)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(SIZEDUMMY)$(ELF)$(CPP_DEPS) Winch
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
