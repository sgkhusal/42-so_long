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

# define TILE_SIZE 32
# define SMALL_IMG_OFFSET 8
# define PLAYER_FRAMES 3

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

typedef struct s_animation
{
	t_image	**frames;
	int		nf;
}				t_animation;

typedef struct s_sprites
{
	t_image	floor0;
	t_image	floor1;
	t_image	corner;
	t_image	wall;
	t_image	exit;
	t_image	front0; //
	t_image	back0; //
	t_image	left0; //
	t_image	right0; //
	t_image	item0;
	t_image	item1;
	t_image	item2;
	t_image	item3;
	t_image	item4;
	t_image	item5;
}				t_sprites;

typedef struct s_player_frames
{
	t_image	**idle_front;
	t_image	**idle_back;
	t_image	**idle_left;
	t_image	**idle_right;
	t_image	**run_front; //
	t_image	**run_back; //
	t_image	**run_left; //
	t_image	**run_right; //
	int		frame;
}				t_player_frames;

typedef struct s_enemy_frames
{
	t_image	**idle_left;
	t_image	**idle_right;
	t_image	**walk__left;
	t_image	**walk__right;
	t_image	**attack__left;
	t_image	**attack__right;
	int		frames;
}				t_enemy_frames;

#endif
