INCLUDE_N				= includes
OBJECTS_N 				= obj

MAKEFILE_N 				= Makefile

ROOT					= ATOS/

CORE_DIR 				= core/
CORE_BOOT				= core/boot/
CORE_CPU				= core/cpu/
CORE_KERNEL				= core/kernel/
CORE_MEMORY				= core/memory/
CORE_DEVICE				= core/device/

DISPLAY_DIR 			= display/
DISPLAY_BASIC_DIR 		= basic/

ASSEMBLY_DIR 			= assembly/
LIBRARY_DIR 			= library/

CURRENT_DIR 			= $(shell pwd)

INCLUDES_DIR 			= -I $(CURRENT_DIR)/$(ROOT)$(CORE_BOOT)$(INCLUDE_N) \
						  -I $(CURRENT_DIR)/$(ROOT)$(CORE_CPU)$(INCLUDE_N) \
						  -I $(CURRENT_DIR)/$(ROOT)$(CORE_KERNEL)$(INCLUDE_N) \
						  -I $(CURRENT_DIR)/$(ROOT)$(CORE_MEMORY)$(INCLUDE_N) \
			  			  -I $(CURRENT_DIR)/$(ROOT)$(CORE_DEVICE)$(INCLUDE_N) \
			  			  -I $(CURRENT_DIR)/$(ROOT)$(DISPLAY_DIR)$(DISPLAY_BASIC_DIR)$(INCLUDE_N) \
			  			  -I $(CURRENT_DIR)/$(ROOT)$(ENTRY_DIR)$(INCLUDE_N) \
			  			  -I $(CURRENT_DIR)/$(ROOT)$(LIBRARY_DIR)$(INCLUDE_N) \


OBJECTS_DIR 			= $(ROOT)$(CORE_DIR)$(OBJECTS_N)/* \
						  $(ROOT)$(DISPLAY_DIR)$(OBJECTS_N)/* \
						  $(ROOT)$(ASSEMBLY_DIR)$(OBJECTS_N)/* \
						  $(ROOT)$(LIBRARY_DIR)$(OBJECTS_N)/* \

CC 						= i686-elf-gcc
LD_SCRIPT				= linker/linker.ld
LD_FLAGS				= -T $(LD_SCRIPT) -ffreestanding -O2 -nostdlib
LD						= $(CC) $(LD_FLAGS)

NAME 					= release/boot/atos.bin
ISO_NAME				= atos.iso

all: 


	$(MAKE) -C $(ROOT)$(CORE_DIR) 		INCLUDES="$(INCLUDES_DIR)"
	$(MAKE) -C $(ROOT)$(DISPLAY_DIR)	INCLUDES="$(INCLUDES_DIR)"
	$(MAKE) -C $(ROOT)$(ASSEMBLY_DIR)		INCLUDES="$(INCLUDES_DIR)"
	$(MAKE) -C $(ROOT)$(LIBRARY_DIR)	INCLUDES="$(INCLUDES_DIR)"

	$(LD) -o $(NAME) $(OBJECTS_DIR)
	grub-mkrescue -o atos.iso release/


clean:

	$(MAKE) clean -C  $(ROOT)$(CORE_DIR)
	$(MAKE) clean -C  $(ROOT)$(DISPLAY_DIR)
	$(MAKE) clean -C  $(ROOT)$(ASSEMBLY_DIR)
	$(MAKE) clean -C  $(ROOT)$(LIBRARY_DIR)

	rm -rf $(NAME)
	rm -rf $(ISO_NAME)

