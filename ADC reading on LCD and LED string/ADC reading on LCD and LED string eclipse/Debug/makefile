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
battery_charge_status_on_leds_with_lcd.lss \

FLASH_IMAGE += \
battery_charge_status_on_leds_with_lcd.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: battery_charge_status_on_leds_with_lcd.elf secondary-outputs

# Tool invocations
battery_charge_status_on_leds_with_lcd.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,battery_charge_status_on_leds_with_lcd.map -mmcu=atmega32 -o "battery_charge_status_on_leds_with_lcd.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

battery_charge_status_on_leds_with_lcd.lss: battery_charge_status_on_leds_with_lcd.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S battery_charge_status_on_leds_with_lcd.elf  >"battery_charge_status_on_leds_with_lcd.lss"
	@echo 'Finished building: $@'
	@echo ' '

battery_charge_status_on_leds_with_lcd.hex: battery_charge_status_on_leds_with_lcd.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex battery_charge_status_on_leds_with_lcd.elf  "battery_charge_status_on_leds_with_lcd.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: battery_charge_status_on_leds_with_lcd.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 battery_charge_status_on_leds_with_lcd.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) battery_charge_status_on_leds_with_lcd.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
