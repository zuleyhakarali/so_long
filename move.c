#include "so_long.h"

static void win(t_long *game)
{
    game->move++;
    ft_printf("%d\n", game->move);
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
    game->move++;
    ft_printf("%d\n", game->move);
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
    game->move++;
    ft_printf("%d\n", game->move);
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
    game->move++;
    ft_printf("%d\n", game->move);
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
    game->move++;
    ft_printf("%d\n", game->move);
}
