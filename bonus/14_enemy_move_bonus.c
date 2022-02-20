/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14_enemy_move_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:51:19 by coder             #+#    #+#             */
/*   Updated: 2022/02/20 20:00:23 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	put_floor_enemies_walk(t_game *sl)
{
	int	i;
	int	j;

	i = 0;
	while (i < sl->map.total_lines)
	{
		j = 0;
		while (j < (int)sl->map.line_size)
		{
			if (sl->map.map[i][j] == ENEMY0)
				put_floor_again(sl, j * TILE_SIZE, i * TILE_SIZE, 0);
			else if (sl->map.map[i][j] == ENEMY1)
				put_floor_again(sl, j * TILE_SIZE, i * TILE_SIZE, 1);
			j++;
		}
		i++;
	}
}

static void	enemy_walk_right(t_enemy *e)
{
	e->walk_pos += WALK_DELTA;
	if (e->walk_pos > e->walk_final)
	{
		e->view = LEFT;
		e->walk_pos = e->walk_final;
	}
	if (e->walk_pos % TILE_SIZE == TILE_SIZE / 2)
		e->x = e->walk_pos + TILE_SIZE / 2;
}

static void	enemy_walk_left(t_enemy *e)
{
	e->walk_pos -= WALK_DELTA;
	if (e->walk_pos < e->walk_init)
	{
		e->view = RIGHT;
		e->walk_pos = e->walk_init;
	}
	if (e->walk_pos % TILE_SIZE == TILE_SIZE / 2)
		e->x = e->walk_pos - TILE_SIZE / 2;
}

void	update_enemy_walk(t_game *sl, t_enemy *e)
{
	if (e->view == RIGHT)
		enemy_walk_right(e);
	else if (e->view == LEFT)
		enemy_walk_left(e);
	sl_put_enemy(sl, e);
}
