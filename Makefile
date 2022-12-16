NAME = so_long.out

LIBRARY = ft_printf/libftprintf.a
GCC = gcc
SRC = so_long.c utils.c maps.c ft_splitnl.c render.c hook.c display_map.c mapinit.c
CFLAGS = -g -Wall -Wextra -Werror
LINKS = libmlx_Linux.a -lXext -lX11 -lm
PRINTF = ft_printf
RM	= rm -f
OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	@make -C $(PRINTF)
	$(GCC) -no-pie $(CFLAGS) $(OBJ) $(LIBRARY) $(LINKS) -o $(NAME)

clean:
	@make clean -C $(PRINTF)
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C $(PRINTF)
	@rm -rf $(NAME)

re: fclean all