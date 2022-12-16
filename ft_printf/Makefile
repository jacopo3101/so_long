CC=gcc

CFLAGS=-Wall -Wextra -Werror -I.

NAME	= libftprintf.a

FILES	= ft_printf.c ft_utils.c ft_print_format.c ft_print_hex.c ft_unsigned_itoa.c

LIBFT	= libft

RM	= rm -f

OBJECTS=$(FILES:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJECTS)
			@make -C ../$(LIBFT)
			@cp ../libft/libft.a .
			@mv libft.a $(NAME)
			ar rsc $(NAME) $(OBJECTS)
			
clean:
			@$(RM) $(OBJECTS)
			@make clean -C ../$(LIBFT)
			
fclean:	clean
			@$(RM) $(NAME)
			@$(RM) ../$(LIBFT)/libft.a
			
re:		fclean all

bonus: all

.PHONY:		all clean fclean re
