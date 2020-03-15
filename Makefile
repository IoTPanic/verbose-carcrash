VERSION_BASE = $(shell git describe --dirty --always --tags)
ROSS_COMPILE ?= arm-none-eabi-
CC := $(CROSS_COMPILE)gcc
AS := $(CROSS_COMPILE)as

ifeq ($(CHIP_FAMILY), samd21)
COMMON_FLAGS = -mthumb -mcpu=cortex-m0plus -Os -g -DSAMD21
endif
ifeq ($(CHIP_FAMILY), samd51)
COMMON_FLAGS = -mthumb -mcpu=cortex-m4 -O2 -g -DSAMD51
endif


CFLAGS = -fno-common -ffreestanding -O0 -std=gnu99 \
	 	 -gdwarf-2 -g3 -Wall -Werror \
	 	 -mthumb

#Universal Devices Defintion
include rules.mk
#Create corresponding build command to the device
$(eval $(call eval_all_variable,$(STM32F429_DEVICE),$(STM32)))

NAME = vcc-build-$(VERSION_BASE)

define build_command
	mkdir -p $($(1)_RELEASE_DIR)
	$(CC) $(CFLAGS) $($(1)_CPU) -Wl,-T$($(1)_TARGET_ld) -nostartfiles \
		  $(addprefix -I,$($(1)_INC_DIR)) \
		  $(CORE_SOURCE) $($(1)_DEPENDENT_SOURCE) -o $($(1)_TARGET_elf)
	$(CROSS_COMPILE)objcopy -Obinary $($(1)_TARGET_elf) $($(1)_TARGET_bin)
	$(CROSS_COMPILE)objdump -S $($(1)_TARGET_elf) > $($(1)_TARGET_dump)
endef

define eval_build_command
$($(1)_TARGET):
	$(call build_command,$(1))
endef

$(eval $(call eval_build_command,$(STM32P103_DEVICE)))

PLAT ?= $(SAMD21G18A) #Default for now

target:
	$(call build_command,$(PLAT))

clean:
	rm -rf  $(RELEASE_DIR)

version:
	echo "Newest version should be $(NAME)"
