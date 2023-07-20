#
# Auto-Generated file. Do not edit!
#

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../lvgl-7.0.1/porting/lv_port_disp.c \
../lvgl-7.0.1/porting/lv_port_fs.c \
../lvgl-7.0.1/porting/lv_port_indev.c

OBJS += \
./lvgl-7.0.1/porting/lv_port_disp.o \
./lvgl-7.0.1/porting/lv_port_fs.o \
./lvgl-7.0.1/porting/lv_port_indev.o

C_DEPS += \
./lvgl-7.0.1/porting/lv_port_disp.d \
./lvgl-7.0.1/porting/lv_port_fs.d \
./lvgl-7.0.1/porting/lv_port_indev.d

# Each subdirectory must supply rules for building sources it contributes
lvgl-7.0.1/porting/%.o: ../lvgl-7.0.1/porting/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MIPS SDE Lite C Compiler'
	D:/LoongIDE/mips-2011.03/bin/mips-sde-elf-gcc.exe -mips32 -G0 -EL -msoft-float -DLIB_YAFFS2 -DLIB_LWIP -DLIB_LVGL -DLS1B -DOS_RTTHREAD  -O0 -g -Wall -c -fmessage-length=0 -pipe -I"../" -I"../include" -I"../RTThread/include" -I"../RTThread/port/include" -I"../RTThread/port/mips" -I"../RTThread/components/finsh" -I"../RTThread/components/dfs/include" -I"../RTThread/components/drivers/include" -I"../RTThread/components/libc/time" -I"../RTThread/bsp-ls1x" -I"../ls1x-drv/include" -I"$(GCC_SPECS)/$(OS)/yaffs2" -I"$(GCC_SPECS)/$(OS)/lwIP-1.4.1" -I"$(GCC_SPECS)/$(OS)/lwIP-1.4.1/ipv4" -I"$(GCC_SPECS)/$(OS)/lvgl-7.0.1" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

