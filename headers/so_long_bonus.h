/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:01:49 by coder             #+#    #+#             */
/*   Updated: 2022/02/18 15:48:33 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// -------------------------- GAME HEADERS ------------------------------ |
# include "libs.h"
# include "map.h"
# include "imgs_bonus.h"

// ------------------------- GAME CONSTANTS ----------------------------- |
# define SET 1
# define NOT_SET 0
# define COLLECTED 0
# define NOT_COLLECTED 1
# define FRONT 0
# define BACK 1
# define LEFT 2
# define RIGHT 3

// -------------------------- GAME STRUCTS ------------------------------ |

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}				t_mlx;

typedef struct s_item
{
	int	id_img;
	int	x;
	int	y;
}				t_item;

typedef struct s_player
{
	int	status;
	int	frame;
	int	id_floor;
	int	x;
	int	y;
}				t_player;

/* typedef struct s_enemy
{
	int	status;
	int	id_floor;
	int	x;
	int	y;
}				t_enemy; */

typedef struct s_game
{
	int			moves;
	int			player_set;
	int			collected_items;
	t_mlx		mlx;
	t_map		map;
	t_item		**items;
	t_player	player;
	//t_enemy		enemy;
	t_img		img;
	t_tiles		tiles;
	t_sprites	sprites;
}				t_game;

// ------------------------- GAME FUNCTIONS ----------------------------- |

void	sl_map(char *path, t_game *sl);
void	sl_check_map(t_game *sl);

void	sl_game_init(t_game *sl);
void	sl_set_collectibles(t_game *sl);
void	sl_init_player(t_game *sl, int x, int y, int id_floor);
void	sl_load_sprites(t_game *sl);

void	sl_render_game(t_game *sl);
void	sl_load_sprites(t_game *sl);
void	sl_put_static_map(t_game *sl, int i, int j, int k);
void	sl_put_collectibles(t_game *sl);
void	sl_put_player(t_game *sl);

void	put_player(t_game *sl, t_img *sprite);
void	update_player_sprite(t_game *sl);

void	load_sprite(t_game *sl, t_img *sprite, char *path, int type_size);
void	put_sprite_in_game_img(t_game *sl, t_img *sprite, int x, int y);

void	sl_mlx_hooks(t_game *sl);
void	sl_move_right(t_game *sl);
void	sl_move_left(t_game *sl);
void	sl_move_up(t_game *sl);
void	sl_move_down(t_game *sl);
void	sl_move_exit(t_game *sl);

void	print_move(t_game *sl);
void	check_collectible(t_game *sl, int i, int j);
void	put_floor_player(t_game *sl);
void	put_floor_again(t_game *sl, int x, int y, int id_floor);

int		sl_error(char *msg, t_game *sl);
void	clean_game(t_game *sl);
void	clean_imgs(t_game *sl);
int		close_game(t_game *sl);

#endif
