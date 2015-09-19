AS 				= nasm
CC 				= i686-elf-gcc


ASFLAGS			= -f elf32
CFLAGS 			= -std=gnu99 -ffreestanding -O2 -Wall -Wextra


LINKERSCRIPT  	= linker/linker.ld 
LINKERFLAGS		= -T $(LINKERSCRIPT) -ffreestanding -O2 -nostdlib
LD				= $(CC) $(LINKER) $(LINKERFLAGS)


SRCSDIR     	= ./ATOS
OBJSDIR     	= $(SRCSDIR)/objs/

SRCS      		= $(SRCSDIR)/entry/sources/entry.S \
				  $(SRCSDIR)/core/sources/kernel.c \
				  $(SRCSDIR)/display/basic/sources/vga.c \
				  $(SRCSDIR)/library/sources/strlen.c \


INCS			= -I $(SRCSDIR)/entry/includes/ \
				  -I $(SRCSDIR)/core/includes/ \
				  -I $(SRCSDIR)/display/basic/includes/ \
				  -I $(SRCSDIR)/library/includes/ \

NAME     		= release/boot/atos.bin

OBJSCC   		= $(SRCS:$(SRCSDIR)%.c=$(OBJSDIR)%.o) 
OBJSAS  		= $(SRCS:$(SRCSDIR)%.S=$(OBJSDIR)%.o)

RM 				= rm -rf 


all: $(NAME)

$(OBJSDIR)%.o: $(SRCSDIR)%.c
		$(CC) $(INCS) -c $< -o $(addprefix $(OBJSDIR), $(notdir $@))  $(CFLAGS)

$(OBJSDIR)%.o: $(SRCSDIR)%.S
		$(AS) $(INCS) $< -o $(addprefix $(OBJSDIR), $(notdir $@))  $(ASFLAGS)

$(NAME):   $(OBJSCC) $(OBJSAS)
		$(LD) -o $(NAME) $(OBJSDIR)*.o

iso: 

	grub-mkrescue -o atos.iso release/
		
clean: 
		$(RM) ATOS/objs/*.o

fclean: clean
		$(RM) $(NAME)
		$(RM) atos.iso