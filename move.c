#include "so_long.h"

static void win(t_long *game)
{
    write(1, "You Have Successfully Completed the Game\n", 41);
    free_part(game);
}

void up(t_long *game)
{
    int x;
    int y;

    x = game->player_x;
    y = game->player_y - 1;
    if (game->map[y][x] == '1')
        return ;
    else if (game->map[y][x] == 'C')
        game->coll--;
    else if (game->map[y][x] == 'E')
    {
        if (game->coll == 0)
            win(game);
        else 
            return ;
    }
    game->map[game->player_y][game->player_x] = '0';
    game->map[y][x] = 'P';
    game->player_y = y;
    mlx_clear_window(game->mlx, game->window);
    placement(game);
}

void down(t_long *game)
{
    int x;
    int y;

    x = game->player_x;
    y = game->player_y + 1;
    if (game->map[y][x] == '1')
        return ;
    else if (game->map[y][x] == 'C')
        game->coll--;
    else if (game->map[y][x] == 'E')
    {
        if (game->coll == 0)
            win(game);
        else 
            return ;
    }
    game->map[game->player_y][game->player_x] = '0';
    game->map[y][x] = 'P';
    game->player_y = y;
    mlx_clear_window(game->mlx, game->window);
    placement(game);
}

void right(t_long *game)
{
    int x;
    int y;

    x = game->player_x + 1;
    y = game->player_y;
    if (game->map[y][x] == '1')
        return ;
    else if (game->map[y][x] == 'C')
        game->coll--;
    else if (game->map[y][x] == 'E')
    {
        if (game->coll == 0)
            win(game);
        else 
            return ;
    }
    game->map[game->player_y][game->player_x] = '0';
    game->map[y][x] = 'P';
    game->player_x = x;
    mlx_clear_window(game->mlx, game->window);
    placement(game);
}

void left(t_long *game)
{
    int x;
    int y;

    x = game->player_x - 1;
    y = game->player_y;
    if (game->map[y][x] == '1')
        return ;
    else if (game->map[y][x] == 'C')
        game->coll--;
    else if (game->map[y][x] == 'E')
    {
        if (game->coll == 0)
            win(game);
        else 
            return ;
    }
    game->map[game->player_y][game->player_x] = '0';
    game->map[y][x] = 'P';
    game->player_x = x;
    mlx_clear_window(game->mlx, game->window);
    placement(game);
}
