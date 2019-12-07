################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
smartrf_settings/%.obj: ../smartrf_settings/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"D:/Programs/ti/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/ciara/Desktop/FYP/rfPacketRx_CC2650_LAUNCHXL_TI" --include_path="C:/Users/ciara/Desktop/FYP/rfPacketRx_CC2650_LAUNCHXL_TI" --include_path="C:/Users/ciara/Desktop/FYP/rfPacketRx_CC2650_LAUNCHXL_TI/smartrf_settings" --include_path="/products/cc26xxware_2_24_03_17272" --include_path="D:/Programs/ti/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/include" --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="smartrf_settings/$(basename $(<F)).d_raw" --obj_directory="smartrf_settings" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


