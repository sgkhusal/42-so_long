/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16_player_dies_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:51:28 by coder             #+#    #+#             */
/*   Updated: 2022/02/20 03:26:45 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	set_player_to_die(t_game *sl, t_enemy *e)
{
	sl->player.status = DIE;
	e->status = ATTACK;
	e->frame = 0;
	if (sl->player.view == RIGHT)
		sl->player.x = e->x - (TILE_SIZE / 2);
	if (sl->player.view == LEFT)
		sl->player.x = e->x + TILE_SIZE;
	if (sl->player.view == FRONT)
	{
		sl->player.x = e->x + (TILE_SIZE / 2);
		sl->player.y = e->y - TILE_SIZE + PLAYER_Y_DIE;
	}
	if (sl->player.view == BACK)
	{
		sl->player.y = e->y + (TILE_SIZE / 2);
		sl->player.x = e->x + (TILE_SIZE / 2);
	}
		
}

int	player_dies(t_game *sl, t_enemy *e)
{
	if (sl->player.y - IMG_OFFSET == e->y)
	{
		if (sl->player.x - IMG_OFFSET == e->x)
			return (1);
		else
			return (0);
	}
	return (0);
}
