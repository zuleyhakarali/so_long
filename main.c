#include "so_long.h"

static void is_valid(int ac, char **av)
{
    char *s;
    int i;

    if (ac != 2)
        error();
    s = ft_strnstr(av[1], ".ber", ft_strlen(av[1]));
    i = 4;
    if (s[i] != '\0')
        error();
}

static void for_placement(int i, int *size, t_long *game)
{
    int j;
    char **tmp;

    *size *= 2;
    tmp = malloc(sizeof(char *) * (*size));
    if (!tmp)
        return ;
    j = 0;
    while (j < i)
    {
        tmp[j] = game->map[j];
        j++;
    }
    free(game->map);
    game->map = tmp;
}

static void reading(char **av, t_long *game)
{
    int fd;
    int i;
    int size;
    char *line;

    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        error();
    i = 0;
    size = 2;
    game->map = malloc(sizeof(char *) * size);
    if (!game->map)
        return ;
    while ((line = get_next_line(fd)))
    {
        if (i >= size)
            for_placement(i, &size, game);
        game->map[i++] = line;
    }
    if (i == 0)
        error();
    game->map[i] = NULL;
    game->m_height = i;
    game->m_width = ft_strlen(game->map[0]);
    close(fd);
}

static void find_p_pos(t_long *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'P')
            {
                game->player_x = i;
                game->player_y = j;
                return ;
            }
            j++;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    t_long *game;

    game = malloc(sizeof(t_long));
    is_valid(ac, av);
    reading(av, game);
    is_map_valid(game);
    find_p_pos(game);

}