/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:06:45 by yli               #+#    #+#             */
/*   Updated: 2023/02/23 17:34:51 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_command(int argc, char **argv, t_game *game)
{
	int	map_len;

	if (argc != 2)
		ft_error("wrong number of maps", game);
	map_len = ft_strlen(argv[1]);
	if (ft_strnstr(&argv[1][map_len - 4], ".ber", 4) == NULL)
		ft_error("file type is wrong, should be .ber", game);
}

void	ft_init_map(t_game *game, char **argv)
{
	char	*wbuffer;
	char	*wmap;

	game->fd = open(argv[1], O_RDONLY);
	game->map.rows = 0;
	if (game->fd < 0)
		ft_error("can't read the map", game);
	wmap = ft_strdup("");
	while (true)
	{
		wbuffer = get_next_line(game->fd);
		if (wbuffer == NULL)
			break ;
		wmap = ft_strjoin_frees1(wmap, wbuffer);
		game->map.columns = ft_strlen(wbuffer) - 1;
		free(wbuffer);
		game->map.rows++;
	}
	printf("in map init = %d\n", game->map.columns);
	close(game->fd);
	game->map.full = ft_split(wmap, '\n');
	free(wmap);
	game->map_alloc = true;
}
