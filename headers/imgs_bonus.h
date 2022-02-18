/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:54:55 by coder             #+#    #+#             */
/*   Updated: 2022/02/18 15:38:12 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMGS_BONUS_H
# define IMGS_BONUS_H

# define TILE 1
# define ITEM 2
# define PLAYER_IMG 3
# define TILE_SIZE 32
# define ITEM_SIZE 16
# define PLAYER_SIZE_X 16
# define PLAYER_SIZE_Y 20
# define SMALL_IMG_OFFSET 8
# define PLAYER_FRAMES 3

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

typedef struct s_frames_player
{
	t_img	*idle_front;
	t_img	*idle_back;
	t_img	*idle_left;
	t_img	*idle_right;
	t_img	*run_front; //
	t_img	*run_back; //
	t_img	*run_left; //
	t_img	*run_right; //
	int		frame;
}				t_frames_player;

/* typedef struct s_frames_enemy
{
	t_img	**idle_left;
	t_img	**idle_right;
	t_img	**walk__left;
	t_img	**walk__right;
	t_img	**attack__left;
	t_img	**attack__right;
	int		frames;
}				t_frames_enemy; */

typedef struct s_sprites
{
	t_items_imgs	items;
	t_frames_player	player;
}				t_sprites;

#endif
