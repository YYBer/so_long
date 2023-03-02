/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_input_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:07:37 by yli               #+#    #+#             */
/*   Updated: 2023/02/23 20:54:24 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_hook(int keysym, t_game *game)
{
	if (keysym == KEY_UP || keysym == KEY_W)
		ft_move(game, (game->map.player.y - 32), game->map.player.x, UP);
	if (keysym == KEY_RIGHT || keysym == KEY_D)
		ft_move(game, game->map.player.y, (game->map.player.x + 32), RIGHT);
	if (keysym == KEY_DOWN || keysym == KEY_S)
		ft_move(game, (game->map.player.y + 32), game->map.player.x, DOWN);
	if (keysym == KEY_LEFT || keysym == KEY_A)
		ft_move(game, (game->map.player.y), game->map.player.x - 32, LEFT);
	if (keysym == KEY_Q || keysym == KEY_ESC)
		ft_game_close(game);
	return (0);
}

void	ft_move(t_game *game, int new_y, int new_x, int move)
{
	int	last_x;
	int	last_y;

	game->player_sprite = move;
	last_x = game->map.player.x / 32;
	last_y = game->map.player.y / 32;
	new_y /= 32;
	new_x /= 32;
	if ((game->map.full[new_y][new_x] == FLOOR)
		|| (game->map.full[new_y][new_x] == GOLD)
			|| (game->map.full[new_y][new_x] == T_GRASS))
	{
		game->map.full[last_y][last_x] = FLOOR;
		if (game->map.full[new_y][new_x] == T_GRASS)
			ft_game_failure(game);
		else if (game->map.full[new_y][new_x] == GOLD)
			game->map.gold--;
		game->map.player.x = new_x * 32;
		game->map.player.y = new_y * 32;
		game->map.full[new_y][new_x] = PLAYER;
		game->movements++;
		ft_map_loading(game);
	}
	else if (game->map.full[new_y][new_x] == MAP_EXIT && game->map.gold == 0)
		ft_victory(game);
}
