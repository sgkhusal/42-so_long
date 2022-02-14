/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:32:08 by coder             #+#    #+#             */
/*   Updated: 2022/02/14 20:53:34 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	sl_error(char *msg, t_game *sl)
{
	printf("Error\n%s\n", msg);
	clean_map(sl);
	clean_items(sl);
	clean_mlx(sl);
	exit(EXIT_FAILURE);
}

void	load_sprite(t_game *sl, t_image *sprite, char *path, int type_size)
{
	char	*msg;
	
	sprite->img = mlx_xpm_file_to_image(sl->mlx.mlx, path, &sprite->line_size,
			&sprite->height);
	if (!sprite->img)
	{
		msg = ft_strjoin("Mlx error loading sprite: ", path);
		sl_error(msg, sl);
	}	
	sprite->addr = mlx_get_data_addr(sprite->img, &sprite->bpp,
			&sprite->line_size, &sprite->endian);
	if (type_size == 1)
	{
		sprite->height = TILE_SIZE;
		sprite->width = TILE_SIZE;
	}
	else if (type_size == 2)
	{
		sprite->height = TILE_SIZE / 2;
		sprite->width = TILE_SIZE / 2;
	}
}

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
