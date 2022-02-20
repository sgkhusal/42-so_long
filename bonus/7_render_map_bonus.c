/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_render_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 01:51:34 by coder             #+#    #+#             */
/*   Updated: 2022/02/20 16:29:36 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static void	put_floor(t_game *sl, int i, int j, int id_floor)
{
	if (id_floor % 2 == 0)
		put_sprite_in_game_img(sl, &sl->tiles.floor0, j * TILE_SIZE,
			i * TILE_SIZE);
	else
		put_sprite_in_game_img(sl, &sl->tiles.floor1, j * TILE_SIZE,
			i * TILE_SIZE);
	if (sl->map.map[i][j] == PLAYER)
		sl_init_player(sl, j * TILE_SIZE + IMG_OFFSET,
			i * TILE_SIZE + IMG_OFFSET, id_floor % 2);
}

static void	put_corner(t_game *sl, int i, int j)
{
	put_sprite_in_game_img(sl, &sl->tiles.corner, j * TILE_SIZE,
		i * TILE_SIZE);
}

static void	put_wall(t_game *sl, int i, int j)
{
	put_sprite_in_game_img(sl, &sl->tiles.wall, j * TILE_SIZE,
		i * TILE_SIZE);
}

void	sl_put_static_map(t_game *sl, int i, int j, int k)
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
		put_sprite_in_game_img(sl, &sl->tiles.exit, j * TILE_SIZE,
			i * TILE_SIZE);
	else
		put_floor(sl, i, j, k);
}
