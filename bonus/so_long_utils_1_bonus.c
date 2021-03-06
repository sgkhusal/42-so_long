/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:32:08 by coder             #+#    #+#             */
/*   Updated: 2022/04/01 20:13:43 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	sl_error(char *msg, t_game *sl)
{
	ft_printf("Error\n%s\n", msg);
	clean_game(sl);
	exit(EXIT_FAILURE);
}

static void	set_sprite_size(t_img *sprite, int type)
{
	if (type == TILE)
	{
		sprite->height = TILE_SIZE;
		sprite->width = TILE_SIZE;
	}
	else if (type == ITEM)
	{
		sprite->height = ITEM_SIZE;
		sprite->width = ITEM_SIZE;
	}
	else if (type == PLAYER_IMG)
	{
		sprite->height = PLAYER_SIZE_Y;
		sprite->width = PLAYER_SIZE_X;
	}
	else if (type == ENEMY_IMG)
	{
		sprite->height = ENEMY_SIZE_Y;
		sprite->width = ENEMY_SIZE_X;
	}
}

void	load_sprite(t_game *sl, t_img *sprite, char *path, int type)
{
	sprite->img = mlx_xpm_file_to_image(sl->mlx.mlx, path, &sprite->line_size,
			&sprite->height);
	if (!sprite->img)
		sl_error(ft_strjoin("Mlx error loading sprite: ", path), sl);
	sprite->addr = mlx_get_data_addr(sprite->img, &sprite->bpp,
			&sprite->line_size, &sprite->endian);
	set_sprite_size(sprite, type);
}
