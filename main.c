/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:30:11 by zkarali           #+#    #+#             */
/*   Updated: 2025/11/17 13:00:35 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_maps_name_valid(int ac, char **av, t_long *game)
{
	char	*s;

	if (ac != 2)
		error(game, 0);
	s = ft_strnstr(av[1], ".ber", ft_strlen(av[1]));
	if (!s || s[4] != '\0')
		error(game, 0);
}

static void	for_placement(int i, int *size, t_long *game)
{
	int		j;
	char	**tmp;

	*size *= 2;
	tmp = malloc(sizeof(char *) * (*size + 1));
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
	tmp[i] = NULL;
}

static void	reading(char **av, t_long *game, int size)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error(game, 0);
	i = 0;
	size = 2;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (i >= size)
			for_placement(i, &size, game);
		game->map[i++] = line;
	}
	if (i == 0)
		error(game, 1);
	game->map[i] = NULL;
	game->m_height = i;
	close(fd);
}

static void	find_p_pos(t_long *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_y = i;
				game->player_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_long	*game;
	int		size;

	game = malloc(sizeof(t_long));
	if (!game)
		return (1);
	is_maps_name_valid(ac, av, game);
	size = 2;
	game->map = malloc(sizeof(char *) * (size + 1));
	if (!game->map)
		error(game, 1);
	reading(av, game, size);
	game->m_width = ft_strlen(game->map[0]);
	if (game->map[0][game->m_width - 1] == '\n')
		game->m_width--;
	is_map_valid(game);
	find_p_pos(game);
	find_coll(game);
	is_maps_playable(game);
	is_exit_reachable(game);
	mlx_part(game);
}
