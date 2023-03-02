/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:40:48 by yli               #+#    #+#             */
/*   Updated: 2023/02/23 18:20:55 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *message, t_game *game)
{
	printf("test1\n");
	if (game->map_alloc == true)
		ft_free_map(game);
	if (game->sprite_alloc == true)
	{
		free(game->mlx_ptr);
		ft_destroy_images(game);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
	}
	free(game);
	ft_printf(RED"ERROR: %s\n"RESET, message);
	exit(1);
}

void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
		free(game->map.full[i++]);
	free (game->map.full);
}

void	ft_free_all(t_game *game)
{
	ft_destroy_images(game);
	ft_free_map(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
}

void	ft_destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->gold.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_f.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_r.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_b.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_l.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->open.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->stone.xpm_ptr);
}
