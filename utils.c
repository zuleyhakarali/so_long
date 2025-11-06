#include "so_long.h"

void error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

void find_coll(t_long *game)
{
    int i;
    int j;
    int c;

    i = 0;
    c = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'C')
                c++;
            j++;
        }
        i++;
    }
    game->coll = c;
}

static void sec_placement(t_long *game, char c, int j, int i)
{
    if (c == '1')
        mlx_put_image_to_window(game->mlx, game->window, game->iwall,
                                j * SIZE, i * SIZE);
    else if (c == '0')
        mlx_put_image_to_window(game->mlx, game->window, game->ifloor,
                                j * SIZE, i * SIZE);
    else
        mlx_put_image_to_window(game->mlx, game->window, game->iplayer,
                                        j * SIZE, i * SIZE);
}

void placement(t_long *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == '0')
                sec_placement(game, '0', j, i);
            if (game->map[i][j] == '1')
                sec_placement(game, '1', j, i);
            if (game->map[i][j] == 'P')
                sec_placement(game, 'P', j, i);
            if (game->map[i][j] == 'C')
                mlx_put_image_to_window(game->mlx, game->window, game->icoll,
                                        j * SIZE, i * SIZE);
            if (game->map[i][j] == 'E')
                mlx_put_image_to_window(game->mlx, game->window, game->iexit,
                                        j * SIZE, i * SIZE);
            j++;
        }
        i++;
    }
}