/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:31:03 by yli               #+#    #+#             */
/*   Updated: 2023/02/23 17:47:45 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_check(t_game *game)
{
	ft_check_map_rows_columns(game);
	ft_find_map_parameters(game);
}

void	ft_init_vars(t_game *game)
{
	game->map.gold = 0;
	game->map.exit = 0;
	game->map.players = 0;
	game->movements = 0;
	//game->map.columns = ft_strlen(game->map.full[0]);
	game->player_sprite = UP;
}

void	ft_check_map_rows_columns(t_game *game)
{
	int	i;

	i = 0;
	printf("%zu\n",ft_strlen(game->map.full[i]));
	printf("%d\n",game->map.columns);
	printf("%s\n",game->map.full[0]);
	printf("%s\n",game->map.full[1]);
	printf("%s\n",game->map.full[2]);
	printf("%s\n",game->map.full[3]);
	printf("%s\n",game->map.full[4]);
	printf("%s\n",game->map.full[5]);
	while (i < game->map.rows)
	{
		printf("map.full = %zu\n", ft_strlen(game->map.full[i]));
		printf("map. columns = %d\n",game->map.columns);
		if ((int)ft_strlen(game->map.full[i]) != game->map.columns)
			ft_error("wrong length of map", game);
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
			if (!ft_strchr("GEP01S", game->map.full[y][x]))
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
