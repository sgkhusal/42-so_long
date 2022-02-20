/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:54:55 by coder             #+#    #+#             */
/*   Updated: 2022/02/20 02:23:02 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMGS_BONUS_H
# define IMGS_BONUS_H

# define TILE 1
# define ITEM 2
# define PLAYER_IMG 3
# define ENEMY_IMG 4
# define TILE_SIZE 32
# define ITEM_SIZE 16
# define PLAYER_SIZE_X 16
# define PLAYER_SIZE_Y 20
# define ENEMY_SIZE_X 32
# define ENEMY_SIZE_Y 32
# define IMG_OFFSET 8
# define PLAYER_FRAMES 4
# define ENEMY_FRAMES 8

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_size;
	int		endian;
	int		height;
	int		width;
}				t_img;

typedef struct s_tiles
{
	t_img	floor0;
	t_img	floor1;
	t_img	corner;
	t_img	wall;
	t_img	exit;
}				t_tiles;

typedef struct s_items_imgs
{
	t_img	item0;
	t_img	item1;
	t_img	item2;
	t_img	item3;
	t_img	item4;
	t_img	item5;
}				t_items_imgs;

typedef struct s_frames
{
	t_img	img0;
	t_img	img1;
	t_img	img2;
	t_img	img3;
	t_img	img4;
	t_img	img5;
	t_img	img6;
	t_img	img7;
}				t_frames;

typedef struct s_frames_player
{
	t_frames	front;
	t_frames	back;
	t_frames	left;
	t_frames	right;
}				t_frames_player;

typedef struct s_frames_enemy
{
	t_frames	walk_left;
	t_frames	walk_right;
	t_frames	attack_l;
	t_frames	attack_r;
}				t_frames_enemy;

typedef struct s_sprites
{
	t_items_imgs	items;
	t_frames_player	player;
	t_frames_enemy	enemy;
}				t_sprites;

#endif
