/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_render_collectibles.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 02:35:12 by coder             #+#    #+#             */
/*   Updated: 2022/02/17 19:26:11 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static	int	sl_set_item(t_game *sl, int nc, int id_img, int idx[2])
{
	sl->items[nc] = (t_item *)malloc(sizeof(t_item));
	if (!sl->items[nc])
		sl_error("Malloc error 2 in sl_set_item function.", sl);
	sl->items[nc]->status = NOT_COLLECTED;
	sl->items[nc]->x = idx[1] * TILE_SIZE + SMALL_IMG_OFFSET;
	sl->items[nc]->y = idx[0] * TILE_SIZE + SMALL_IMG_OFFSET;
	sl->items[nc]->id_img = id_img;
	id_img++;
	if (id_img == 6)
		id_img = 0;
	return (id_img);
}

void	sl_set_collectibles(t_game *sl)
{
	int	idx[2];
	int	nc;
	int	id_img;

	sl->items = (t_item **)malloc((sl->map.total_c + 1) * sizeof(t_item));
	if (!sl->items)
		sl_error("Malloc error in sl_set_collectibles function.", sl);
	idx[0] = 0;
	nc = 0;
	id_img = 0;
	while (++idx[0] < sl->map.total_lines - 1 && nc < sl->map.total_c)
	{
		idx[1] = 1;
		while (idx[1] < (int)sl->map.line_size - 1)
		{
			if (sl->map.map[idx[0]][idx[1]] == COLLECTIBLE)
			{
				id_img = sl_set_item(sl, nc, id_img, idx);
				nc++;
			}
			idx[1]++;
		}
	}
	sl->items[nc] = NULL;
}

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

static void	sl_put_item(t_game *sl, t_image *sprite, int nc)
{
	put_sprite_in_game_img(sl, sprite, sl->items[nc]->x, sl->items[nc]->y);
}

void	sl_put_collectibles(t_game *sl)
{
	int	nc;

	nc = 0;
	while (nc < sl->map.total_c)
	{
		if (sl->items[nc]->status == NOT_COLLECTED)
		{
			if (sl->items[nc]->id_img == 0)
				sl_put_item(sl, &sl->sprites.item0, nc);
			else if (sl->items[nc]->id_img == 1)
				sl_put_item(sl, &sl->sprites.item1, nc);
			else if (sl->items[nc]->id_img == 2)
				sl_put_item(sl, &sl->sprites.item2, nc);
			else if (sl->items[nc]->id_img == 3)
				sl_put_item(sl, &sl->sprites.item3, nc);
			else if (sl->items[nc]->id_img == 4)
				sl_put_item(sl, &sl->sprites.item4, nc);
			else if (sl->items[nc]->id_img == 5)
				sl_put_item(sl, &sl->sprites.item5, nc);
		}
		nc++;
	}
}
