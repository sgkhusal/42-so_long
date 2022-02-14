/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:01:49 by coder             #+#    #+#             */
/*   Updated: 2022/02/14 21:15:11 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "get_next_line.h"
# include "libft.h"
# include <math.h>

// printf
# include <stdio.h>

// open - O_RDONLY
# include <fcntl.h>

# define VALID_CHAR	"01CEP"
# define WALL '1'
# define SPACE '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define OPEN_ERROR -1
# define GNL_ERROR -1
# define GNL_EOF 0
# define GNL_READ_LINE 1
# define TILE_SIZE 32
# define SMALL_IMG_OFFSET 8
# define NOT_COLLECTED 1
# define COLLECTED 0
# define FRONT 0
# define BACK 1
# define LEFT 2
# define RIGHT 3

typedef struct s_map
{
	char	*linear_map;
	char	**map;
	int		total_c;
	int		total_e;
	int		total_p;
	int		total_lines;
	size_t	line_size;
}				t_map;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_size;
	int		endian;
	int		height;
	int		width;
}				t_image;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}				t_mlx;

typedef struct s_item
{
	int	status;
	int	id_img;
	int	id_floor;
	int	x;
	int	y;
}				t_item;

typedef struct s_player
{
	int	status;
	int	id_img;
	int	id_floor;
	int	x;
	int	y;
}				t_player;

typedef struct s_sprites
{
	t_image	floor0;
	t_image	floor1;
	t_image	corner;
	t_image	wall;
	t_image	front1;
	t_image	back1;
	t_image	left1;
	t_image	right1;
	t_image	item0;
	t_image	item1;
	t_image	item2;
	t_image	item3;
	t_image	item4;
	t_image	item5;
	t_image	exit;
}				t_sprites;

typedef struct s_game
{
	int			moves;
	t_mlx		mlx;
	t_map		map;
	t_sprites	sprites;
	t_image		img;
	t_item		**items;
	t_player	player;
}				t_game;

/*
so_long functions
*/

void	sl_map(char *path, t_game *sl);
void	sl_check_map(t_game *sl);
void	sl_game(t_game *sl);
void	load_sprite(t_game *sl, t_image *sprite, char *path, int type_size);
void	sl_set_transparence(t_image *img);
void	sl_set_collectibles(t_game *sl);
void	sl_render_game(t_game *sl);
void	put_sprite_in_game_img(t_game *sl, t_image *sprite, int x, int y);
void	sl_set_collectible_id_floor(t_game *sl, int x, int y, int id_floor);
void	sl_put_collectibles(t_game *sl);

int		sl_error(char *msg, t_game *sl);

void	clean_map(t_game *sl);
void	clean_items(t_game *sl);
void	clean_mlx(t_game *sl);

#endif
