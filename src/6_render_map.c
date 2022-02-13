/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_render_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 01:51:34 by coder             #+#    #+#             */
/*   Updated: 2022/02/13 00:42:40 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	render_floor(t_game *sl, int i, int j, int k)
{
	if (k % 2 == 0)
		mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win,
			sl->floor1.img, i * TILE_SIZE, j * TILE_SIZE);
	else
		mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win,
			sl->floor2.img, i * TILE_SIZE, j * TILE_SIZE);
}

static void	render_corner(t_game *sl, int i, int j)
{
	mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win,
		sl->corner.img, i * TILE_SIZE, j * TILE_SIZE);
}

static void	render_wall(t_game *sl, int i, int j)
{
	mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win,
		sl->wall.img, i * TILE_SIZE, j * TILE_SIZE);
}

static void	static_objects(t_game *sl, int i, int j, int k)
{
	if ((i == 0 || i == (int)sl->map.line_size - 1) && j == 0)
		render_corner(sl, i, j);
	else if (i == 0 && j == sl->map.total_lines - 1)
		render_corner(sl, i, j);
	else if (i == (int)sl->map.line_size - 1 && j == sl->map.total_lines - 1)
		render_corner(sl, i, j);
	else if (i == 0 || i == (int)sl->map.line_size - 1)
		render_wall(sl, i, j);
	else if (j == 0 || j == sl->map.total_lines - 1)
		render_wall(sl, i, j);
	else if (sl->map.map[j][i] == '1')
		render_wall(sl, i, j);
	else if (sl->map.map[j][i] == 'E')
		mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win,
			sl->exit.img, i * TILE_SIZE, j * TILE_SIZE);
	else
		render_floor(sl, i, j, k);
}

void	sl_render_map(t_game *sl)
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
			static_objects(sl, i, j, k);
			i++;
			k++;
		}
		j++;
		k++;
	}
}
