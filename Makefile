NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux

SRC = main.c is_valid.c utils.c mlibx_part.c move.c
OBJS = $(SRC:.c=.o)

LIB = libft/libft.a
MLX = minilibx-linux/libmlx.a
GNL_DIR = get_next_line
GNL_S = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_O = $(GNL_S:.c=.o)

MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

all: $(LIB) $(MLX) $(NAME)

$(NAME): $(OBJS) $(GNL_O) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(GNL_O) $(LIB) $(MLX_FLAGS) -o $(NAME)

$(LIB):
	$(MAKE) -C libft

$(MLX):
	$(MAKE) -C minilibx-linux

clean:
	rm -f $(OBJS) $(GNL_O)
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re