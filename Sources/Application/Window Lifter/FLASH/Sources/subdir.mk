################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Button.c" \
"../Sources/Exceptions.c" \
"../Sources/GPIO.c" \
"../Sources/IntcInterrupts.c" \
"../Sources/PIT.c" \
"../Sources/PLL.c" \
"../Sources/Window_Lifter.c" \
"../Sources/ivor_branch_table.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/Button.c \
../Sources/Exceptions.c \
../Sources/GPIO.c \
../Sources/IntcInterrupts.c \
../Sources/PIT.c \
../Sources/PLL.c \
../Sources/Window_Lifter.c \
../Sources/ivor_branch_table.c \
../Sources/main.c \

OBJS += \
./Sources/Button_c.obj \
./Sources/Exceptions_c.obj \
./Sources/GPIO_c.obj \
./Sources/IntcInterrupts_c.obj \
./Sources/PIT_c.obj \
./Sources/PLL_c.obj \
./Sources/Window_Lifter_c.obj \
./Sources/ivor_branch_table_c.obj \
./Sources/main_c.obj \

OBJS_QUOTED += \
"./Sources/Button_c.obj" \
"./Sources/Exceptions_c.obj" \
"./Sources/GPIO_c.obj" \
"./Sources/IntcInterrupts_c.obj" \
"./Sources/PIT_c.obj" \
"./Sources/PLL_c.obj" \
"./Sources/Window_Lifter_c.obj" \
"./Sources/ivor_branch_table_c.obj" \
"./Sources/main_c.obj" \

C_DEPS += \
./Sources/Button_c.d \
./Sources/Exceptions_c.d \
./Sources/GPIO_c.d \
./Sources/IntcInterrupts_c.d \
./Sources/PIT_c.d \
./Sources/PLL_c.d \
./Sources/Window_Lifter_c.d \
./Sources/ivor_branch_table_c.d \
./Sources/main_c.d \

OBJS_OS_FORMAT += \
./Sources/Button_c.obj \
./Sources/Exceptions_c.obj \
./Sources/GPIO_c.obj \
./Sources/IntcInterrupts_c.obj \
./Sources/PIT_c.obj \
./Sources/PLL_c.obj \
./Sources/Window_Lifter_c.obj \
./Sources/ivor_branch_table_c.obj \
./Sources/main_c.obj \

C_DEPS_QUOTED += \
"./Sources/Button_c.d" \
"./Sources/Exceptions_c.d" \
"./Sources/GPIO_c.d" \
"./Sources/IntcInterrupts_c.d" \
"./Sources/PIT_c.d" \
"./Sources/PLL_c.d" \
"./Sources/Window_Lifter_c.d" \
"./Sources/ivor_branch_table_c.d" \
"./Sources/main_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/Button_c.obj: ../Sources/Button.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Button.args" -o "Sources/Button_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/Exceptions_c.obj: ../Sources/Exceptions.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Exceptions.args" -o "Sources/Exceptions_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/GPIO_c.obj: ../Sources/GPIO.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/GPIO.args" -o "Sources/GPIO_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/IntcInterrupts_c.obj: ../Sources/IntcInterrupts.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/IntcInterrupts.args" -o "Sources/IntcInterrupts_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/PIT_c.obj: ../Sources/PIT.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/PIT.args" -o "Sources/PIT_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/PLL_c.obj: ../Sources/PLL.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/PLL.args" -o "Sources/PLL_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Window_Lifter_c.obj: ../Sources/Window_Lifter.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Window_Lifter.args" -o "Sources/Window_Lifter_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/ivor_branch_table_c.obj: ../Sources/ivor_branch_table.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/ivor_branch_table.args" -o "Sources/ivor_branch_table_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/main.args" -o "Sources/main_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


