/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_render_player_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:49:59 by coder             #+#    #+#             */
/*   Updated: 2022/04/01 20:13:06 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	sl_init_player(t_game *sl, int x, int y, int id_floor)
{
	sl->player.status = IDLE;
	sl->player.view = FRONT;
	sl->player.id_floor = id_floor;
	sl->player.x = x;
	sl->player.y = y;
	sl->player_set = PLAYER_NOT_RENDER;
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
		put_player(sl, &frames->img0);
}

void	sl_put_player(t_game *sl)
{
	if (sl->player.view == FRONT)
		put_player_frame(sl, &sl->sprites.player.front);
	else if (sl->player.view == BACK)
		put_player_frame(sl, &sl->sprites.player.back);
	else if (sl->player.view == LEFT)
		put_player_frame(sl, &sl->sprites.player.left);
	else if (sl->player.view == RIGHT)
		put_player_frame(sl, &sl->sprites.player.right);
}

void	update_player(t_game *sl)
{
	sl->player.frame++;
	if (sl->player.frame == PLAYER_FRAMES)
		sl->player.frame = 0;
	if (sl->player.status == DIE)
		put_floor_player_die(sl);
	else
		put_floor_player(sl);
	sl_put_player(sl);
}
