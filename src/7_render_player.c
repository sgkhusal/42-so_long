/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_render_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:49:59 by coder             #+#    #+#             */
/*   Updated: 2022/02/19 16:39:44 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	sl_init_player(t_game *sl, int x, int y, int id_floor)
{
	sl->player.view = FRONT;
	sl->player.id_floor = id_floor;
	sl->player.x = x;
	sl->player.y = y;
	sl->player_set = SET;
}

void	put_player(t_game *sl, t_image *sprite)
{
	put_sprite_in_game_img(sl, sprite, sl->player.x, sl->player.y);
}

void	sl_put_player(t_game *sl)
{
	if (sl->player.view == FRONT)
		put_player(sl, &sl->sprites.front0);
	else if (sl->player.view == BACK)
		put_player(sl, &sl->sprites.back0);
	else if (sl->player.view == LEFT)
		put_player(sl, &sl->sprites.left0);
	else if (sl->player.view == RIGHT)
		put_player(sl, &sl->sprites.right0);
}

void	update_player_sprite(t_game *sl)
{
	put_floor_player(sl);
	sl_put_player(sl);
}
