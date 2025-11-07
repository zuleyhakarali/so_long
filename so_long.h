#ifndef SO_LONG_H
# define SO_LONG_H

//kullanımı doğru mu??
# ifndef SIZE
#  define SIZE 32 
# endif

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "minilibx-linux/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include <stdio.h>

typedef struct s_long
{
    char **map; //haritanın 2d hali
    int m_height; //map height
    int m_width; //map width
    int player_x; //player x position
    int player_y; //player y position
    int coll;
    void *mlx; //minilibx ana pointer
    void *window; //oyun penceresi
    void *iwall;
    void *ifloor;
    void *icoll;
    void *iexit;
    void *iplayer;
} t_long;


int main(int ac, char **av);
void is_map_valid(t_long *game);
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