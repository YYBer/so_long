/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:25:11 by yli               #+#    #+#             */
/*   Updated: 2023/02/23 19:18:46 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_loading(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			ft_paramenter_loading(game, y, x);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_sprite_loading(t_game *game, t_image sprite, int row, int column)
{
	mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, sprite.xpm_ptr, \
	column * sprite.x, row * sprite.y);
}

void	ft_player_loading(t_game *game, int y, int x)
{
	if (game->player_sprite == UP)
		ft_sprite_loading (game, game->player_f, y, x);
	if (game->player_sprite == RIGHT)
		ft_sprite_loading (game, game->player_r, y, x);
	if (game->player_sprite == LEFT)
		ft_sprite_loading (game, game->player_l, y, x);
	if (game->player_sprite == DOWN)
		ft_sprite_loading (game, game->player_b, y, x);
}

void	ft_paramenter_loading(t_game *game, int y, int x)
{
	char	paramenter;

	paramenter = game->map.full[y][x];
	if (paramenter == WALL)
		ft_sprite_loading (game, game->wall, y, x);
	else if (paramenter == FLOOR)
		ft_sprite_loading (game, game->floor, y, x);
	else if (paramenter == GOLD)
		ft_sprite_loading (game, game->gold, y, x);
	else if (paramenter == STONE)
		ft_sprite_loading (game, game->stone, y, x);
	else if (paramenter == MAP_EXIT)
	{
		if (game->map.gold == 0)
			ft_sprite_loading (game, game->open, y, x);
		else
			ft_sprite_loading (game, game->exit, y, x);
	}
	else if (paramenter == PLAYER)
		ft_player_loading (game, y, x);
}
/*int	mlx_put_image_to_window(t_xvar *xvar,t_win_list *win,
	t_img *img, int x,int y)
int	mlx_string_put(t_xvar *xvar,t_win_list *win, 
	int x,int y,int color,char *string)*/