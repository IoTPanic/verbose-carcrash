VERSION_BASE = $(shell git describe --dirty --always --tags)
ROSS_COMPILE ?= arm-none-eabi-
CC := $(CROSS_COMPILE)gcc
AS := $(CROSS_COMPILE)as
CORTEX_M3 := -mcpu=cortex-m3
CORTEX_M4 := -mcpu=cortex-m4
CFLAGS = -fno-common -ffreestanding -O0 -std=gnu99 \
	 	 -gdwarf-2 -g3 -Wall -Werror \
	 	 -mthumb

#Universal Devices Defintion
include rules.mk

NAME = vcc-build-$(VERSION_BASE)

clean:
	rm -rf  $(RELEASE_DIR)

version:
	echo "Newest version should be $(NAME)"
