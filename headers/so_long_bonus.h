/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:01:49 by coder             #+#    #+#             */
/*   Updated: 2022/02/20 19:55:54 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// -------------------------- GAME HEADERS ------------------------------ |
# include "libs.h"
# include "map_bonus.h"
# include "imgs_bonus.h"

// ------------------------- GAME CONSTANTS ----------------------------- |
# define PLAYER_RENDER 1
# define PLAYER_NOT_RENDER 0
# define COLLECTED 0
# define NOT_COLLECTED 1
# define FRONT 0
# define BACK 1
# define LEFT 2
# define RIGHT 3
# define IDLE 0
# define WALK 1
# define ATTACK 2
# define DIE 2
# define WALK_DELTA 2
# define PLAYER_Y_DIE 20

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
	int	view;
	int	frame;
	int	id_floor;
	int	x;
	int	y;
	/* int	walk_pos_x;
	int	walk_pos_y;
	int	walk_final_x;
	int	walk_final_y;
	int	walk_init_x;
	int	walk_init_y; */
}				t_player;

typedef struct s_enemy
{
	int	status;
	int	view;
	int	frame;
	int	id_floor; // setar como o da pos do walk_init
	int	x;
	int	y;
	int	walk_pos;
	int	walk_final;
	int	walk_init;
	int	walk_size; // 1 a 3
	int	walk_floor; // 1 a 3
}				t_enemy;

typedef struct s_game
{
	int			moves;
	int			player_set;
	int			collected_items;
	t_mlx		mlx;
	t_map		map;
	t_img		img;
	t_img		img_moves;
	t_tiles		tiles;
	t_sprites	sprites;
	t_player	player;
	t_item		**items;
	t_enemy		**enemies;
}				t_game;

// ------------------------- GAME FUNCTIONS ----------------------------- |

void	sl_map(char *path, t_game *sl);
void	sl_check_map(t_game *sl);

void	sl_game_init(t_game *sl);
void	sl_load_sprites(t_game *sl);
void	load_sprite(t_game *sl, t_img *sprite, char *path, int type_size);
void	sl_set_collectibles(t_game *sl);
void	sl_set_enemies(t_game *sl);
void	sl_set_enemy_walk(t_game *sl, t_enemy *e, int i, int j);
void	sl_init_player(t_game *sl, int x, int y, int id_floor);

void	sl_render_game(t_game *sl);
void	sl_put_static_map(t_game *sl, int i, int j, int k);
void	sl_put_collectibles(t_game *sl);
void	sl_put_enemies(t_game *sl);

void	sl_mlx_hooks(t_game *sl);

void	sl_move_right(t_game *sl);
void	sl_move_left(t_game *sl);
void	sl_move_up(t_game *sl);
void	sl_move_down(t_game *sl);
void	sl_move_exit(t_game *sl);
void	print_move(t_game *sl);
void	check_collectible(t_game *sl, int i, int j);

void	put_floor_again(t_game *sl, int x, int y, int id_floor);
void	put_floor_player(t_game *sl);
void	put_floor_player_die(t_game *sl);
void	put_floor_enemies_walk(t_game *sl);

void	update_player(t_game *sl);
void	sl_put_player(t_game *sl);
void	put_player(t_game *sl, t_img *sprite);

void	update_enemies(t_game *sl);
void	update_enemy_walk(t_game *sl, t_enemy *e);
void	update_enemy_attack(t_game *sl, t_enemy *e);
void	sl_put_enemy(t_game *sl, t_enemy *e);

int		player_dies(t_game *sl, t_enemy *e);
void	set_player_to_die(t_game *sl, t_enemy *e);
void	render_die(t_game *sl, t_enemy *e);

void	put_sprite_in_game_img(t_game *sl, t_img *sprite, int x, int y);
void	put_background_colors(t_img *img, int color, int thick, int frame);
int		sl_error(char *msg, t_game *sl);
void	clean_game(t_game *sl);
void	clean_imgs(t_game *sl);
int		close_game(t_game *sl);

#endif
