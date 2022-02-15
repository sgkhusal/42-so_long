/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:30:03 by coder             #+#    #+#             */
/*   Updated: 2022/02/15 16:02:09 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	clean_map(t_game *sl)
{
	int	i;

	i = 0;
	if (sl->map.linear_map)
		ft_clean(&sl->map.linear_map);
	if (sl->map.map)
	{
		while (sl->map.map[i])
		{
			ft_clean(&sl->map.map[i]);
			i++;
		}
		free(sl->map.map);
		sl->map.map = NULL;
	}
}

void	clean_items(t_game *sl)
{
	int	i;

	i = 0;
	while(sl->items[i])
	{
		free(sl->items[i]);
		sl->items[i] = NULL;
		i++;
	}
	free(sl->items);
	sl->items = NULL;
}

void	clean_mlx(t_game *sl)
{
	
	if (sl->sprites.floor0.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.floor0.img);
	if (sl->sprites.floor1.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.floor1.img);
	if (sl->sprites.wall.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.wall.img);
	if (sl->sprites.corner.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.corner.img);
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
	if (sl->sprites.exit.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.exit.img);
	if (sl->sprites.front0.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.front0.img);
	if (sl->sprites.back0.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.back0.img);
	if (sl->sprites.left0.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->sprites.left0.img);
		//if (sl->sprites.right0.img != NULL)
	//mlx_destroy_image(sl->mlx.mlx, sl->sprites.right0.img);
	if (sl->img.img != NULL)
		mlx_destroy_image(sl->mlx.mlx, sl->img.img);
	if (sl->mlx.win != NULL)
		mlx_destroy_window(sl->mlx.mlx, sl->mlx.win);
	sl->mlx.win = NULL;
	if (sl->mlx.mlx != NULL)
		mlx_destroy_display(sl->mlx.mlx);
	free(sl->mlx.mlx);
	sl->mlx.mlx = NULL;
}

void	clean_game(t_game *sl)
{
	clean_map(sl);
	clean_items(sl);
	clean_mlx(sl);
}
