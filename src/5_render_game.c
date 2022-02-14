/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_render_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 01:51:34 by coder             #+#    #+#             */
/*   Updated: 2022/02/14 20:37:41 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	put_floor(t_game *sl, int i, int j, int k)
{
	if (sl->map.map[i][j] == COLLECTIBLE)
		sl_set_collectible_id_floor(sl, i + SMALL_IMG_OFFSET,
			j + SMALL_IMG_OFFSET, k % 2);
	if (k % 2 == 0)
		put_sprite_in_game_img(sl, &sl->sprites.floor0, j * TILE_SIZE,
			i * TILE_SIZE);
	else
		put_sprite_in_game_img(sl, &sl->sprites.floor1, j * TILE_SIZE,
			i * TILE_SIZE);
}

static void	put_corner(t_game *sl, int i, int j)
{
	put_sprite_in_game_img(sl, &sl->sprites.corner, j * TILE_SIZE,
		i * TILE_SIZE);
}

static void	put_wall(t_game *sl, int i, int j)
{
	put_sprite_in_game_img(sl, &sl->sprites.wall, j * TILE_SIZE,
		i * TILE_SIZE);
}

static void	put_static_objects(t_game *sl, int i, int j, int k)
{
	if ((j == 0 || j == (int)sl->map.line_size - 1) && i == 0)
		put_corner(sl, i, j);
	else if (j == 0 && i == sl->map.total_lines - 1)
		put_corner(sl, i, j);
	else if (j == (int)sl->map.line_size - 1 && i == sl->map.total_lines - 1)
		put_corner(sl, i, j);
	else if (j == 0 || j == (int)sl->map.line_size - 1)
		put_wall(sl, i, j);
	else if (i == 0 || i == sl->map.total_lines - 1)
		put_wall(sl, i, j);
	else if (sl->map.map[i][j] == WALL)
		put_wall(sl, i, j);
	else if (sl->map.map[i][j] == EXIT)
		put_sprite_in_game_img(sl, &sl->sprites.exit, j * TILE_SIZE,
			i * TILE_SIZE);
	else
		put_floor(sl, i, j, k);
}

void	sl_render_game(t_game *sl)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < sl->map.total_lines)
	{
		j = 0;
		while (j < (int)sl->map.line_size)
		{
			put_static_objects(sl, i, j, k);
			j++;
			k++;
		}
		i++;
		k++;
	}
	sl_put_collectibles(sl);
	mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win, sl->img.img, 0, 0);
}
