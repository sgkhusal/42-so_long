/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_render_enemies_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:47:35 by coder             #+#    #+#             */
/*   Updated: 2022/02/19 15:44:35 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	put_enemy(t_game *sl, t_img *sprite, t_enemy *e)
{
	put_sprite_in_game_img(sl, sprite, e->walk_pos, e->y);
}

void	put_enemy_frame(t_game *sl, t_enemy *e, t_frames *frames)
{
	if (e->frame == 0)
		put_enemy(sl, &frames->img0, e);
	else if (e->frame == 1)
		put_enemy(sl, &frames->img1, e);
	else if (e->frame == 2)
		put_enemy(sl, &frames->img2, e);
	else if (e->frame == 3)
		put_enemy(sl, &frames->img3, e);
	else if (e->frame == 4)
		put_enemy(sl, &frames->img4, e);
	else if (e->frame == 5)
		put_enemy(sl, &frames->img5, e);
	else if (e->frame == 6)
		put_enemy(sl, &frames->img6, e);
	else if (e->frame == 7)
		put_enemy(sl, &frames->img7, e);
}

void	sl_put_enemy(t_game *sl, t_enemy *e)
{
	if (e->status == LEFT)
		put_enemy_frame(sl, e, &sl->sprites.enemy.walk_left);
	else if (e->status == RIGHT)
		put_enemy_frame(sl, e, &sl->sprites.enemy.walk_right);
}

void	sl_put_enemies(t_game *sl)
{
	int	ne;

	ne = 0;
	while (ne < sl->map.total_p - 1)
	{
		sl_put_enemy(sl, sl->enemies[ne]);
		ne++;
	}
}
