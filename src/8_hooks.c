/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_hooks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:09:22 by coder             #+#    #+#             */
/*   Updated: 2022/02/15 18:19:34 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	close_game(t_game *sl)
{
	mlx_destroy_window(sl->mlx.mlx, sl->mlx.win);
	sl->mlx.win = NULL;
	clean_game(sl);
	exit(0);
}

int	sl_key_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_game(game);
	return (0);
}

void	sl_mlx_hooks(t_game *sl)
{
	//mlx_expose_hook(sl->mlx.win, &sl_render_game, sl);
	//mlx_mouse_hook();
	mlx_hook(sl->mlx.win, DestroyNotify, NoEventMask, &close_game, sl);
	mlx_hook(sl->mlx.win, KeyPress, KeyPressMask, &sl_key_press, sl);
	//mlx_loop_hook(sl->mlx.mlx, &sl_render_game, sl);
}