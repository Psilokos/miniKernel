##
## Makefile for LokiOS in /home/lecouv_v/LokiOS/kernel/lib
##
## Made by Victorien LE COUVIOUR--TUFFET
## Login   <lecouv_v@epitech.net>
##
## Started on  Thu Jul 23 18:15:53 2015 Victorien LE COUVIOUR--TUFFET
## Last update Sat Oct 15 01:57:28 2016 Victorien LE COUVIOUR--TUFFET
##

all:	lib

export CC	= $(WDIR)/opt/cross/bin/i686-elf-gcc
export CFLAGS	= -Wall -Werror -Wextra
export CFLAGS	+= -I $(DIR_INC) $(DIR_LIB_INC)

lib:
	@make -C string all --no-print-directory

clean:
	@printf "\033[35m*\033[32m|————————————DELETING_LIBRARIES_OBJECTS———————————————|\033[35m*\n\033[0m"
	@make -C string clean --no-print-directory
	@printf "\033[35m*\033[32m|—————————————————————————————————————————————————————|\033[35m*\n\033[0m"

fclean:
	@printf "\033[35m*\033[32m|—————————————————DELETING_LIBRARIES——————————————————|\033[35m*\n\033[0m"
	@make -C string fclean --no-print-directory
	@printf "\033[35m*\033[32m|—————————————————————————————————————————————————————|\033[35m*\n\033[0m"

re:
	@make -C string re --no-print-directory

.PHONY: lib clean fclean re
