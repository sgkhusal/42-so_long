/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14_enemy_move_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:51:19 by coder             #+#    #+#             */
/*   Updated: 2022/02/20 03:16:39 by coder            ###   ########.fr       */
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

/* static void	set_enemy_relative_pos(t_enemy *e)
{
	e->relative_id_floor = (e->relative_id_floor + 1) % 2;
	if (e->view == RIGHT && !(e->walk_pos + WALK_DELTA> e->walk_final))
		e->relative_x = e->walk_pos;
	else if (e->view == LEFT && !(e->walk_pos - WALK_DELTA < e->walk_init))
		e->relative_x = e->relative_x - TILE_SIZE;
} */

static void enemy_walk_right(t_enemy *e)
{
	e->walk_pos += WALK_DELTA;
	if (e->walk_pos > e->walk_final)
	{
		e->view = LEFT;
		e->walk_pos = e->walk_final;
		//e->x = e->walk_pos - TILE_SIZE;
	}
	/* else if (e->walk_pos % TILE_SIZE == 0) ////////
		set_enemy_relative_pos(e); */
}

static void enemy_walk_left(t_enemy *e)
{
	e->walk_pos -= WALK_DELTA;
	if (e->walk_pos < e->walk_init)
	{
		e->view = RIGHT;
		e->walk_pos = e->walk_init;
		//e->x = e->walk_pos + TILE_SIZE;
	}
	/* else if (e->walk_pos % TILE_SIZE == 0) //////////
		set_enemy_relative_pos(e); */
}

void	update_enemy_walk(t_game *sl, t_enemy *e)
{
	put_floor_enemy_walk(sl, e);
	if (e->view == RIGHT)
		enemy_walk_right(e);
	else if (e->view == LEFT)
		enemy_walk_left(e);
	sl_put_enemy(sl, e);
}
