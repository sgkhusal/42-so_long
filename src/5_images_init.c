/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_images_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:19:35 by coder             #+#    #+#             */
/*   Updated: 2022/02/13 01:47:41 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	sl_images_init_wall(t_game *sl)
{
	sl->wall.img = mlx_xpm_file_to_image(sl->mlx.mlx,
			"assets/images/wall.xpm", &sl->wall.width, &sl->wall.height);
	if (!sl->wall.img)
		sl_error("Mlx error loading wall image.", sl);
	sl->corner.img = mlx_xpm_file_to_image(sl->mlx.mlx,
			"assets/images/corner.xpm", &sl->corner.width, &sl->corner.height);
	if (!sl->corner.img)
		sl_error("Mlx error loading corner image.", sl);
	sl->mid_wall.img = mlx_xpm_file_to_image(sl->mlx.mlx,
			"assets/images/wall2.xpm", &sl->mid_wall.width,
			&sl->mid_wall.height);
	if (!sl->mid_wall.img)
		sl_error("Mlx error loading mid_wall image.", sl);
}

static void	sl_images_init_floor(t_game *sl)
{
	sl->floor1.img = mlx_xpm_file_to_image(sl->mlx.mlx,
			"assets/images/floor1.xpm", &sl->floor1.width, &sl->floor1.height);
	if (!sl->floor1.img)
		sl_error("Mlx error loading floor1 image.", sl);
	sl->floor2.img = mlx_xpm_file_to_image(sl->mlx.mlx,
			"assets/images/floor2.xpm", &sl->floor2.width, &sl->floor2.height);
	if (!sl->floor2.img)
		sl_error("Mlx error loading floor2 image.", sl);
}

static void	sl_images_init_collectible(t_game *sl)
{
	sl->collectible.img = mlx_xpm_file_to_image(sl->mlx.mlx,
			"assets/images/tiger_eye.xpm", &sl->collectible.width,
			&sl->collectible.height);
}

static void	sl_images_init_player(t_game *sl)
{
	sl->player.img = mlx_xpm_file_to_image(sl->mlx.mlx,
			"assets/images/player_front.xpm", &sl->player.width,
			&sl->player.height);
}

void	sl_images_init(t_game *sl)
{
	sl_images_init_wall(sl);
	sl_images_init_floor(sl);
	sl_images_init_collectible(sl);
	sl_images_init_player(sl);
	sl->exit.img = mlx_xpm_file_to_image(sl->mlx.mlx,
			"assets/images/stair_exit.xpm", &sl->exit.width, &sl->exit.height);
}
