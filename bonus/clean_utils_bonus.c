/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:05:27 by coder             #+#    #+#             */
/*   Updated: 2022/02/20 15:07:19 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static void	clean_imgs_items(t_game *sl)
{
	if (sl->sprites.items.item0.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.items.item0.img);
	if (sl->sprites.items.item1.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.items.item1.img);
	if (sl->sprites.items.item2.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.items.item2.img);
	if (sl->sprites.items.item3.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.items.item3.img);
	if (sl->sprites.items.item4.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.items.item4.img);
	if (sl->sprites.items.item5.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.items.item5.img);
}

static void	clean_player_frames(t_game *sl, t_frames *frames)
{
	if (frames->img0.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, frames->img0.img);
	if (frames->img1.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, frames->img1.img);
	if (frames->img2.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, frames->img2.img);
}

static void	clean_frames(t_game *sl, t_frames *frames)
{
	if (frames->img0.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, frames->img0.img);
	if (frames->img1.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, frames->img1.img);
	if (frames->img2.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, frames->img2.img);
	if (frames->img3.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, frames->img3.img);
	if (frames->img4.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, frames->img4.img);
	if (frames->img5.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, frames->img5.img);
	if (frames->img6.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, frames->img6.img);
	if (frames->img7.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, frames->img7.img);
}

void	clean_imgs(t_game *sl)
{
	if (sl->tiles.floor0.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->tiles.floor0.img);
	if (sl->tiles.floor1.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->tiles.floor1.img);
	if (sl->tiles.wall.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->tiles.wall.img);
	if (sl->tiles.corner.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->tiles.corner.img);
	if (sl->tiles.exit.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->tiles.exit.img);
	clean_imgs_items(sl);
	clean_player_frames(sl, &sl->sprites.player.back);
	clean_player_frames(sl, &sl->sprites.player.front);
	clean_player_frames(sl, &sl->sprites.player.right);
	clean_player_frames(sl, &sl->sprites.player.left);
	clean_frames(sl, &sl->sprites.enemy.walk_left);
	clean_frames(sl, &sl->sprites.enemy.walk_right);
	clean_frames(sl, &sl->sprites.enemy.attack_l);
	clean_frames(sl, &sl->sprites.enemy.attack_r);
	if (sl->img.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->img.img);
}
