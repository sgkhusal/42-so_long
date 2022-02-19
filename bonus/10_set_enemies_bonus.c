/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_set_enemies_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 02:52:55 by coder             #+#    #+#             */
/*   Updated: 2022/02/19 19:50:07 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	sl_init_enemy(t_enemy *e, int x, int y, int id_floor)
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

int	sl_jump_player(t_game *sl, int *i, int *j, int *id_floor)
{
	*i = 0;
	while (*i < sl->map.total_lines)
	{
		*j = 0;
		while (*j < (int)sl->map.line_size)
		{
			if (sl->map.map[*i][*j] == PLAYER)
			{
				id_floor++;
				return (1);
			}
			(*j)++;
			id_floor++;
		}
		(*i)++;
		if ((int)sl->map.line_size % 2 == 0)
			id_floor++;
	}
	return (0);
}

void	sl_enemy_malloc(t_game *sl)
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
}

void	sl_set_enemies(t_game *sl)
{
	int	i;
	int	j;
	int	id_floor;
	int	ne;

	ne = 0;
	id_floor = 0;
	sl_jump_player(sl, &i, &j, &id_floor);
	while (i < sl->map.total_lines && ne < sl->map.total_p - 1)
	{
		while (++j < (int)sl->map.line_size)
		{
			if (sl->map.map[i][j] == PLAYER)
			{
				sl_init_enemy(sl->enemies[ne], j, i, id_floor % 2);
				sl_change_map(sl, sl->enemies[ne], i, j);
				ne++;
			}
			id_floor++;
		}
		j = 0;
		i++;
		if ((int)sl->map.line_size % 2 == 0)
			id_floor++;
	}
}