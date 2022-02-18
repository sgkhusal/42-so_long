/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_render_player_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:49:59 by coder             #+#    #+#             */
/*   Updated: 2022/02/18 21:36:35 by coder            ###   ########.fr       */
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
	sl->player.frame = 1;
}

void	put_player(t_game *sl, t_img *sprite)
{
	put_sprite_in_game_img(sl, sprite, sl->player.x, sl->player.y);
}

void	put_player_frame(t_game *sl, t_frames *frames)
{
	if (sl->player.frame == 0)
		put_player(sl, &frames->img0);
	else if (sl->player.frame == 1)
		put_player(sl, &frames->img1);
	else if (sl->player.frame == 2)
		put_player(sl, &frames->img2);
	else if (sl->player.frame == 3)
		put_player(sl, &frames->img3);
}

void	sl_put_player(t_game *sl)
{
	if (sl->player.status == FRONT)
		put_player_frame(sl, &sl->sprites.player.idle_front);
	else if (sl->player.status == BACK)
		put_player_frame(sl, &sl->sprites.player.idle_back);
	else if (sl->player.status == LEFT)
		put_player_frame(sl, &sl->sprites.player.idle_left);
	else if (sl->player.status == RIGHT)
		put_player_frame(sl, &sl->sprites.player.idle_right);
}

void	update_player_sprite(t_game *sl)
{
	put_floor_player(sl);
	sl_put_player(sl);
}
