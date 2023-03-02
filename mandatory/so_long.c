/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:13:18 by yli               #+#    #+#             */
/*   Updated: 2023/02/23 19:44:10 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	ft_check_map_command(argc, argv, game);
	ft_init_map(game, argv);
	ft_game_init(game);	
	ft_map_check(game);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, *ft_hook, game);
	mlx_hook(game->win_ptr, DestroyNotify, \
	ButtonPressMask, *ft_game_close, game);
	mlx_hook(game->win_ptr, Expose, ExposureMask, *ft_map_loading, game);
	mlx_loop(game->mlx_ptr);
	ft_free_all(game);
}
/*

ft_init_map(game, argv); //read map
ft_game_init(game); //vars, mlx, sprite
ft_map_check(game); //rows, columns, paramenters

int	mlx_hook(t_win_list *win, int x_event, int x_mask, 
		 int (*funct)(),void *param)
{
  win->hooks[x_event].hook = funct;
  win->hooks[x_event].param = param;
  win->hooks[x_event].mask = x_mask;
}
*/
