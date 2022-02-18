/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_hooks_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:09:22 by coder             #+#    #+#             */
/*   Updated: 2022/02/18 22:46:16 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	close_game(t_game *sl)
{
	mlx_destroy_window(sl->mlx.mlx, sl->mlx.win);
	sl->mlx.win = NULL;
	clean_game(sl);
	exit(0);
}

/*static int	render_game_again(t_game *sl)
{
	 static int	count;

	count++;
	if (count % 500 == 0)
	{
		if (sl->mlx.win != NULL)
		{
			
			mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win, sl->img.img, 0, 0);
		}
	}
	else
		sl_error("Not possible to render game. Mlx window is set as NULL.", sl);
	return (0);
}*/

static int	render_game_again(t_game *sl)
{
	static int	count;

	count++;
	if (count % 1000 == 0)
	{
		sl->player.frame++;
		if (sl->player.frame == PLAYER_FRAMES)
			sl->player.frame = 0;
		update_player_sprite(sl);
	}
	if (sl->mlx.win != NULL)
		mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win, sl->img.img, 0, 0);
	else
		sl_error("Not possible to render game. Mlx window is set as NULL.", sl);
	return (0);
}

static int	sl_key_press(int key, t_game *sl)
{
	if (key == XK_Escape)
		close_game(sl);
	else if (key == XK_d || key == XK_Right)
		sl_move_right(sl);
	else if (key == XK_a || key == XK_Left)
		sl_move_left(sl);
	else if (key == XK_w || key == XK_Up)
		sl_move_up(sl);
	else if (key == XK_s || key == XK_Down)
		sl_move_down(sl);
	return (0);
}

void	sl_mlx_hooks(t_game *sl)
{
	mlx_expose_hook(sl->mlx.win, &render_game_again, sl);
	mlx_hook(sl->mlx.win, DestroyNotify, NoEventMask, &close_game, sl);
	mlx_hook(sl->mlx.win, KeyPress, KeyPressMask, &sl_key_press, sl);
	mlx_loop_hook(sl->mlx.mlx, &render_game_again, sl);
}
