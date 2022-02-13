/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_render_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 01:51:34 by coder             #+#    #+#             */
/*   Updated: 2022/02/13 02:37:06 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	render_floor(t_game *sl, int i, int j, int k)
{
	if (sl->map.map[i][j] == COLLECTIBLE)
		sl_set_collectible_id_floor(sl, i + SMALL_IMG_OFFSET,
			j + SMALL_IMG_OFFSET, k % 2);
	if (k % 2 == 0)
		mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win,
			sl->floor0.img, j * TILE_SIZE, i * TILE_SIZE);
	else
		mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win,
			sl->floor1.img, j * TILE_SIZE, i * TILE_SIZE);
}

static void	render_corner(t_game *sl, int i, int j)
{
	mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win,
		sl->corner.img, j * TILE_SIZE, i * TILE_SIZE);
}

static void	render_wall(t_game *sl, int i, int j)
{
	mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win,
		sl->wall.img, j * TILE_SIZE, i * TILE_SIZE);
}

static void	static_objects(t_game *sl, int i, int j, int k)
{
	if ((j == 0 || j == (int)sl->map.line_size - 1) && i == 0)
		render_corner(sl, i, j);
	else if (j == 0 && i == sl->map.total_lines - 1)
		render_corner(sl, i, j);
	else if (j == (int)sl->map.line_size - 1 && i == sl->map.total_lines - 1)
		render_corner(sl, i, j);
	else if (j == 0 || j == (int)sl->map.line_size - 1)
		render_wall(sl, i, j);
	else if (i == 0 || i == sl->map.total_lines - 1)
		render_wall(sl, i, j);
	else if (sl->map.map[i][j] == WALL)
		render_wall(sl, i, j);
	else if (sl->map.map[i][j] == EXIT)
		mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win,
			sl->exit.img, j* TILE_SIZE, i * TILE_SIZE);
	else
		render_floor(sl, i, j, k);
}

void	sl_render_map(t_game *sl)
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
			static_objects(sl, i, j, k);
			j++;
			k++;
		}
		i++;
		k++;
	}
}
