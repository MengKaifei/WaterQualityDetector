#
# Auto-Generated file. Do not edit!
#

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../RTThread/components/dfs/src/dfs.c \
../RTThread/components/dfs/src/dfs_file.c \
../RTThread/components/dfs/src/dfs_fs.c \
../RTThread/components/dfs/src/dfs_posix.c \
../RTThread/components/dfs/src/poll.c \
../RTThread/components/dfs/src/select.c

OBJS += \
./RTThread/components/dfs/src/dfs.o \
./RTThread/components/dfs/src/dfs_file.o \
./RTThread/components/dfs/src/dfs_fs.o \
./RTThread/components/dfs/src/dfs_posix.o \
./RTThread/components/dfs/src/poll.o \
./RTThread/components/dfs/src/select.o

C_DEPS += \
./RTThread/components/dfs/src/dfs.d \
./RTThread/components/dfs/src/dfs_file.d \
./RTThread/components/dfs/src/dfs_fs.d \
./RTThread/components/dfs/src/dfs_posix.d \
./RTThread/components/dfs/src/poll.d \
./RTThread/components/dfs/src/select.d

# Each subdirectory must supply rules for building sources it contributes
RTThread/components/dfs/src/%.o: ../RTThread/components/dfs/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MIPS SDE Lite C Compiler'
	D:/LoongIDE/mips-2011.03/bin/mips-sde-elf-gcc.exe -mips32 -G0 -EL -msoft-float -DLIB_YAFFS2 -DLIB_LWIP -DLIB_LVGL -DLS1B -DOS_RTTHREAD  -O0 -g -Wall -c -fmessage-length=0 -pipe -I"../" -I"../include" -I"../RTThread/include" -I"../RTThread/port/include" -I"../RTThread/port/mips" -I"../RTThread/components/finsh" -I"../RTThread/components/dfs/include" -I"../RTThread/components/drivers/include" -I"../RTThread/components/libc/time" -I"../RTThread/bsp-ls1x" -I"../ls1x-drv/include" -I"$(GCC_SPECS)/$(OS)/yaffs2" -I"$(GCC_SPECS)/$(OS)/lwIP-1.4.1" -I"$(GCC_SPECS)/$(OS)/lwIP-1.4.1/ipv4" -I"$(GCC_SPECS)/$(OS)/lvgl-7.0.1" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

