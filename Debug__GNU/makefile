################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CG_TOOL_ROOT := /opt/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-4_8-2014q3

ORDERED_OBJS += \
"./LEDBlink.o" \
"./UpdateBase.o" \
"./UpdateBaseEmpty.o" \
"./UpdateManager.o" \
"./main.o" \
"./tickCounter.o" \
"./tm4c123gh6pm_startup_ccs_gcc.o" \
"./driverlib/adc.o" \
"./driverlib/aes.o" \
"./driverlib/can.o" \
"./driverlib/comp.o" \
"./driverlib/cpu.o" \
"./driverlib/crc.o" \
"./driverlib/des.o" \
"./driverlib/eeprom.o" \
"./driverlib/emac.o" \
"./driverlib/epi.o" \
"./driverlib/epi_workaround_ccs.o" \
"./driverlib/flash.o" \
"./driverlib/fpu.o" \
"./driverlib/gpio.o" \
"./driverlib/hibernate.o" \
"./driverlib/i2c.o" \
"./driverlib/interrupt.o" \
"./driverlib/lcd.o" \
"./driverlib/mpu.o" \
"./driverlib/onewire.o" \
"./driverlib/pwm.o" \
"./driverlib/qei.o" \
"./driverlib/shamd5.o" \
"./driverlib/ssi.o" \
"./driverlib/sw_crc.o" \
"./driverlib/sysctl.o" \
"./driverlib/sysexc.o" \
"./driverlib/systick.o" \
"./driverlib/timer.o" \
"./driverlib/uart.o" \
"./driverlib/udma.o" \
"./driverlib/usb.o" \
"./driverlib/watchdog.o" \
-Wl,-T"../tm4c123gh6pm.lds" \
"../driverlib/rvmdk/driverlib.lib" \
"../driverlib/ccs/Debug/driverlib.lib" \
$(GEN_CMDS__FLAG) \
-Wl,--start-group \
-l"c" \
-Wl,--end-group \

-include ../makefile.init

RM := rm -rf
RMDIR := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include driverlib/subdir_vars.mk
-include driverlib/rvmdk/subdir_vars.mk
-include driverlib/gcc/subdir_vars.mk
-include driverlib/ewarm/Exe/subdir_vars.mk
-include driverlib/ccs/Debug/subdir_vars.mk
-include subdir_rules.mk
-include driverlib/subdir_rules.mk
-include driverlib/rvmdk/subdir_rules.mk
-include driverlib/gcc/subdir_rules.mk
-include driverlib/ewarm/Exe/subdir_rules.mk
-include driverlib/ccs/Debug/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
TimingTesting.out \

EXE_OUTPUTS__QUOTED += \
"TimingTesting.out" \

BIN_OUTPUTS += \
TimingTesting.hex \

BIN_OUTPUTS__QUOTED += \
"TimingTesting.hex" \


# All Target
all: TimingTesting.out

# Tool invocations
TimingTesting.out: $(OBJS) $(CMD_SRCS) $(LDS_SRCS) $(LIB_SRCS) $(A_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU Linker'
	"/opt/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-4_8-2014q3/bin/arm-none-eabi-gcc" -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -Wl,-Map,"TimingTesting.map" -o"TimingTesting.out" $(ORDERED_OBJS) $(A_SRCS)
	@echo 'Finished building target: $@'
	@echo ' '

TimingTesting.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: GNU Objcopy Utility'
	"/opt/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-4_8-2014q3/bin/arm-none-eabi-objcopy"  $(EXE_OUTPUTS__QUOTED) "TimingTesting.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "LEDBlink.d" "UpdateBase.d" "UpdateBaseEmpty.d" "UpdateManager.d" "main.d" 
	-$(RM) "tickCounter.d" "tm4c123gh6pm_startup_ccs_gcc.d" "driverlib/adc.d" "driverlib/aes.d" "driverlib/can.d" "driverlib/comp.d" "driverlib/cpu.d" "driverlib/crc.d" "driverlib/des.d" "driverlib/eeprom.d" "driverlib/emac.d" "driverlib/epi.d" "driverlib/flash.d" "driverlib/fpu.d" "driverlib/gpio.d" "driverlib/hibernate.d" "driverlib/i2c.d" "driverlib/interrupt.d" "driverlib/lcd.d" "driverlib/mpu.d" "driverlib/onewire.d" "driverlib/pwm.d" "driverlib/qei.d" "driverlib/shamd5.d" "driverlib/ssi.d" "driverlib/sw_crc.d" "driverlib/sysctl.d" "driverlib/sysexc.d" "driverlib/systick.d" "driverlib/timer.d" "driverlib/uart.d" "driverlib/udma.d" "driverlib/usb.d" "driverlib/watchdog.d" 
	-$(RM) "driverlib/epi_workaround_ccs.d" 
	-$(RM) "LEDBlink.o" "UpdateBase.o" "UpdateBaseEmpty.o" "UpdateManager.o" "main.o" "tickCounter.o" "tm4c123gh6pm_startup_ccs_gcc.o" "driverlib/adc.o" "driverlib/aes.o" "driverlib/can.o" "driverlib/comp.o" "driverlib/cpu.o" "driverlib/crc.o" "driverlib/des.o" "driverlib/eeprom.o" "driverlib/emac.o" "driverlib/epi.o" "driverlib/epi_workaround_ccs.o" "driverlib/flash.o" "driverlib/fpu.o" "driverlib/gpio.o" "driverlib/hibernate.o" "driverlib/i2c.o" "driverlib/interrupt.o" "driverlib/lcd.o" "driverlib/mpu.o" "driverlib/onewire.o" "driverlib/pwm.o" "driverlib/qei.o" "driverlib/shamd5.o" "driverlib/ssi.o" "driverlib/sw_crc.o" "driverlib/sysctl.o" "driverlib/sysexc.o" "driverlib/systick.o" "driverlib/timer.o" "driverlib/uart.o" "driverlib/udma.o" "driverlib/usb.o" "driverlib/watchdog.o" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

