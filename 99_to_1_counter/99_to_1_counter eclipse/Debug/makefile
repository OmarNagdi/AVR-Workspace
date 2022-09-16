################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
1_to_99_counter.lss \

FLASH_IMAGE += \
1_to_99_counter.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: 1_to_99_counter.elf secondary-outputs

# Tool invocations
1_to_99_counter.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,1_to_99_counter.map -mmcu=atmega32 -o "1_to_99_counter.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

1_to_99_counter.lss: 1_to_99_counter.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 1_to_99_counter.elf  >"1_to_99_counter.lss"
	@echo 'Finished building: $@'
	@echo ' '

1_to_99_counter.hex: 1_to_99_counter.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 1_to_99_counter.elf  "1_to_99_counter.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 1_to_99_counter.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 1_to_99_counter.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 1_to_99_counter.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
