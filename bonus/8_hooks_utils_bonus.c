/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_hooks_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:44:48 by coder             #+#    #+#             */
/*   Updated: 2022/02/19 19:45:46 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static void	update_enemy_idle(t_game *sl, t_enemy *e)
{
	if (e->walk_pos != e->x)
	{
		if (e->walk_pos < e->x)
			e->walk_pos += WALK_DELTA;
		else
			e->walk_pos -= WALK_DELTA;
	}
	// printa apenas um chão do inimigo
	sl_put_enemy(sl, e);
	if (player_near(sl, e) == 0)
		e->status = WALK;
}

int	player_near()//(t_game *sl, t_enemy *e)
{
	// verificar se a posição do player é próximo dele -> IDLE
	/* if (sl->player.x == e->x + TILE_SIZE || sl->player.x == e->x - TILE_SIZE)
		return (1);
	else if (sl->player.y == e->y + TILE_SIZE)
		return (1);
	else if (sl->player.y == e->y - TILE_SIZE)
		return (1); */
	
	ft_printf("Função ainda não feita");
	return (0);
}

void	update_enemy_sprite(t_game *sl, t_enemy *e)
{
	if (sl->player.status == DIE && e->status == ATTACK)
		render_die(sl, e);
	else if (player_dies_x(sl, e))
		set_player_to_die(sl, e);
	else if (player_dies_y(sl, e))
		set_player_to_die(sl, e);
	if (player_near())//(sl, e))
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