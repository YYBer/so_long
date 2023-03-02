/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:31:03 by yli               #+#    #+#             */
/*   Updated: 2023/02/24 20:58:59 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_map_check(t_game *game)
{
	ft_check_map_rows_columns(game);
	ft_find_map_parameters(game);
}

void	ft_check_map_rows_columns(t_game *game)
{
	int	i;

	i = 0;
	printf("%s\n",game->map.full[0]);
	printf("%s\n",game->map.full[1]);
	printf("%s\n",game->map.full[2]);
	while (i < game->map.rows)
	{
		if ((int)ft_strlen(game->map.full[i]) != game->map.columns)
		{
			ft_error("wrong length of map", game);
		}
		else if (game->map.full[i][0] != WALL)
			ft_error("Wall missing from the first row", game);
		else if (game->map.full[i][game->map.columns - 1] != WALL)
			ft_error("Wall missing from the last row", game);
		i++;
	}
	i = 0;
	while (i < game->map.columns)
	{
		if (game->map.full[0][i] != WALL)
			ft_error("Wall missing from the first column", game);
		else if (game->map.full[game->map.rows - 1][i] != WALL)
			ft_error("Wall missing frome the last column", game);
		i++;
	}
}

void	ft_find_map_parameters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("GEP01ST", game->map.full[y][x]))
				ft_error("wrong parameter", game);
			else if (game->map.full[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = x * 32;
				game->map.player.y = y * 32;
			}
			else if (game->map.full[y][x] == GOLD)
				game->map.gold++;
			else if (game->map.full[y][x] == MAP_EXIT)
				game->map.exit++;
			x++;
		}
		y++;
	}
}
