################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Application/Window_Lifter.c" \

C_SRCS += \
../Sources/Application/Window_Lifter.c \

OBJS += \
./Sources/Application/Window_Lifter_c.obj \

OBJS_QUOTED += \
"./Sources/Application/Window_Lifter_c.obj" \

C_DEPS += \
./Sources/Application/Window_Lifter_c.d \

OBJS_OS_FORMAT += \
./Sources/Application/Window_Lifter_c.obj \

C_DEPS_QUOTED += \
"./Sources/Application/Window_Lifter_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/Application/Window_Lifter_c.obj: ../Sources/Application/Window_Lifter.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Application/Window_Lifter.args" -o "Sources/Application/Window_Lifter_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Application/%.d: ../Sources/Application/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


