/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:05:27 by coder             #+#    #+#             */
/*   Updated: 2022/02/16 15:20:33 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	clean_imgs_items(t_game *sl)
{
	if (sl->sprites.item0.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.item0.img);
	if (sl->sprites.item1.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.item1.img);
	if (sl->sprites.item2.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.item2.img);
	if (sl->sprites.item3.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.item3.img);
	if (sl->sprites.item4.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.item4.img);
	if (sl->sprites.item5.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.item5.img);
}

static void	clean_imgs_player(t_game *sl)
{
	if (sl->sprites.front0.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.front0.img);
	if (sl->sprites.back0.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.back0.img);
	if (sl->sprites.left0.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.left0.img);
	if (sl->sprites.right0.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.right0.img);
}

void	clean_imgs(t_game *sl)
{
	if (sl->sprites.floor0.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.floor0.img);
	if (sl->sprites.floor1.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.floor1.img);
	if (sl->sprites.wall.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.wall.img);
	if (sl->sprites.corner.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.corner.img);
	if (sl->sprites.exit.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.exit.img);
	clean_imgs_items(sl);
	clean_imgs_player(sl);
	if (sl->img.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->img.img);
}
