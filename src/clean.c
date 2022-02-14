/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:30:03 by coder             #+#    #+#             */
/*   Updated: 2022/02/14 21:16:42 by coder            ###   ########.fr       */
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
	mlx_destroy_image(sl->mlx.mlx, sl->sprites.floor0.img);
	mlx_destroy_image(sl->mlx.mlx, sl->sprites.floor1.img);
	mlx_destroy_image(sl->mlx.mlx, sl->sprites.wall.img);
	mlx_destroy_image(sl->mlx.mlx, sl->sprites.corner.img);
	mlx_destroy_image(sl->mlx.mlx, sl->sprites.item0.img);
	mlx_destroy_image(sl->mlx.mlx, sl->sprites.item1.img);
	mlx_destroy_image(sl->mlx.mlx, sl->sprites.item2.img);
	mlx_destroy_image(sl->mlx.mlx, sl->sprites.item3.img);
	mlx_destroy_image(sl->mlx.mlx, sl->sprites.item4.img);
	mlx_destroy_image(sl->mlx.mlx, sl->sprites.item5.img);
	mlx_destroy_image(sl->mlx.mlx, sl->sprites.item2.img);
	mlx_destroy_image(sl->mlx.mlx, sl->sprites.exit.img);
	mlx_destroy_image(sl->mlx.mlx, sl->sprites.front1.img);
	mlx_destroy_image(sl->mlx.mlx, sl->sprites.back1.img);
	mlx_destroy_image(sl->mlx.mlx, sl->sprites.left1.img);
	//mlx_destroy_image(sl->mlx.mlx, sl->sprites.right1.img);
	mlx_destroy_image(sl->mlx.mlx, sl->img.img);
	mlx_destroy_window(sl->mlx.mlx, sl->mlx.win);
	mlx_destroy_display(sl->mlx.mlx);
	free(sl->mlx.mlx);
}
