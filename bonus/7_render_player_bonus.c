/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_render_player_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:49:59 by coder             #+#    #+#             */
/*   Updated: 2022/02/18 15:58:13 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	sl_init_player(t_game *sl, int x, int y, int id_floor)
{
	sl->player.status = FRONT;
	sl->player.id_floor = id_floor;
	sl->player.x = x;
	sl->player.y = y;
	sl->player_set = SET;
	sl->sprites.player.frame = 0;
}

void	put_player(t_game *sl, t_img *sprite)
{
	put_sprite_in_game_img(sl, sprite, sl->player.x, sl->player.y);
}

void	sl_put_player(t_game *sl, t_frames_player *sprites, int frame)
{
	if (sl->player.status == FRONT)
		put_player(sl, &sprites->idle_front[frame]);
	else if (sl->player.status == BACK)
		put_player(sl, &sprites->idle_back[frame]);
	else if (sl->player.status == LEFT)
		put_player(sl, &sprites->idle_left[frame]);
	else if (sl->player.status == RIGHT)
		put_player(sl, &sprites->idle_right[frame]);
}

void	update_player_sprite(t_game *sl)
{
	put_floor_player(sl);
	sl_put_player(sl, &sl->sprites.player, sl->sprites.player.frame);
}
