/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16_enemy_attack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 02:03:56 by coder             #+#    #+#             */
/*   Updated: 2022/02/20 02:42:59 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	put_floor_player_die(t_game *sl)
{
	if (sl->player.view == RIGHT)
		put_floor_again(sl, sl->player.x - (TILE_SIZE / 2),
			sl->player.y - IMG_OFFSET, (sl->player.id_floor + 1) % 2);
	else if (sl->player.view == LEFT)
		put_floor_again(sl, sl->player.x, sl->player.y - IMG_OFFSET,
			(sl->player.id_floor + 1) % 2);
	else if (sl->player.view == FRONT)
		put_floor_again(sl, sl->player.x - (TILE_SIZE / 2),
			sl->player.y - PLAYER_Y_DIE, (sl->player.id_floor + 1) % 2);
	else if (sl->player.view == BACK)
		put_floor_again(sl, sl->player.x - (TILE_SIZE / 2),
			sl->player.y + (TILE_SIZE / 2), (sl->player.id_floor + 1) % 2);
}

void	update_enemy_attack(t_game *sl, t_enemy *e)
{
	put_floor_again(sl, e->x, e->y, e->id_floor % 2); // verificar se usa o e->x ou outro param
	if (e->frame != ENEMY_FRAMES)
		update_player(sl);
	else
		put_floor_player_die(sl);
	sl->player_set = PLAYER_RENDER;
	sl_put_enemy(sl, e);
	if (e->frame == ENEMY_FRAMES)
	{
		if (sl->mlx.win != NULL)
			mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win, sl->img.img,
				0, 0);
		ft_printf("\n\nYOU DIE!! TRY AGAIN...\n\n");
		close_game(sl);
	}
}

/* void	render_die(t_game *sl, t_enemy *e)
{
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
} */
