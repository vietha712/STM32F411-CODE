PRO_DIR := .
PROJ_NAME := stm32f411_button_nvic
OUTPUT_PATH := $(PRO_DIR)/output

INC_DIR := $(PRO_DIR)/Inc
SRC_DIR := $(PRO_DIR)/Src
LINKER_FILE := $(PRO_DIR)/linker/gcc_arm.ld
GPIO_COMPILED_FILE := /mnt/9E9AE62B9AE6001F/Workspace/GPIO_driver/Compiled/gpio_driver.o
GPIO_INC_DIR := /mnt/9E9AE62B9AE6001F/Workspace/GPIO_driver/Inc

COMPILER_DIR := /home/hatheviet/Desktop/gcc-arm-none-eabi-7-2018-q2-update/

PREFIX_GCC_COMPILER := arm-none-eabi
CC := $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-gcc
OBJCPY := $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-objcopy
ASM := $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-as
LD := $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-ld

FILE_TO_LINK := $(OUTPUT_PATH)/main.o $(OUTPUT_PATH)/button_nvic.o $(OUTPUT_PATH)/startup_ARMCM4.o $(GPIO_COMPILED_FILE)

CC_OPT := -mcpu=cortex-m4 -c -O0 -g -mthumb -I$(INC_DIR) -I$(GPIO_INC_DIR)
ASM_OPT := -mcpu=cortex-m4 -c -mthumb
LD_OPT := -T $(LINKER_FILE) -Map $(OUTPUT_PATH)/$(PROJ_NAME).map $(FILE_TO_LINK)


$(OUTPUT_PATH)/main.o: $(SRC_DIR)/main.c
	@echo "compile $(SRC_DIR)/main.c file"
	$(CC) $(CC_OPT) $(SRC_DIR)/main.c -o $(OUTPUT_PATH)/main.o

$(OUTPUT_PATH)/button_nvic.o: $(SRC_DIR)/button_nvic.c
	@echo "compile $(SRC_DIR)/button_nvic.c file"
	$(CC) $(CC_OPT) $(SRC_DIR)/button_nvic.c -o $(OUTPUT_PATH)/button_nvic.o

$(OUTPUT_PATH)/startup_ARMCM4.o: $(SRC_DIR)/startup_ARMCM4.S
	@echo "compile $(SRC_DIR)/startup_ARMCM4.S file"
	$(ASM) $(ASM_OPT) $(SRC_DIR)/startup_ARMCM4.S -o $(OUTPUT_PATH)/startup_ARMCM4.o

build: $(FILE_TO_LINK) $(LINKER_FILE)
	@echo "Linking all object file and creating .elf file"
	$(LD) $(LD_OPT) -o $(OUTPUT_PATH)/$(PROJ_NAME).elf

delete_o:
	@rm -rf $(OUTPUT_PATH)/*


