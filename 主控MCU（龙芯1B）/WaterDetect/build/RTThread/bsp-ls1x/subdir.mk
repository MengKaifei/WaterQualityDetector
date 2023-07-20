#
# Auto-Generated file. Do not edit!
#

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../RTThread/bsp-ls1x/drv_can.c \
../RTThread/bsp-ls1x/drv_fb.c \
../RTThread/bsp-ls1x/drv_nand.c \
../RTThread/bsp-ls1x/drv_pwm.c \
../RTThread/bsp-ls1x/drv_uart.c \
../RTThread/bsp-ls1x/rt_ls1x_drv_init.c

OBJS += \
./RTThread/bsp-ls1x/drv_can.o \
./RTThread/bsp-ls1x/drv_fb.o \
./RTThread/bsp-ls1x/drv_nand.o \
./RTThread/bsp-ls1x/drv_pwm.o \
./RTThread/bsp-ls1x/drv_uart.o \
./RTThread/bsp-ls1x/rt_ls1x_drv_init.o

C_DEPS += \
./RTThread/bsp-ls1x/drv_can.d \
./RTThread/bsp-ls1x/drv_fb.d \
./RTThread/bsp-ls1x/drv_nand.d \
./RTThread/bsp-ls1x/drv_pwm.d \
./RTThread/bsp-ls1x/drv_uart.d \
./RTThread/bsp-ls1x/rt_ls1x_drv_init.d

# Each subdirectory must supply rules for building sources it contributes
RTThread/bsp-ls1x/%.o: ../RTThread/bsp-ls1x/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MIPS SDE Lite C Compiler'
	D:/LoongIDE/mips-2011.03/bin/mips-sde-elf-gcc.exe -mips32 -G0 -EL -msoft-float -DLIB_YAFFS2 -DLIB_LWIP -DLIB_LVGL -DLS1B -DOS_RTTHREAD  -O0 -g -Wall -c -fmessage-length=0 -pipe -I"../" -I"../include" -I"../RTThread/include" -I"../RTThread/port/include" -I"../RTThread/port/mips" -I"../RTThread/components/finsh" -I"../RTThread/components/dfs/include" -I"../RTThread/components/drivers/include" -I"../RTThread/components/libc/time" -I"../RTThread/bsp-ls1x" -I"../ls1x-drv/include" -I"$(GCC_SPECS)/$(OS)/yaffs2" -I"$(GCC_SPECS)/$(OS)/lwIP-1.4.1" -I"$(GCC_SPECS)/$(OS)/lwIP-1.4.1/ipv4" -I"$(GCC_SPECS)/$(OS)/lvgl-7.0.1" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

