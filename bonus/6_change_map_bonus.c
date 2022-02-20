/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_change_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 00:47:05 by coder             #+#    #+#             */
/*   Updated: 2022/02/20 00:50:19 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static void	sl_change_map_part2(t_game *sl, t_enemy *e, int i, int j)
{
	sl->map.map[i][j - 1] = ENEMY;
	e->walk_init -= TILE_SIZE;
	e->walk_size++;
	e->id_floor = (e->id_floor + 1) % 2;
	if (sl->map.map[i][j - 2] == EMPTY)
	{
		sl->map.map[i][j - 2] = ENEMY;
		e->walk_init -= TILE_SIZE;
		e->walk_size++;
		e->id_floor = (e->id_floor + 1) % 2;
	}
}

void	sl_change_map(t_game *sl, t_enemy *e, int i, int j)
{
	sl->map.map[i][j] = ENEMY;
	if (sl->map.map[i][j + 1] == EMPTY)
	{
		sl->map.map[i][j + 1] = ENEMY;
		e->walk_final += TILE_SIZE;
		e->walk_size++;
		if (sl->map.map[i][j + 2] == EMPTY)
		{
			sl->map.map[i][j + 2] = ENEMY;
			e->walk_final += TILE_SIZE;
			e->walk_size++;
		}
		else if (sl->map.map[i][j - 1] == EMPTY)
		{
			sl->map.map[i][j - 1] = ENEMY;
			e->walk_init -= TILE_SIZE;
			e->walk_size++;
			e->id_floor = (e->id_floor + 1) % 2;
		}
	}
	else if (sl->map.map[i][j - 1] == EMPTY)
		sl_change_map_part2(sl, e, i, j);
}
