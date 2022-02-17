/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:54:55 by coder             #+#    #+#             */
/*   Updated: 2022/02/17 18:20:39 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMGS_H
# define IMGS_H

# define TILE_SIZE 32
# define SMALL_IMG_OFFSET 8

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

typedef struct s_sprites
{
	t_image	floor0;
	t_image	floor1;
	t_image	corner;
	t_image	wall;
	t_image	front0;
	t_image	back0;
	t_image	left0;
	t_image	right0;
	t_image	item0;
	t_image	item1;
	t_image	item2;
	t_image	item3;
	t_image	item4;
	t_image	item5;
	t_image	exit;
}				t_sprites;

#endif
