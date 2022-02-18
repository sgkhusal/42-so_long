/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:05:27 by coder             #+#    #+#             */
/*   Updated: 2022/02/18 15:06:20 by coder            ###   ########.fr       */
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

/* static void	clean_frames(t_game *sl, t_image **frames)
{
	int	i;
	
	if (frames)
	{
		i = 0;
		while (frames[i])
		{
			if (frames[i]->img != NULL)
				mlx_destroy_image(sl->mlx.mlx, frames[i]->img);
			frames[i] = NULL;
			i++;
		}
		free(frames);
		frames = NULL;
	}
}
 */
/* static void	clean_imgs_player(t_game *sl)
{
	//clean_frames(sl,sl->player.sprites.idle_front[0]);
	clean_frames(sl,sl->player.sprites.idle_back);
	clean_frames(sl,sl->player.sprites.idle_right);
	clean_frames(sl,sl->player.sprites.idle_left);
	clean_frames(sl,sl->player.sprites.run_front);
	clean_frames(sl,sl->player.sprites.run_back);
	clean_frames(sl,sl->player.sprites.run_right);
	clean_frames(sl,sl->player.sprites.run_left); */

	/* while (frames[i])
	{
		if (sl->player.sprites.idle_front[i].img != NULL)
			mlx_destroy_image(sl->player.sprites.idle_front[i].img);
		i++;
	}
	i = -1;
	while (sl->player.sprites.idle_back[++i])
	{
		if (sl->player.sprites.idle_back[i].img != NULL)
			mlx_destroy_image(sl->player.sprites.idle_back[i].img);
	}
	i = -1;
	while (sl->player.sprites.idle_right[++i])
	{
		if (sl->player.sprites.idle_right[i].img != NULL)
			mlx_destroy_image(sl->player.sprites.idle_right[i].img);
	}
	i = -1;
	while (sl->player.sprites.idle_left[++i])
	{
		if (sl->player.sprites.idle_left[i].img != NULL)
			mlx_destroy_image(sl->player.sprites.idle_left[i].img);
	} */

//}

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
	//clean_imgs_player(sl);
	if (sl->img.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->img.img);
}
