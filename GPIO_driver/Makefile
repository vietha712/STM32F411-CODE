PRO_DIR := .
PRO_NAME := gpio_driver
OUTPUT_PATH := $(PRO_DIR)/Compiled

INC_DIR := $(PRO_DIR)/Inc
SRC_DIR := $(PRO_DIR)/Src

COMPILER_DIR := /home/hatheviet/Desktop/gcc-arm-none-eabi-7-2018-q2-update/

PREFIX_GCC_COMPILER := arm-none-eabi
CC := $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-gcc
CC_OPT := -mcpu=cortex-m4 -c -O0 -g -mthumb -I$(INC_DIR)

build : $(SRC_DIR)/$(PRO_NAME).c
	@echo "compiled $(SRC_DIR)/$(PRO_NAME).c to $(OUTPUT_PATH)/$(PRO_NAME).o"
	$(CC) $(CC_OPT) $(SRC_DIR)/$(PRO_NAME).c -o $(OUTPUT_PATH)/$(PRO_NAME).o

clearr:
	@rm -rf $(OUTPUT_PATH)/*
