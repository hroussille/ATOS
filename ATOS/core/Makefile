INCLUDE_N				= includes
OBJECTS_N 				= obj

MAKEFILE_N 				= Makefile

BOOT					= boot/
CPU 					= cpu/
KERNEL 					= kernel/
MEMORY 					= memory/
DEVICE					= device/

CURRENT_DIR 			= $(shell pwd)


all:

	$(MAKE) -C $(ROOT)$(BOOT) 		INCLUDES="$(INCLUDES)"
	$(MAKE) -C $(ROOT)$(CPU)		INCLUDES="$(INCLUDES)"
	$(MAKE) -C $(ROOT)$(KERNEL)		INCLUDES="$(INCLUDES)"
	$(MAKE) -C $(ROOT)$(MEMORY)		INCLUDES="$(INCLUDES)"
	$(MAKE) -C $(ROOT)$(DEVICE)		INCLUDES="$(INCLUDES)"

clean:

	$(MAKE) clean -C  $(BOOT)
	$(MAKE) clean -C  $(CPU)
	$(MAKE) clean -C  $(KERNEL)
	$(MAKE) clean -C  $(MEMORY)
	$(MAKE) clean -C  $(DEVICE)
