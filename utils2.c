/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:33:10 by zkarali           #+#    #+#             */
/*   Updated: 2025/11/17 12:44:05 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill(char **tmp, int y, int x)
{
	if (y < 0 || x < 0 || tmp[y][x] == '1' || tmp[y][x] == '\0'
		|| tmp[y][x] == 'f')
		return ;
	if (tmp[y][x] == 'E')
	{
		tmp[y][x] = 'f';
		return ;
	}
	tmp[y][x] = 'f';
	fill(tmp, y - 1, x);
	fill(tmp, y + 1, x);
	fill(tmp, y, x - 1);
	fill(tmp, y, x + 1);
}

static void	check(char **tmp, t_long *game)
{
	int	i;
	int	j;
	int	f;

	i = 0;
	f = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
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

void	is_exit_reachable(t_long *game)
{
	char	**tmp;
	int		i;
	int		x;
	int		y;

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
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

void	check_p_e_c(t_long *game)
{
	int	i;
	int	j;
	int	c;
	int	e;
	int	p;

	i = 0;
	c = 0;
	e = 0;
	p = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			c += (game->map[i][j] == 'C');
			e += (game->map[i][j] == 'E');
			p += (game->map[i][j] == 'P');
			j++;
		}
		i++;
	}
	if (c == 0 || e != 1 || p != 1)
		error(game, 1);
}
