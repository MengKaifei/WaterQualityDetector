#
# Auto-Generated file. Do not edit!
#

# Add inputs and outputs from these tool invocations to the build variables
ASM_SRCS += \
../RTThread/port/cache.S \
../RTThread/port/context.S \
../RTThread/port/irq_s.S \
../RTThread/port/mips_timer.S \
../RTThread/port/start.S \
../RTThread/port/tlb.S

C_SRCS += \
../RTThread/port/bsp_start.c \
../RTThread/port/exception.c \
../RTThread/port/inittlb.c \
../RTThread/port/irq.c \
../RTThread/port/stack.c \
../RTThread/port/tick.c

STARTO += ./RTThread/port/start.o

OBJS += \
./RTThread/port/bsp_start.o \
./RTThread/port/cache.o \
./RTThread/port/context.o \
./RTThread/port/exception.o \
./RTThread/port/inittlb.o \
./RTThread/port/irq.o \
./RTThread/port/irq_s.o \
./RTThread/port/mips_timer.o \
./RTThread/port/stack.o \
./RTThread/port/tick.o \
./RTThread/port/tlb.o

ASM_DEPS += \
./RTThread/port/cache.d \
./RTThread/port/context.d \
./RTThread/port/irq_s.d \
./RTThread/port/mips_timer.d \
./RTThread/port/start.d \
./RTThread/port/tlb.d

C_DEPS += \
./RTThread/port/bsp_start.d \
./RTThread/port/exception.d \
./RTThread/port/inittlb.d \
./RTThread/port/irq.d \
./RTThread/port/stack.d \
./RTThread/port/tick.d

# Each subdirectory must supply rules for building sources it contributes
RTThread/port/%.o: ../RTThread/port/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: MIPS SDE Lite C Compiler'
	D:/LoongIDE/mips-2011.03/bin/mips-sde-elf-gcc.exe -mips32 -G0 -EL -msoft-float -DLS1B -DOS_RTTHREAD  -O0 -g -Wall -c -fmessage-length=0 -pipe -I"../" -I"../include" -I"../RTThread/port/mips" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTThread/port/%.o: ../RTThread/port/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MIPS SDE Lite C Compiler'
	D:/LoongIDE/mips-2011.03/bin/mips-sde-elf-gcc.exe -mips32 -G0 -EL -msoft-float -DLIB_YAFFS2 -DLIB_LWIP -DLIB_LVGL -DLS1B -DOS_RTTHREAD  -O0 -g -Wall -c -fmessage-length=0 -pipe -I"../" -I"../include" -I"../RTThread/include" -I"../RTThread/port/include" -I"../RTThread/port/mips" -I"../RTThread/components/finsh" -I"../RTThread/components/dfs/include" -I"../RTThread/components/drivers/include" -I"../RTThread/components/libc/time" -I"../RTThread/bsp-ls1x" -I"../ls1x-drv/include" -I"$(GCC_SPECS)/$(OS)/yaffs2" -I"$(GCC_SPECS)/$(OS)/lwIP-1.4.1" -I"$(GCC_SPECS)/$(OS)/lwIP-1.4.1/ipv4" -I"$(GCC_SPECS)/$(OS)/lvgl-7.0.1" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

