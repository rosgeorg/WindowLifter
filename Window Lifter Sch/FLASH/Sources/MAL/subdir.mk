################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/MAL/LED.c" \
"../Sources/MAL/Scheduler.c" \
"../Sources/MAL/Scheduler_task.c" \
"../Sources/MAL/button.c" \

C_SRCS += \
../Sources/MAL/LED.c \
../Sources/MAL/Scheduler.c \
../Sources/MAL/Scheduler_task.c \
../Sources/MAL/button.c \

OBJS += \
./Sources/MAL/LED_c.obj \
./Sources/MAL/Scheduler_c.obj \
./Sources/MAL/Scheduler_task_c.obj \
./Sources/MAL/button_c.obj \

OBJS_QUOTED += \
"./Sources/MAL/LED_c.obj" \
"./Sources/MAL/Scheduler_c.obj" \
"./Sources/MAL/Scheduler_task_c.obj" \
"./Sources/MAL/button_c.obj" \

C_DEPS += \
./Sources/MAL/LED_c.d \
./Sources/MAL/Scheduler_c.d \
./Sources/MAL/Scheduler_task_c.d \
./Sources/MAL/button_c.d \

OBJS_OS_FORMAT += \
./Sources/MAL/LED_c.obj \
./Sources/MAL/Scheduler_c.obj \
./Sources/MAL/Scheduler_task_c.obj \
./Sources/MAL/button_c.obj \

C_DEPS_QUOTED += \
"./Sources/MAL/LED_c.d" \
"./Sources/MAL/Scheduler_c.d" \
"./Sources/MAL/Scheduler_task_c.d" \
"./Sources/MAL/button_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/MAL/LED_c.obj: ../Sources/MAL/LED.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/MAL/LED.args" -o "Sources/MAL/LED_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/MAL/%.d: ../Sources/MAL/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/MAL/Scheduler_c.obj: ../Sources/MAL/Scheduler.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/MAL/Scheduler.args" -o "Sources/MAL/Scheduler_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/MAL/Scheduler_task_c.obj: ../Sources/MAL/Scheduler_task.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/MAL/Scheduler_task.args" -o "Sources/MAL/Scheduler_task_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/MAL/button_c.obj: ../Sources/MAL/button.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/MAL/button.args" -o "Sources/MAL/button_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


