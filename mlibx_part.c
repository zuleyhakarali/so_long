#include "so_long.h"

static void sec_placement(t_long *game, char c, int j, int i)
{
    if (c == 1)
        mlx_put_image_to_window(game->mlx, game->window, game->iwall,
                                j * SIZE, i * SIZE);
    else
        mlx_put_image_to_window(game->mlx, game->window, game->ifloor,
                                j * SIZE, i * SIZE);
}

static void placement(t_long *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j++])
        {
            if (game->map[i][j] == '1')
                sec_placement(game, '1', j, i);
            if (game->map[i][j] == '0')
                sec_placement(game, '0', j, i);
            if (game->map[i][j] == 'P')
                mlx_put_image_to_window(game->mlx, game->window, game->iplayer,
                                        j * SIZE, i * SIZE);
            if (game->map[i][j] == 'C')
                mlx_put_image_to_window(game->mlx, game->window, game->icoll,
                                        j * SIZE, i * SIZE);
            if (game->map[i][j] == 'E')
                mlx_put_image_to_window(game->mlx, game->window, game->iexit,
                                        j * SIZE, i * SIZE);
        }
        i++;
    }
}

static void for_mlx_hooks(t_long *game)
{
    
}

void mlx_part(t_long *game)
{
    int wi;
    int he;

    wi = 0;
    he = 0;
    game->mlx = mlx_init();
    if (!game->mlx)
        error();
    game->window = mlx_new_window(game->mlx, game->m_width * SIZE, 
                    game->m_height * SIZE, "so_long");
    game->iwall = mlx_xpm_file_to_image(game->mlx, "XPM/wall.xpm", &wi, &he);
    game->ifloor = mlx_xpm_file_to_image(game->mlx, "XPM/floor.xpm", &wi, &he);
    game->icoll = mlx_xpm_file_to_image(game->mlx, "XPM/coll.xpm", &wi, &he);
    game->iexit = mlx_xpm_file_to_image(game->mlx, "XPM/exit.xpm", &wi, &he);
    game->iplayer = mlx_xpm_file_to_image(game->mlx, "XPM/plyr.xpm", &wi, &he);
    if (game->window == NULL || game->iwall == NULL || game->ifloor == NULL ||
        game->icoll == NULL || game->iexit == NULL || game->iplayer == NULL)
        error();
    placement(game);
    for_mlx_hooks(game);
    mlx_loop(game->mlx);
}