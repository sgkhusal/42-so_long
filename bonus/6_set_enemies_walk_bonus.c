/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_set_enemies_walk_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 00:47:05 by coder             #+#    #+#             */
/*   Updated: 2022/04/01 20:12:56 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static void	sl_change_map(t_game *sl, int id_floor, int i, int j)
{
	if (id_floor % 2 == 0)
		sl->map.map[i][j] = ENEMY0;
	else
		sl->map.map[i][j] = ENEMY1;
}

static void	sl_set_enemy_walk_part2(t_game *sl, t_enemy *e, int i, int j)
{
	sl_change_map(sl, e->id_floor + 1, i, j - 1);
	e->walk_init -= TILE_SIZE;
	e->walk_size++;
	e->id_floor = (e->id_floor + 1) % 2;
	if (sl->map.map[i][j - 2] == EMPTY)
	{
		sl_change_map(sl, e->id_floor, i, j - 2);
		e->walk_init -= TILE_SIZE;
		e->walk_size++;
		e->id_floor = (e->id_floor + 1) % 2;
	}
}

void	sl_set_enemy_walk(t_game *sl, t_enemy *e, int i, int j)
{
	sl_change_map(sl, e->id_floor, i, j);
	if (sl->map.map[i][j + 1] == EMPTY)
	{
		sl_change_map(sl, e->id_floor + 1, i, j + 1);
		e->walk_final += TILE_SIZE;
		e->walk_size++;
		if (sl->map.map[i][j + 2] == EMPTY)
		{
			sl_change_map(sl, e->id_floor, i, j + 2);
			e->walk_final += TILE_SIZE;
			e->walk_size++;
		}
		else if (sl->map.map[i][j - 1] == EMPTY)
		{
			sl_change_map(sl, e->id_floor + 1, i, j - 1);
			e->walk_init -= TILE_SIZE;
			e->walk_size++;
			e->id_floor = (e->id_floor + 1) % 2;
		}
	}
	else if (sl->map.map[i][j - 1] == EMPTY)
		sl_set_enemy_walk_part2(sl, e, i, j);
}
