RELEASE_DIR      := ./release
PLATFORM_DIR     := ./platform
CMSIS_DIR        := ./cmsis
CORE_DIR         := ./core
INC_DIR          := include
SRC_DIR          := src
CORE_HEADER_DIR  := $(CORE_DIR)/$(INC_DIR)/

CORE_SOURCE  := $(wildcard $(CORE_DIR)/$(SRC_DIR)/*.c)