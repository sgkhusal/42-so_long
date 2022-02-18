/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:30:03 by coder             #+#    #+#             */
/*   Updated: 2022/02/18 15:06:25 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static void	clean_map(t_game *sl)
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

static void	clean_items(t_game *sl)
{
	int	i;

	i = 0;
	while (sl->items[i])
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
	clean_imgs(sl);
	clean_mlx(sl);
}
