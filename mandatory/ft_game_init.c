/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:59:50 by yli               #+#    #+#             */
/*   Updated: 2023/02/23 18:06:53 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_init(t_game *game)
{
	ft_init_vars(game);
	ft_init_mlx(game);
	ft_init_sprite(game);
}
/*
void	ft_init_vars(t_game *game)
{
	game->map.gold = 0;
	game->map.exit = 0;
	game->map.players = 0;
	game->movements = 0;
	game->map.columns = ft_strlen(game->map.full[0]);
	game->player_sprite = UP;
}
*/
void	ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		ft_error("can't find mlx pointer", game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	game->map.columns * IMG_WIDTH, game->map.rows * IMG_HEIGHT, "so_long");
	if (game->win_ptr == NULL)
	{
		free (game->mlx_ptr);
		ft_error("can't create the window", game);
	}
}

t_image	ft_new_sprite(void *mlx, char *path, t_game *game)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, \
	path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		ft_error("can't find the sprite", game);
	return (sprite);
}

void	ft_init_sprite(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	game->wall = ft_new_sprite(mlx, WALL_XPM, game);
	game->floor = ft_new_sprite(mlx, FLOOR_XPM, game);
	game->gold = ft_new_sprite(mlx, GOLD_XPM, game);
	game->stone = ft_new_sprite(mlx, STONE_XPM, game);
	game->player_f = ft_new_sprite(mlx, PLAYER_F_XPM, game);
	game->player_r = ft_new_sprite(mlx, PLAYER_R_XPM, game);
	game->player_b = ft_new_sprite(mlx, PLAYER_B_XPM, game);
	game->player_l = ft_new_sprite(mlx, PLAYER_L_XPM, game);
	game->open = ft_new_sprite(mlx, OPEN_XPM, game);
	game->exit = ft_new_sprite(mlx, EXIT_XPM, game);
	game->sprite_alloc = true;
}
//	*mlx_new_window(t_xvar *xvar,int size_x,int size_y,char *title)
