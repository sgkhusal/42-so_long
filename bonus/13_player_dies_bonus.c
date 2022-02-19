/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_player_dies_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:51:28 by coder             #+#    #+#             */
/*   Updated: 2022/02/19 19:46:59 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	set_player_to_die(t_game *sl, t_enemy *e)
{
	sl->player.status = DIE;
	/* if (sl->player.view == RIGHT)
		sl->player.walk_final_x = e->x - TILE_SIZE / 2;
	if (sl->player.view == LEFT)
		sl->player.walk_final_x = e->x + TILE_SIZE / 2;
	if (sl->player.view == FRONT)
		sl->player.walk_final_x = e->x - TILE_SIZE / 2;
	if (sl->player.view == BACK)
		sl->player.walk_final_x = e->x - TILE_SIZE / 2; */
	e->status = ATTACK;
	e->frame = 0;
}

int	player_dies_x(t_game *sl, t_enemy *e)
{
	if (sl->player.view == RIGHT)
	{
		if (sl->player.walk_final_x + IMG_OFFSET == e->walk_final)
			return (1);
		else
			return(0);
	}
	else if (sl->player.view == LEFT)
	{
		if (sl->player.walk_final_x - IMG_OFFSET == e->walk_final)
			return (1);
		else
			return(0);
	}
	else
		return(0);
}

int	player_dies_y(t_game *sl, t_enemy *e)
{
	if (sl->player.view == FRONT)
	{
		if (sl->player.walk_final_y + IMG_OFFSET == e->y + IMG_OFFSET)
			return (1);
		else
			return(0);
	}
	else if (sl->player.view == BACK)
	{
		if (sl->player.walk_final_y + IMG_OFFSET == e->y + IMG_OFFSET)
			return (1);
		else
			return(0);
	}
	else
		return(0);
}

void	render_die(t_game *sl, t_enemy *e)
{
	if (e->frame == ENEMY_FRAMES)
	{
		ft_printf("\n\nYOU DIE!! TRY AGAIN...\n\n");
		close_game(sl);
	}
	//printa o chão do player e do inimigo
	if (sl->player.view == RIGHT)
	{
		if (sl->player.walk_pos_x != sl->player.walk_final_x)
		{
			sl->player.walk_pos_x += WALK_DELTA;
			//printa o player na nova posição
		}
		else
			update_player_sprite(sl);
	}
	if (sl->player.view == LEFT)
	{
		if (sl->player.walk_pos_x != sl->player.walk_final_x)
		{
			sl->player.walk_pos_x -= WALK_DELTA;
			//printa o player na nova posição
		}
		else
			update_player_sprite(sl);
	}
	if (sl->player.view == FRONT)
	{
		if (sl->player.walk_pos_y != sl->player.walk_final_y)
		{
			sl->player.walk_pos_y += WALK_DELTA;
			//printa o player na nova posição
		}
		else
			update_player_sprite(sl);
	}
	if (sl->player.view == BACK)
	{
		if (sl->player.walk_pos_y != sl->player.walk_final_y)
		{
			sl->player.walk_pos_y -= WALK_DELTA;
			//printa o player na nova posição
		}
		else
			update_player_sprite(sl);
	}
	// printa o inimigo
}
