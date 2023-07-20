#
# Auto-generated file. Do not edit!
#

GCC_SPECS := D:/LoongIDE/mips-2011.03/mips-sde-elf/ls1b200
OS := rtthread

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include objects.mk
-include subdir.mk
-include RTThread/bsp-ls1x/subdir.mk
-include RTThread/bsp-ls1x/i2c/subdir.mk
-include RTThread/bsp-ls1x/spi/subdir.mk
-include RTThread/components/dfs/src/subdir.mk
-include RTThread/components/drivers/src/subdir.mk
-include RTThread/components/finsh/subdir.mk
-include RTThread/components/libc/compilers/newlib/subdir.mk
-include RTThread/components/libc/time/subdir.mk
-include RTThread/port/subdir.mk
-include RTThread/src/subdir.mk
-include ls1x-drv/subdir.mk
-include ls1x-drv/ac97/subdir.mk
-include ls1x-drv/can/subdir.mk
-include ls1x-drv/console/subdir.mk
-include ls1x-drv/fb/subdir.mk
-include ls1x-drv/fb/font/subdir.mk
-include ls1x-drv/gmac/subdir.mk
-include ls1x-drv/gpio/subdir.mk
-include ls1x-drv/i2c/subdir.mk
-include ls1x-drv/i2c/ads1015/subdir.mk
-include ls1x-drv/i2c/gp7101/subdir.mk
-include ls1x-drv/i2c/gt1151/subdir.mk
-include ls1x-drv/i2c/mcp4725/subdir.mk
-include ls1x-drv/i2c/pca9557/subdir.mk
-include ls1x-drv/i2c/rx8010/subdir.mk
-include ls1x-drv/nand/subdir.mk
-include ls1x-drv/pwm/subdir.mk
-include ls1x-drv/rtc/subdir.mk
-include ls1x-drv/spi/subdir.mk
-include ls1x-drv/spi/w25x40/subdir.mk
-include ls1x-drv/spi/xpt2046/subdir.mk
-include ls1x-drv/uart/subdir.mk
-include ls1x-drv/useful/subdir.mk
-include ls1x-drv/watchdog/subdir.mk
-include lvgl-7.0.1/porting/subdir.mk
-include modbus/app/subdir.mk
-include modbus/port/subdir.mk
-include modbus/src/subdir.mk
-include src/subdir.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
endif

-include ../makefile.defs

OUT_ELF=WaterDetect.exe
OUT_MAP=WaterDetect.map
OUT_BIN=WaterDetect.bin

LINKCMDS=../ld.script

# Add inputs and outputs from these tool invocations to the build variables

# All Target
all: $(OUT_ELF)

# Tool invocations
$(OUT_ELF): $(STARTO) $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MIPS SDE Lite C Linker'
	D:/LoongIDE/mips-2011.03/bin/mips-sde-elf-gcc.exe  -mips32 -G0 -EL -msoft-float -nostartfiles -static -T $(LINKCMDS) -o $(OUT_ELF) $(STARTO) $(OBJS) $(USER_OBJS) $(LIBS) -L"$(GCC_SPECS)/$(OS)" 
	@echo 'Invoking: MIPS SDE Lite C Objcopy'
	D:/LoongIDE/mips-2011.03/bin/mips-sde-elf-objcopy.exe -O binary $(OUT_ELF) $(OUT_BIN)
	@echo 'Invoking: MIPS SDE Lite C Size'
	D:/LoongIDE/mips-2011.03/bin/mips-sde-elf-size.exe $(OUT_ELF)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(STARTO) $(OBJS) $(C_DEPS) $(CPP_DEPS) $(ASM_DEPS) $(EXECUTABLES) $(OUT_ELF) $(OUT_MAP) $(OUT_BIN)
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets


