/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_enemy_move_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:51:19 by coder             #+#    #+#             */
/*   Updated: 2022/02/19 19:32:43 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static void	put_floor_enemy_walk(t_game *sl, t_enemy *e)
{
	int	i;
	int	x;
	int	id_floor;

	i = 0;
	x = e->walk_init;
	id_floor = e->id_floor;
	while (i < e->walk_size)
	{
		put_floor_again(sl, x, e->y, id_floor);
		id_floor = (id_floor + 1) % 2;
		x += TILE_SIZE;
		i++;
	}
}

void	update_enemy_walk(t_game *sl, t_enemy *e)
{
	put_floor_enemy_walk(sl, e);
	if (e->view == RIGHT)
	{
		e->walk_pos += WALK_DELTA;
		if (e->walk_pos > e->walk_final)
		{
			e->view = LEFT;
			e->walk_pos = e->walk_final;
		}
	}
	else if (e->view == LEFT)
	{
		e->walk_pos -= WALK_DELTA;
		if (e->walk_pos < e->walk_init)
		{
			e->view = RIGHT;
			e->walk_pos = e->walk_init;
		}
	}
	sl_put_enemy(sl, e);
}
