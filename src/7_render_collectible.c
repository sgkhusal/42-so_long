/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_render_collectible.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 02:35:12 by coder             #+#    #+#             */
/*   Updated: 2022/02/13 02:39:02 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	sl_set_collectible_id_floor(t_game *sl, int x, int y, int id_floor)
{
	int	nc;

	nc = 0;
	while (nc < sl->map.total_c)
	{
		if (sl->items[nc]->x == x && sl->items[nc]->y == y)
		{
			sl->items[nc]->id_floor = id_floor;
			return ;
		}
		nc++;
	}
}

void	sl_set_collectibles(t_game *sl)
{
	int	i;
	int	j;
	int	nc;
	int	id_img;
	
	sl->items = (t_item **)malloc((sl->map.total_c + 1) * sizeof(t_item));
	if (!sl->items)
		sl_error("Malloc error in sl_set_collectibles function.", sl);
	i = 1;
	nc = 0;
	id_img = 0;
	while (i < sl->map.total_lines - 1 && nc < sl->map.total_c)
	{
		j = 1;
		while (j < (int)sl->map.line_size - 1)
		{
			if (sl->map.map[i][j] == COLLECTIBLE)
			{
				sl->items[nc] = (t_item *)malloc(sizeof(t_item));
				if (!sl->items[nc])
					sl_error("Malloc error 2 in sl_set_collectibles function.", sl);
				sl->items[nc]->status = ITEM_NOT_COLLECT;
				sl->items[nc]->x = j * TILE_SIZE + SMALL_IMG_OFFSET;
				sl->items[nc]->y = i * TILE_SIZE + SMALL_IMG_OFFSET;
				sl->items[nc]->id_img = id_img;
				id_img++;
				nc++;
			}
			if (id_img == 2)
				id_img = 0;
			j++;
		}
		i++;
	}
	sl->items[nc] = NULL;
}

static void	sl_render_c(t_game *sl, int nc, void *img)
{
	mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win, img, sl->items[nc]->x,
		sl->items[nc]->y);
}

void	sl_render_collectibles(t_game *sl)
{
	int	nc;
	
	nc = 0;
	while (nc < sl->map.total_c)
	{
		if (sl->items[nc]->status == ITEM_NOT_COLLECT)
		{
			if (sl->items[nc]->id_img == 0)
				sl_render_c(sl, nc, sl->item0.img);
			else if (sl->items[nc]->id_img == 1)
				sl_render_c(sl, nc, sl->item1.img);
		}
		nc++;
	}
	
}
