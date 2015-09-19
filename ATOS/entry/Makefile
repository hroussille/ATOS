vpath %.S ./sources

CC 				= nasm
CFLAGS 			= -f elf32

SRCS 			= entry.S \

OBJS			= $(patsubst %.S,obj/%.o,$(SRCS))

$(OBJS): | obj

obj :
	@mkdir -p $@

obj/%.o : %.S
	@echo $<
	@$(CC) $(CFLAGS) $< -o $@ $(INCLUDES)

clean : 

		rm -rf obj

fclean : clean
