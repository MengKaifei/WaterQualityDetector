#
# Auto-Generated file. Do not edit!
#

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../RTThread/components/finsh/cmd.c \
../RTThread/components/finsh/finsh_compiler.c \
../RTThread/components/finsh/finsh_error.c \
../RTThread/components/finsh/finsh_heap.c \
../RTThread/components/finsh/finsh_init.c \
../RTThread/components/finsh/finsh_node.c \
../RTThread/components/finsh/finsh_ops.c \
../RTThread/components/finsh/finsh_parser.c \
../RTThread/components/finsh/finsh_token.c \
../RTThread/components/finsh/finsh_var.c \
../RTThread/components/finsh/finsh_vm.c \
../RTThread/components/finsh/msh.c \
../RTThread/components/finsh/msh_file.c \
../RTThread/components/finsh/shell.c \
../RTThread/components/finsh/symbol.c

OBJS += \
./RTThread/components/finsh/cmd.o \
./RTThread/components/finsh/finsh_compiler.o \
./RTThread/components/finsh/finsh_error.o \
./RTThread/components/finsh/finsh_heap.o \
./RTThread/components/finsh/finsh_init.o \
./RTThread/components/finsh/finsh_node.o \
./RTThread/components/finsh/finsh_ops.o \
./RTThread/components/finsh/finsh_parser.o \
./RTThread/components/finsh/finsh_token.o \
./RTThread/components/finsh/finsh_var.o \
./RTThread/components/finsh/finsh_vm.o \
./RTThread/components/finsh/msh.o \
./RTThread/components/finsh/msh_file.o \
./RTThread/components/finsh/shell.o \
./RTThread/components/finsh/symbol.o

C_DEPS += \
./RTThread/components/finsh/cmd.d \
./RTThread/components/finsh/finsh_compiler.d \
./RTThread/components/finsh/finsh_error.d \
./RTThread/components/finsh/finsh_heap.d \
./RTThread/components/finsh/finsh_init.d \
./RTThread/components/finsh/finsh_node.d \
./RTThread/components/finsh/finsh_ops.d \
./RTThread/components/finsh/finsh_parser.d \
./RTThread/components/finsh/finsh_token.d \
./RTThread/components/finsh/finsh_var.d \
./RTThread/components/finsh/finsh_vm.d \
./RTThread/components/finsh/msh.d \
./RTThread/components/finsh/msh_file.d \
./RTThread/components/finsh/shell.d \
./RTThread/components/finsh/symbol.d

# Each subdirectory must supply rules for building sources it contributes
RTThread/components/finsh/%.o: ../RTThread/components/finsh/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MIPS SDE Lite C Compiler'
	D:/LoongIDE/mips-2011.03/bin/mips-sde-elf-gcc.exe -mips32 -G0 -EL -msoft-float -DLIB_YAFFS2 -DLIB_LWIP -DLIB_LVGL -DLS1B -DOS_RTTHREAD  -O0 -g -Wall -c -fmessage-length=0 -pipe -I"../" -I"../include" -I"../RTThread/include" -I"../RTThread/port/include" -I"../RTThread/port/mips" -I"../RTThread/components/finsh" -I"../RTThread/components/dfs/include" -I"../RTThread/components/drivers/include" -I"../RTThread/components/libc/time" -I"../RTThread/bsp-ls1x" -I"../ls1x-drv/include" -I"$(GCC_SPECS)/$(OS)/yaffs2" -I"$(GCC_SPECS)/$(OS)/lwIP-1.4.1" -I"$(GCC_SPECS)/$(OS)/lwIP-1.4.1/ipv4" -I"$(GCC_SPECS)/$(OS)/lvgl-7.0.1" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

