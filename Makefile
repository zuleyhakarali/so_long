NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c is_valid.c utils.c 
OBJS = $(SRC:.c=.o)

LIB = libft/libft.a

GNL_DIR = get_next_line
GNL_S = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_O = $(GNL_S:.c=.o)

all: $(LIB) $(NAME)

$(NAME): $(OBJS) $(GNL_O) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(GNL_O) $(LIB) -o $(NAME)

$(LIB):
	$(MAKE) -C libft

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean
	rm -f $(GNL_O)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re