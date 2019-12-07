################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
smartrf_settings/%.obj: ../smartrf_settings/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.4.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="D:/Code/rfPacketTx_CC2650_LAUNCHXL_TI" --include_path="D:/Code/rfPacketTx_CC2650_LAUNCHXL_TI" --include_path="D:/Code/rfPacketTx_CC2650_LAUNCHXL_TI/smartrf_settings" --include_path="C:/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/cc26xxware_2_24_03_17272" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.4.LTS/include" --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="smartrf_settings/$(basename $(<F)).d_raw" --obj_directory="smartrf_settings" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


