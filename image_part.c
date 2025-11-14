#include "so_long.h"

static void for_img_free(t_long *game)
{
    mlx_destroy_window(game->mlx, game->window);
    mlx_destroy_display(game->mlx);
    error(game, 2);
}

static void sec_image(t_long *game, int i)
{
    if (i == 0)
    {
        mlx_destroy_image(game->mlx, game->iwall);
        mlx_destroy_image(game->mlx, game->ifloor);
        mlx_destroy_image(game->mlx, game->icoll);
        for_img_free(game);
    }
    else
    {
        mlx_destroy_image(game->mlx, game->iwall);
        mlx_destroy_image(game->mlx, game->ifloor);
        mlx_destroy_image(game->mlx, game->icoll);
        mlx_destroy_image(game->mlx, game->iexit);
        for_img_free(game);
    }
}

void image(t_long *game)
{
    int wi;
    int he;

    game->iwall = mlx_xpm_file_to_image(game->mlx, "XPM/wall.xpm", &wi, &he);
    if (!game->iwall)
        for_img_free(game);
    game->ifloor = mlx_xpm_file_to_image(game->mlx, "XPM/floor.xpm", &wi, &he);
    if (!game->ifloor)
    {
        mlx_destroy_image(game->mlx, game->iwall);
        for_img_free(game);
    }
    game->icoll = mlx_xpm_file_to_image(game->mlx, "XPM/coll.xpm", &wi, &he);
    if (!game->icoll)
    {
        mlx_destroy_image(game->mlx, game->iwall);
        mlx_destroy_image(game->mlx, game->ifloor);
        for_img_free(game);
    }
    game->iexit = mlx_xpm_file_to_image(game->mlx, "XPM/exit.xpm", &wi, &he);
    if (!game->iexit)
        sec_image(game, 0);
    game->iplayer = mlx_xpm_file_to_image(game->mlx, "XPM/plyr.xpm", &wi, &he);
    if (!game->iplayer)
        sec_image(game, 1);
}