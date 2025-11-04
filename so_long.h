#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
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
    int Coll; //collectible
    void *mlibx; //minilibx ana pointer
    void *window; //oyun penceresi
} t_long;


int main(int ac, char **av);
void is_map_valid(t_long *game);
void error(void);

#endif