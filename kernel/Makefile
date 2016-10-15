##
## Makefile for kernel in /home/lecouv_v/kernel/kernel
##
## Made by Victorien LE COUVIOUR--TUFFET
## Login   <lecouv_v@epitech.net>
##
## Started on  Fri Jul 10 14:21:15 2015 Victorien LE COUVIOUR--TUFFET
## Last update Sat Oct 15 01:46:58 2016 Victorien LE COUVIOUR--TUFFET
##

NAME		= kernel

ASFLAGS		= -f elf

CC		= ../opt/cross/bin/i686-elf-gcc
CFLAGS		+= -Wall -Werror -Wextra
CFLAGS		+= -I $(DIR_INC) -I $(DIR_K_INC) -I $(DIR_LIB_INC)
CFLAGS		+= -masm=intel -g

LD		= ../opt/cross/bin/i686-elf-ld
LDFLAGS		= --oformat binary -Ttext 0x10000 -m elf_i386

SRCS_ASM	=

SRCS_C		= gdt.c			\
		  idt.c			\
		  interrupt.c		\
		  pic.c			\
		  screen.c

OBJS_ASM	= $(SRCS_ASM:.s=.o)

OBJS_C		= $(SRCS_C:.c=.o)

LINE_LEN	= 53
LEFT_SHIFT	= 0
RIGHT_SHIFT	= 0

all:		$(NAME)

$(NAME):	$(OBJS_ASM) $(OBJS_C) _start.o
		@$(LD) $(LDFLAGS) _start.o $(OBJS_ASM) $(OBJS_C) -o $@ $(DIR_LIB)libstring.a
		@printf "\033[31m>\033[35m*///////////////////\033[4;34;43m{KERNEL-LINKED}\033[24;35;40m\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\033[35m*\033[31;40m<\n\033[0m"

%.o:		%.s
		@$(AS) $(ASFLAGS) $< -o $@
		$(eval LEFT_SHIFT = $(shell echo $(shell echo $(LINE_LEN) - $(shell python ../strlen.py $<) - $(shell python ../strlen.py " assembled") | bc) / 2 + 1 | bc))
		$(eval RIGHT_SHIFT = $(shell echo $(shell echo $(LINE_LEN) - $(shell python ../strlen.py $<) - $(shell python ../strlen.py " assembled") | bc) / 2 - $(shell python ../strlen.py $<) % 2 | bc))
		@printf "\033[31m>\033[35m*%$(LEFT_SHIFT)s\033[1;32m$< assembled\033[0m%$(RIGHT_SHIFT)s\033[35m*\033[31m<\n\033[0m"

%.o:		%.c
		@$(CC) $(CFLAGS) -c $< -o $@
		$(eval LEFT_SHIFT = $(shell echo $(shell echo $(LINE_LEN) - $(shell python ../strlen.py $<) - $(shell python ../strlen.py " compiled") | bc) / 2 + $(shell python ../strlen.py $<) % 2 | bc))
		$(eval RIGHT_SHIFT = $(shell echo $(shell echo $(LINE_LEN) - $(shell python ../strlen.py $<) - $(shell python ../strlen.py " compiled") | bc) / 2 - 1 + $(shell echo $(shell python ../strlen.py $<) + 1 | bc) % 2 + $(shell python ../strlen.py $<) % 2 | bc))
		@printf "\033[31m>\033[35m*%$(LEFT_SHIFT)s\033[1;36m$< compiled\033[0m%$(RIGHT_SHIFT)s\033[35m*\033[31m<\n\033[0m"

clean:
		@$(RM) _start.o $(OBJS_ASM) $(OBJS_C)
		@printf "\033[35m*\033[34m|—————————————DELETING_KERNEL_OBJECTS—————————————————|\033[35m*\n\033[0m"
		@printf "\033[35m*\033[34m|\t       \033[30;47m{KERNEL_OBJECTS_DELETED}\033[34;40m\t\t       |\033[35m*\n\033[0m"
		@printf "\033[35m*\033[34m|—————————————————————————————————————————————————————|\033[35m*\n\033[0m"

fclean:		clean
		@$(RM) $(NAME)
		@printf "\033[35m*\t\t  \033[30;47m{KERNEL_DELETED}\t\t\t\033[35;40m*\n\033[0m"

re: fclean all

.PHONY: all clean fclean re
