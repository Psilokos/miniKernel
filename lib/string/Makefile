##
## Makefile for string in /home/lecouv_v/LokiOS/kernel/lib/string
##
## Made by Victorien LE COUVIOUR--TUFFET
## Login   <lecouv_v@epitech.net>
##
## Started on  Fri Jul 24 00:58:09 2015 Victorien LE COUVIOUR--TUFFET
## Last update Sat Oct 15 02:08:05 2016 Victorien LE COUVIOUR--TUFFET
##

NAME	= libstring.a

SRCS	= src/memcpy.c

OBJS	= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		ar rc $(DIR_LIB)$(NAME) $(OBJS)
		ranlib $(DIR_LIB)$(NAME)

clean:
		@printf "\033[35m*\033[32m|\033[33m|—————————DELETING_STRING_LIBRARY_OBJECTS———————————|\033[32m|\033[35m*\n\033[0m"
		@$(RM) $(OBJS)
		@printf "\033[35m*\033[32m|\033[33m|\t       \033[30;47m{LIBRARY_OBJECTS_DELETED}\033[33;40m\t      |\033[32m|\033[35m*\n\033[0m"
		@printf "\033[35m*\033[32m|\033[33m|———————————————————————————————————————————————————|\033[32m|\033[35m*\n\033[0m"

fclean:		clean
		@$(RM) $(DIR_LIB)$(NAME)
		@printf "\033[35m*\033[32m|\t       \033[30;47m{STRING_LIBRARY_DELETED}\033[32;40m\t\t       |\033[35;40m*\n\033[0m"

re:		clean fclean all

.PHONY:		all clean fclean re
