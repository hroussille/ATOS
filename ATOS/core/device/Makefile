
SRCS := $(wildcard sources/*.c)

OBJS := $(addprefix ../obj/,$(notdir $(SRCS:.c=.o)))

CC 				= i686-elf-gcc
CFLAGS 			= -std=gnu99 -ffreestanding -O2 -Wall -Wextra

all: 	$(OBJS)
		
../obj/%.o: sources/%.c
		$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean : 
		rm -rf ../obj/*

fclean : clean

