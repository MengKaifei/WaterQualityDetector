#
# Auto-Generated file. Do not edit!
#

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../RTThread/src/clock.c \
../RTThread/src/components.c \
../RTThread/src/cpu.c \
../RTThread/src/device.c \
../RTThread/src/idle.c \
../RTThread/src/ipc.c \
../RTThread/src/irq.c \
../RTThread/src/kservice.c \
../RTThread/src/mem.c \
../RTThread/src/memheap.c \
../RTThread/src/mempool.c \
../RTThread/src/object.c \
../RTThread/src/scheduler.c \
../RTThread/src/signal.c \
../RTThread/src/slab.c \
../RTThread/src/thread.c \
../RTThread/src/timer.c

OBJS += \
./RTThread/src/clock.o \
./RTThread/src/components.o \
./RTThread/src/cpu.o \
./RTThread/src/device.o \
./RTThread/src/idle.o \
./RTThread/src/ipc.o \
./RTThread/src/irq.o \
./RTThread/src/kservice.o \
./RTThread/src/mem.o \
./RTThread/src/memheap.o \
./RTThread/src/mempool.o \
./RTThread/src/object.o \
./RTThread/src/scheduler.o \
./RTThread/src/signal.o \
./RTThread/src/slab.o \
./RTThread/src/thread.o \
./RTThread/src/timer.o

C_DEPS += \
./RTThread/src/clock.d \
./RTThread/src/components.d \
./RTThread/src/cpu.d \
./RTThread/src/device.d \
./RTThread/src/idle.d \
./RTThread/src/ipc.d \
./RTThread/src/irq.d \
./RTThread/src/kservice.d \
./RTThread/src/mem.d \
./RTThread/src/memheap.d \
./RTThread/src/mempool.d \
./RTThread/src/object.d \
./RTThread/src/scheduler.d \
./RTThread/src/signal.d \
./RTThread/src/slab.d \
./RTThread/src/thread.d \
./RTThread/src/timer.d

# Each subdirectory must supply rules for building sources it contributes
RTThread/src/%.o: ../RTThread/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MIPS SDE Lite C Compiler'
	D:/LoongIDE/mips-2011.03/bin/mips-sde-elf-gcc.exe -mips32 -G0 -EL -msoft-float -DLIB_YAFFS2 -DLIB_LWIP -DLIB_LVGL -DLS1B -DOS_RTTHREAD  -O0 -g -Wall -c -fmessage-length=0 -pipe -I"../" -I"../include" -I"../RTThread/include" -I"../RTThread/port/include" -I"../RTThread/port/mips" -I"../RTThread/components/finsh" -I"../RTThread/components/dfs/include" -I"../RTThread/components/drivers/include" -I"../RTThread/components/libc/time" -I"../RTThread/bsp-ls1x" -I"../ls1x-drv/include" -I"$(GCC_SPECS)/$(OS)/yaffs2" -I"$(GCC_SPECS)/$(OS)/lwIP-1.4.1" -I"$(GCC_SPECS)/$(OS)/lwIP-1.4.1/ipv4" -I"$(GCC_SPECS)/$(OS)/lvgl-7.0.1" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

