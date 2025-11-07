#include "so_long.h"

static void fill(char **tmp, int y, int x)
{
    char p;

    p = 'p';
    if (y < 0 || x < 0 || tmp[y][x] == '1' || tmp[y][x] == '\0' 
        || tmp[y][x] == 'p')
        return ;
    if (tmp[y][x] == 'E')
    {
        tmp[y][x] = 'p';
        return ;
    }
    tmp[y][x] = p;
    fill(tmp, y - 1, x);
    fill(tmp, y + 1, x);
    fill(tmp, y, x - 1);
    fill(tmp, y, x + 1);
}

static void check(char **tmp, t_long *game)
{
    int i;
    int j;
    int f;

    i = 0;
    f = 0;
    while (tmp[i])
    {
        j = 0;
        while(tmp[i][j])
        {
            if (tmp[i][j] == 'E' || tmp[i][j] == 'C')
            {
                while (tmp[f])
                    free(tmp[f++]);
                free(tmp);
                error(game, 1);
            }
            j++;
        }
        i++;
    }
}

void is_exit_reachable(t_long *game)
{
    char **tmp;
    int i;
    int x;
    int y;

    y = game->player_y;
    x = game->player_x;
    i = 0;
    tmp = malloc(sizeof(char *) * (game->m_height + 1));
    while (game->map[i])
    {
        tmp[i] = ft_strdup(game->map[i]);
        i++;
    }
    tmp[i] = NULL;
    fill(tmp, y, x);
    check(tmp, game);
    i = 0;
    while(tmp[i])
        free(tmp[i++]);
    free(tmp);
}