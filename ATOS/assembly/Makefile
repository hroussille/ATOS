
SRCS := $(wildcard sources/*.S)
OBJS := $(addprefix obj/,$(notdir $(SRCS:.S=.o)))

CC 				= nasm
CFLAGS 			= -f elf32


all: 	$(OBJS)
		
obj/%.o: sources/%.S
		$(CC) $(CFLAGS) -o $@ $< $(INCLUDES)

clean : 
		rm -rf obj/*

fclean : clean
