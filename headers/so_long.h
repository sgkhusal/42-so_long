/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:01:49 by coder             #+#    #+#             */
/*   Updated: 2022/02/12 05:02:09 by coder            ###   ########.fr       */
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

typedef struct s_map
{
	char	*linear_map;
	char	**map;
	int		total_c;
	int		total_e;
	int		total_p;
	int		total_lines;
	size_t	line_size;
	//t_list	*c_list;
	//t_list	*e_list;
	//t_list	*p_list;
}				t_map;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_image;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}				t_mlx;

typedef struct s_game
{
	int		moves;
	t_mlx	mlx;
	t_map	map;
	t_image	floor1;
	t_image	floor2;
	t_image	corner;
	t_image	wall;
	t_image	mid_wall;
	t_image	player;
	t_image	collectible;
	t_image	exit;
}				t_game;

/*
so_long functions
*/

void	sl_map(char *path, t_game *sl);
void	sl_check_map(t_game *sl);
void	sl_render_game(t_game *sl);

int		sl_error(char *msg, t_game *sl);

void	clean_map(t_game *sl);
void	clean_mlx(t_game *sl);

#endif
