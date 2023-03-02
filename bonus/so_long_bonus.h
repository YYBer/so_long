/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:35:08 by yli               #+#    #+#             */
/*   Updated: 2023/02/23 20:51:46 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../LIBGNL/ft_printf/libft/libft.h"
# include "../LIBGNL/ft_printf/ft_printf.h"
# include "../LIBGNL/get_next_line.h"

# define IMG_HEIGHT	32
# define IMG_WIDTH	32
# define WALL		'1'
# define FLOOR		'0'
# define GOLD		'G'
# define PLAYER		'P'
# define STONE		'S'
# define MAP_EXIT	'E'
# define T_GRASS	'T'

# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_UP		65362
# define KEY_RIGHT	65363
# define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_Q		113
# define KEY_ESC	65307

# define UP			1
# define RIGHT		2
# define DOWN		3
# define LEFT		4

# define WALL_XPM	"assets/wall.xpm"
# define FLOOR_XPM	"assets/floor.xpm"
# define STONE_XPM	"assets/stone.xpm"
# define GOLD_XPM	"assets/gold.xpm"
# define PLAYER_F_XPM	"assets/player_f.xpm"
# define PLAYER_R_XPM	"assets/player_r.xpm"
# define PLAYER_B_XPM	"assets/player_b.xpm"
# define PLAYER_L_XPM	"assets/player_l.xpm"
# define OPEN_XPM	"assets/open.xpm"
# define EXIT_XPM	"assets/exit.xpm"
# define T_GRASS_XPM	"assets/toxic_grass.xpm"

# define GREEN	"\033[0;32m"
# define RED	"\033[1;31m"
# define BLUE	"\033[0;34m"
# define RESET	"\033[0m" 

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	t_position	player;
	char		**full;
	int			rows;
	int			columns;
	int			gold;
	int			exit;
	int			players;
}	t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*param;
	int		movements;
	int		player_sprite;
	int		fd;
	t_map	map;
	t_bool	map_alloc;
	t_bool	sprite_alloc;
	t_image	wall;
	t_image	floor;
	t_image	gold;
	t_image	open;
	t_image	exit;
	t_image	player_f;
	t_image	player_r;
	t_image	player_b;
	t_image	player_l;
	t_image	stone;
	t_image	t_grass;
}	t_game;

int		ft_error(char *message, t_game *game);
void	ft_free_map(t_game *game);
void	ft_free_all(t_game *game);
void	ft_destroy_images(t_game *game);
void	ft_check_map_rows_columns(t_game *game);
void	ft_find_map_parameters(t_game *game);
void	ft_check_map_command(int argc, char **argv, t_game *game);
void	ft_init_map(t_game *game, char **argv);
void	ft_game_init(t_game *game);
void	ft_init_vars(t_game *game);
void	ft_init_mlx(t_game *game);
t_image	ft_new_sprite(void *mlx, char *path, t_game *game);
void	ft_init_sprite(t_game *game);
int		ft_hook(int keysym, t_game *game);
void	ft_move(t_game *game, int new_y, int new_x, int move);
int		ft_map_loading(t_game *game);
void	ft_sprite_loading(t_game *game, t_image sprite, int row, int column);
void	ft_player_loading(t_game *game, int y, int x);
void	ft_paramenter_loading(t_game *game, int y, int x);
void	ft_print_movements(t_game *game);
int		ft_victory(t_game *game);
int		ft_game_close(t_game *game);
char	*get_next_line(int fd);
void	ft_map_check(t_game *game);
int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
int		ft_game_failure(t_game *game);
#endif
