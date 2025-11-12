#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef SIZE
#  define SIZE 32 
# endif

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "minilibx-linux/mlx.h"
#include "ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_long
{
    char **map;
    int m_height;
    int m_width;
    int player_x;
    int player_y;
    int coll;
    int move;
    void *mlx;
    void *window;
    void *iwall;
    void *ifloor;
    void *icoll;
    void *iexit;
    void *iplayer;
} t_long;

int main(int ac, char **av);
void is_map_valid(t_long *game);
void check_P_E_C(t_long *game);
void error(t_long *game, int i);
void find_coll(t_long *game);
void mlx_part(t_long *game);
void placement(t_long *game);
void up(t_long *game);
void down(t_long *game);
void right(t_long *game);
void left(t_long *game);
void free_part(t_long *game);
void is_maps_playable(t_long *game);
void is_exit_reachable(t_long *game);

#endif