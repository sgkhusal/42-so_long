/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:32:08 by coder             #+#    #+#             */
/*   Updated: 2022/04/01 20:12:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

unsigned int	get_pixel_color(t_image *img, int x, int y)
{
	char	*pixel_color;

	pixel_color = img->addr + (y * img->line_size + x * (img->bpp / 8));
	return (*(unsigned int *)pixel_color);
}

void	put_pixel_color(t_image *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_size + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	put_sprite_in_game_img(t_game *sl, t_image *sprite, int x, int y)
{
	unsigned int	color;
	int				sprite_x;
	int				sprite_y;

	sprite_x = 0;
	sprite_y = 0;
	while (sprite_y < sprite->height)
	{
		while (sprite_x < sprite->width)
		{
			color = get_pixel_color(sprite, sprite_x, sprite_y);
			if (color != 0x0000FF)
				put_pixel_color(&sl->img, x + sprite_x, y + sprite_y, color);
			sprite_x++;
		}
		sprite_x = 0;
		sprite_y++;
	}
}
