/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_render_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 01:51:34 by coder             #+#    #+#             */
/*   Updated: 2022/02/12 05:03:31 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void sl_images_init(t_game *sl)
{
	sl->floor1.img = mlx_xpm_file_to_image(sl->mlx.mlx,
			"assets/images/floor1.xpm", &sl->floor1.width, &sl->floor1.height);
	if (!sl->floor1.img)
		sl_error("Mlx error loading floor1 image.", sl);
	sl->floor2.img = mlx_xpm_file_to_image(sl->mlx.mlx,
			"assets/images/floor2.xpm", &sl->floor2.width, &sl->floor2.height);
	if (!sl->floor2.img)
		sl_error("Mlx error loading floor2 image.", sl);
	sl->wall.img = mlx_xpm_file_to_image(sl->mlx.mlx,
			"assets/images/wall.xpm", &sl->wall.width, &sl->wall.height);
	if (!sl->wall.img)
		sl_error("Mlx error loading wall image.", sl);
	sl->corner.img = mlx_xpm_file_to_image(sl->mlx.mlx,
			"assets/images/corner.xpm", &sl->corner.width, &sl->corner.height);
	if (!sl->corner.img)
		sl_error("Mlx error loading corner image.", sl);
	sl->mid_wall.img = mlx_xpm_file_to_image(sl->mlx.mlx,
			"assets/images/wall2.xpm", &sl->mid_wall.width, &sl->mid_wall.height);
	if (!sl->mid_wall.img)
		sl_error("Mlx error loading mid_wall image.", sl);
	/* sl->player.img = mlx_xpm_file_to_image(sl->mlx.mlx,
			"assets/images/player.xpm", TILE_SIZE, TILE_SIZE);
	sl->collectible.img = mlx_xpm_file_to_image(sl->mlx.mlx,
			"assets/images/collectible.xpm", TILE_SIZE, TILE_SIZE);
	sl->exit.img = mlx_xpm_file_to_image(sl->mlx.mlx,
			"assets/images/exit.xpm", TILE_SIZE, TILE_SIZE); */
}

void my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void sl_render_static_map(t_game *sl)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (j < sl->map.total_lines)
	{
		i = 0;
		while (i < (int)sl->map.line_size)
		{
			if ((i == 0 || i == (int)sl->map.line_size - 1) && (j == 0 || j == sl->map.total_lines - 1))
				mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win, sl->corner.img, i * TILE_SIZE, j * TILE_SIZE);
			else if (i == 0 || i == (int)sl->map.line_size - 1)
				mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win, sl->wall.img, i * TILE_SIZE, j * TILE_SIZE);
			else if (j == 0 || j == sl->map.total_lines - 1)
				mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win, sl->wall.img, i * TILE_SIZE, j * TILE_SIZE);
			else if (sl->map.map[j][i] == '1')
				mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win, sl->wall.img, i * TILE_SIZE, j * TILE_SIZE);
			else if (k % 2 == 0)
				mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win, sl->floor1.img, i * TILE_SIZE, j * TILE_SIZE);
			else
				mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win, sl->floor2.img, i * TILE_SIZE, j * TILE_SIZE);
			i++;
			k++;
		}
		//printf("%s/n", sl->map.map[j / TILE_SIZE]);
		j++;
		k++;
	}
}

/* void sl_render_static_map(t_game *sl)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (j < sl->mlx.height)
	{
		i = 0;
		while (i < sl->mlx.width)
		{
			if ((i == 0 || i == sl->mlx.width - TILE_SIZE) && (j == 0 || j == sl->mlx.height - TILE_SIZE))
				mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win, sl->corner.img, i, j);
			else if (i == 0 || i == sl->mlx.width - TILE_SIZE)
				mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win, sl->wall.img, i, j);
			else if (j == 0 || j == sl->mlx.height - TILE_SIZE)
				mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win, sl->wall.img, i, j);
			else if (sl->map.map[j / TILE_SIZE][i / TILE_SIZE] == 1)
				mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win, sl->wall.img, i, j);
			else if (k % 2 == 0)
				mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win, sl->floor1.img, i, j);
			else
				mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win, sl->floor2.img, i, j);
			i += TILE_SIZE;
			k++;
		}
		//printf("%s/n", sl->map.map[j / TILE_SIZE]);
		j += TILE_SIZE;
		k++;
	}
} */

void sl_render_game(t_game *sl)
{
	sl_images_init(sl);
	sl_render_static_map(sl);
}
