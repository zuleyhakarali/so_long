#include "so_long.h"

void free_part(t_long *game)
{
    int i;

    mlx_loop_end(game->mlx);
    mlx_destroy_image(game->mlx, game->iwall);
    mlx_destroy_image(game->mlx, game->ifloor);
    mlx_destroy_image(game->mlx, game->icoll);
    mlx_destroy_image(game->mlx, game->iplayer);
    mlx_destroy_image(game->mlx, game->iexit);
    mlx_destroy_window(game->mlx, game->window);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    i = 0;
    while (game->map[i])
    {
        free(game->map[i]);
        i++;
    }
    free(game->map);
    free(game);
    exit(0);
}

static int key_input(int input, t_long *game)
{
    if (input == 65307)
        free_part(game);
    if (input == 119 || input == 65362)
        up(game);
    if (input == 115 || input == 65364)
        down(game);
    if (input == 100 || input == 65363)
        right(game);
    if (input == 97 || input == 65361)
        left(game);
    return (0);
}

static int for_x(t_long *game)
{
    write(1, "Game closed\n", 12);
    free_part(game);
    return (0);
}

static int loop(t_long *game)
{
    placement(game);
    return (0);
}

void mlx_part(t_long *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        error(game, 1);
    game->move = 0;
    game->window = mlx_new_window(game->mlx, game->m_width * SIZE, 
                    game->m_height * SIZE, "so_long");
    if (!game->window)
    {
        mlx_destroy_display(game->mlx);        
        error(game, 2);
    }
    image(game);
    mlx_hook(game->window, 2, 1, key_input, game);
    mlx_hook(game->window, 17, 0, for_x, game);
    mlx_loop_hook(game->mlx, loop, game);
    mlx_loop(game->mlx);
}