INCLUDE_N				= includes
OBJECTS_N 				= obj

MAKEFILE_N 				= Makefile

BOOT					= boot/
CPU 					= cpu/
KERNEL 					= kernel/
MEMORY 					= memory/

CURRENT_DIR 			= $(shell pwd)


all:

	$(MAKE) -C $(ROOT)$(BOOT) 		INCLUDES="$(INCLUDES)"
	$(MAKE) -C $(ROOT)$(CPU)		INCLUDES="$(INCLUDES)"
	$(MAKE) -C $(ROOT)$(KERNEL)		INCLUDES="$(INCLUDES)"
	$(MAKE) -C $(ROOT)$(MEMORY)		INCLUDES="$(INCLUDES)"

clean:

	$(MAKE) clean -C  $(BOOT)$(CORE_DIR)
	$(MAKE) clean -C  $(CPU)$(DISPLAY_DIR)
	$(MAKE) clean -C  $(KERNEL)$(ENTRY_DIR)
	$(MAKE) clean -C  $(MEMORY)$(LIBRARY_DIR)
