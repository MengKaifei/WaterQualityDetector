#
# Auto-Generated file. Do not edit!
#

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../RTThread/bsp-ls1x/i2c/drv_ads1015.c \
../RTThread/bsp-ls1x/i2c/drv_mcp4725.c \
../RTThread/bsp-ls1x/i2c/drv_pca9557.c \
../RTThread/bsp-ls1x/i2c/drv_rx8010.c

OBJS += \
./RTThread/bsp-ls1x/i2c/drv_ads1015.o \
./RTThread/bsp-ls1x/i2c/drv_mcp4725.o \
./RTThread/bsp-ls1x/i2c/drv_pca9557.o \
./RTThread/bsp-ls1x/i2c/drv_rx8010.o

C_DEPS += \
./RTThread/bsp-ls1x/i2c/drv_ads1015.d \
./RTThread/bsp-ls1x/i2c/drv_mcp4725.d \
./RTThread/bsp-ls1x/i2c/drv_pca9557.d \
./RTThread/bsp-ls1x/i2c/drv_rx8010.d

# Each subdirectory must supply rules for building sources it contributes
RTThread/bsp-ls1x/i2c/%.o: ../RTThread/bsp-ls1x/i2c/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MIPS SDE Lite C Compiler'
	D:/LoongIDE/mips-2011.03/bin/mips-sde-elf-gcc.exe -mips32 -G0 -EL -msoft-float -DLIB_YAFFS2 -DLIB_LWIP -DLIB_LVGL -DLS1B -DOS_RTTHREAD  -O0 -g -Wall -c -fmessage-length=0 -pipe -I"../" -I"../include" -I"../RTThread/include" -I"../RTThread/port/include" -I"../RTThread/port/mips" -I"../RTThread/components/finsh" -I"../RTThread/components/dfs/include" -I"../RTThread/components/drivers/include" -I"../RTThread/components/libc/time" -I"../RTThread/bsp-ls1x" -I"../ls1x-drv/include" -I"$(GCC_SPECS)/$(OS)/yaffs2" -I"$(GCC_SPECS)/$(OS)/lwIP-1.4.1" -I"$(GCC_SPECS)/$(OS)/lwIP-1.4.1/ipv4" -I"$(GCC_SPECS)/$(OS)/lvgl-7.0.1" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

