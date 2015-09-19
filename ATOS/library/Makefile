vpath %.c ./sources

CC 				= i686-elf-gcc
CFLAGS 			= -std=gnu99 -ffreestanding -O2 -Wall -Wextra

SRCS 	= strlen.c \

OBJS	= $(patsubst %.c,obj/%.o,$(SRCS))

$(OBJS): | obj

obj :
	@mkdir -p $@

obj/%.o : %.c
	@echo $<
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean : 
		rm -rf obj

fclean : clean
