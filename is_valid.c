/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:29:21 by zkarali           #+#    #+#             */
/*   Updated: 2025/11/17 12:44:20 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_len(t_long *game, int i)
{
	int	len;

	len = ft_strlen(game->map[i]);
	if (len > 0 && game->map[i][len - 1] == '\n')
		len--;
	if (game->m_width != len)
		error(game, 1);
}

static void	check_fir_las_wid(t_long *game, int i)
{
	int	j;

	j = 0;
	if (i == 0 || game->map[i + 1] == NULL)
	{
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			if (game->map[i][j] != '1')
				error(game, 1);
			j++;
		}
	}
}

static void	check_fir_las_heig(t_long *game, int i)
{
	int	len;

	len = ft_strlen(game->map[i]);
	if (len > 0 && game->map[i][len - 1] == '\n')
		len--;
	if ((game->map[i][0] != '1') || (game->map[i][len - 1] != '1'))
		error(game, 1);
}

static void	check_valid_chars(t_long *game, int i)
{
	int		j;
	char	c;

	j = 0;
	while (game->map[i][j])
	{
		c = game->map[i][j];
		if (c != '1' && c != '0' && c != 'P' && c != 'E'
			&& c != 'C' && c != '\n')
			error(game, 1);
		j++;
	}
}

void	is_map_valid(t_long *game)
{
	int	i;
	int	len;

	len = game->m_height - 1;
	if (game->map[len][ft_strlen(game->map[len]) - 1] == '\n')
		error(game, 1);
	i = 0;
	while (game->map[i])
	{
		check_len(game, i);
		check_fir_las_wid(game, i);
		check_fir_las_heig(game, i);
		check_valid_chars(game, i);
		i++;
	}
	check_p_e_c(game);
}
