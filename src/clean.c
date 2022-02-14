/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:30:03 by coder             #+#    #+#             */
/*   Updated: 2022/02/12 03:36:57 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	clean_map(t_game *sl)
{
	int	i;

	i = 0;
	ft_clean(&sl->map.linear_map);
	while (sl->map.map[i])
	{
		ft_clean(&sl->map.map[i]);
		i++;
	}
	if (sl->map.map)
	{
		free(sl->map.map);
		sl->map.map = NULL;
	}
}

void	clean_mlx(t_game *sl)
{
	mlx_destroy_window(sl->mlx.mlx, sl->mlx.win);
	mlx_destroy_display(sl->mlx.mlx);
	mlx_destroy_image(sl->mlx.mlx, sl->sprites.floor0.img);
	mlx_destroy_image(sl->mlx.mlx, sl->sprites.floor1.img);
	free(sl->mlx.mlx);
}
