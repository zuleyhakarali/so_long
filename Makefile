NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux

SRC = main.c is_valid.c utils.c mlibx_part.c move.c utils2.c image_part.c
OBJS = $(SRC:.c=.o)

LIB = libft/libft.a
PRINTF = ft_printf/libftprintf.a
MLX = minilibx-linux/libmlx.a
GNL = get_next_line/get_next_line.a

MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

all: $(LIB) $(PRINTF) $(GNL) $(MLX) $(NAME)

$(NAME): $(OBJS) $(GNL) $(LIB) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(GNL) $(LIB) $(PRINTF) $(MLX_FLAGS) -o $(NAME)

$(LIB):
	$(MAKE) -C libft

$(PRINTF):
	$(MAKE) -C ft_printf

$(GNL):
	$(MAKE) -C get_next_line

$(MLX):
	$(MAKE) -C minilibx-linux

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean
	$(MAKE) -C get_next_line clean
	$(MAKE) -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C get_next_line fclean

re: fclean all

.PHONY: all clean fclean re