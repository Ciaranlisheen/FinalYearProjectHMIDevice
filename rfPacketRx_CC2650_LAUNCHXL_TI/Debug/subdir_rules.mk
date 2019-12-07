################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"D:/Programs/ti/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/ciara/Desktop/FYP/rfPacketRx_CC2650_LAUNCHXL_TI" --include_path="C:/Users/ciara/Desktop/FYP/rfPacketRx_CC2650_LAUNCHXL_TI" --include_path="C:/Users/ciara/Desktop/FYP/rfPacketRx_CC2650_LAUNCHXL_TI/smartrf_settings" --include_path="/products/cc26xxware_2_24_03_17272" --include_path="D:/Programs/ti/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/include" --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1390777569:
	@$(MAKE) --no-print-directory -Onone -f subdir_rules.mk build-1390777569-inproc

build-1390777569-inproc: ../rfExamples.cfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: XDCtools'
	"D:/Programs/ti/xdctools_3_60_01_27_core/xs" --xdcpath= xdc.tools.configuro -o configPkg -t ti.targets.arm.elf.M3 -p ti.platforms.simplelink:CC2650F128 -r release -c "D:/Programs/ti/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS" --compileOptions "-mv7M3 --code_state=16 --float_support=vfplib -me --include_path=\"C:/Users/ciara/Desktop/FYP/rfPacketRx_CC2650_LAUNCHXL_TI\" --include_path=\"C:/Users/ciara/Desktop/FYP/rfPacketRx_CC2650_LAUNCHXL_TI\" --include_path=\"C:/Users/ciara/Desktop/FYP/rfPacketRx_CC2650_LAUNCHXL_TI/smartrf_settings\" --include_path=\"/products/cc26xxware_2_24_03_17272\" --include_path=\"D:/Programs/ti/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/include\" --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi  " "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

configPkg/linker.cmd: build-1390777569 ../rfExamples.cfg
configPkg/compiler.opt: build-1390777569
configPkg/: build-1390777569


