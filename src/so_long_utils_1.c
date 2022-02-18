/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:32:08 by coder             #+#    #+#             */
/*   Updated: 2022/02/17 21:59:26 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	sl_error(char *msg, t_game *sl)
{
	ft_printf("Error\n%s\n", msg);
	clean_game(sl);
	exit(EXIT_FAILURE);
}

static void	set_sprite_size(t_image *sprite, int type_size)
{
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
	else if (type_size == 3)
	{
		sprite->height = TILE_SIZE / 2 + 4;
		sprite->width = TILE_SIZE / 2;
	}
}

void	load_sprite(t_game *sl, t_image *sprite, char *path, int type_size)
{
	sprite->img = mlx_xpm_file_to_image(sl->mlx.mlx, path, &sprite->line_size,
			&sprite->height);
	if (!sprite->img)
		sl_error(ft_strjoin("Mlx error loading sprite: ", path), sl);
	sprite->addr = mlx_get_data_addr(sprite->img, &sprite->bpp,
			&sprite->line_size, &sprite->endian);
	set_sprite_size(sprite, type_size);
}
