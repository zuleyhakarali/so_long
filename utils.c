#include "so_long.h"

void error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

void find_Coll(t_long *game)
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