/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_render_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 01:51:34 by coder             #+#    #+#             */
/*   Updated: 2022/02/12 01:59:31 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	sl_images_init(t_game *sl)
{
	sl->floor.img = mlx_xpm_file_to_image(sl->mlx.mlx,
			"assets/images/floor.xpm", TILE_SIZE, TILE_SIZE);
	sl->wall.img = mlx_xpm_file_to_image(sl->mlx.mlx,
			"assets/images/wall.xpm", TILE_SIZE, TILE_SIZE);
	sl->player.img = mlx_xpm_file_to_image(sl->mlx.mlx,
			"assets/images/player.xpm", TILE_SIZE, TILE_SIZE);
	sl->collectible.img = mlx_xpm_file_to_image(sl->mlx.mlx,
			"assets/images/collectible.xpm", TILE_SIZE, TILE_SIZE);
	sl->exit.img = mlx_xpm_file_to_image(sl->mlx.mlx,
			"assets/images/exit.xpm", TILE_SIZE, TILE_SIZE);
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	sl_render_map(t_game *sl)
{
	int	i;
	int	j;

	sl->static_map.img = mlx_new_image(sl->mlx.mlx, sl->mlx.width,
			sl->mlx.height);
	sl->static_map.addr = mlx_get_data_addr(sl->static_map.img,
			&sl->static_map.bpp,
			&sl->static_map.line_length,
			&sl->static_map.endian);
	j = 0;
	while (j < sl->mlx.height)
	{
		i = 0;
		while (i < sl->mlx.width)
		{
			my_mlx_pixel_put(&sl->static_map, i, j, 0x000000FF);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win, sl->static_map.img, 0, 0);
}
