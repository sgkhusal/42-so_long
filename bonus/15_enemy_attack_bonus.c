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
	put_floor_again(sl, e->x, e->y, (e->id_floor + 1) % 2);
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
