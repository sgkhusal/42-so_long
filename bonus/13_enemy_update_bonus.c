/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_enemy_update_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:44:48 by coder             #+#    #+#             */
/*   Updated: 2022/02/20 03:10:42 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static int	player_near(t_game *sl, t_enemy *e)
{
	if (sl->player.y - IMG_OFFSET == e->y)
	{
		if (sl->player.x - IMG_OFFSET + TILE_SIZE == e->x)
			return (1);
		else if (sl->player.x - IMG_OFFSET - TILE_SIZE == e->x)
			return (1);
	}
	else if (sl->player.x - IMG_OFFSET == e->x)
	{
		if (sl->player.y - IMG_OFFSET + TILE_SIZE == e->y)
			return (1);
		else if (sl->player.y - IMG_OFFSET - TILE_SIZE == e->y)
			return (1);
	}
	return (0);
}

static void	update_enemy_idle(t_game *sl, t_enemy *e)
{
	if (e->walk_pos != e->x)
		e->walk_pos = e->x;
	put_floor_again(sl, e->x, e->y, (e->id_floor + 1) % 2);
	update_player(sl);
	sl->player_set = PLAYER_RENDER;
	sl_put_enemy(sl, e);
	if (player_near(sl, e) == 0)
		e->status = WALK;
}

static void	update_enemy(t_game *sl, t_enemy *e)
{
	if (e->status == ATTACK)
		update_enemy_attack(sl, e);
	else if (player_dies(sl, e) == 1)
		set_player_to_die(sl, e);
	if (e->status != ATTACK && player_near(sl, e) == 1)
	{
		e->status = IDLE;
		if (sl->player.x < e->x)
			e->view = LEFT;
		else
			e->view = RIGHT;
	}
	if (e->status == IDLE)
		update_enemy_idle(sl, e);
	else if (e->status == WALK)
		update_enemy_walk(sl, e);
}

void	update_enemies(t_game *sl)
{
	int	ne;

	ne = 0;
	while (ne < sl->map.total_p - 1)
	{
		sl->enemies[ne]->frame++;
		if (sl->enemies[ne]->frame == ENEMY_FRAMES)
		{
			if (sl->enemies[ne]->status != ATTACK)
				sl->enemies[ne]->frame = 0;
		}
		update_enemy(sl, sl->enemies[ne]);
		ne++;
	}
}
