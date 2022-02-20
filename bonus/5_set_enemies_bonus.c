/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_set_enemies_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 02:52:55 by coder             #+#    #+#             */
/*   Updated: 2022/02/20 19:50:05 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static void	sl_init_enemy(t_enemy *e, int x, int y, int id_floor)
{
	e->status = WALK;
	e->view = RIGHT;
	e->id_floor = id_floor;
	e->x = x * TILE_SIZE;
	e->y = y * TILE_SIZE;
	e->frame = 0;
	e->walk_pos = e->x;
	e->walk_init = e->x;
	e->walk_final = e->x;
	e->walk_size = 1;
}

static void	sl_enemy_malloc(t_game *sl)
{
	int	ne;

	sl->enemies = (t_enemy **)malloc((sl->map.total_p) * sizeof(t_enemy));
	if (!sl->items)
		sl_error("Malloc error for sl->enimies.", sl);
	ne = 0;
	while (ne < sl->map.total_p - 1)
	{
		sl->enemies[ne] = (t_enemy *)malloc(sizeof(t_enemy));
		if (!sl->enemies[ne])
			sl_error("Malloc error for set enemy.", sl);
		ne++;
	}
	sl->enemies[ne] = NULL;
}

void	sl_set_enemies(t_game *sl)
{
	int	i;
	int	j;
	int	id_floor;
	int	ne;

	sl_enemy_malloc(sl);
	ne = 0;
	id_floor = 0;
	i = -1;
	while (++i < sl->map.total_lines && ne < sl->map.total_p - 1)
	{
		j = -1;
		while (++j < (int)sl->map.line_size)
		{
			if (sl->map.map[i][j] == PLAYER)
			{
				sl_init_enemy(sl->enemies[ne], j, i, id_floor % 2);
				sl_set_enemy_walk(sl, sl->enemies[ne], i, j);
				ne++;
			}
			id_floor++;
		}
		if ((int)sl->map.line_size % 2 == 0)
			id_floor++;
	}
}
