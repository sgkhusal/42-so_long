/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_render_collectibles.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 02:35:12 by coder             #+#    #+#             */
/*   Updated: 2022/02/18 15:06:00 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static	int	sl_set_item(t_game *sl, int nc, int id_img, int idx[2])
{
	sl->items[nc] = (t_item *)malloc(sizeof(t_item));
	if (!sl->items[nc])
		sl_error("Malloc error for set item.", sl);
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
		sl_error("Malloc error for sl->items.", sl);
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

static void	sl_put_item(t_game *sl, t_img *sprite, int nc)
{
	put_sprite_in_game_img(sl, sprite, sl->items[nc]->x, sl->items[nc]->y);
}

void	sl_put_collectibles(t_game *sl)
{
	int	nc;

	nc = 0;
	while (nc < sl->map.total_c)
	{
		if (sl->items[nc]->id_img == 0)
			sl_put_item(sl, &sl->sprites.items.item0, nc);
		else if (sl->items[nc]->id_img == 1)
			sl_put_item(sl, &sl->sprites.items.item1, nc);
		else if (sl->items[nc]->id_img == 2)
			sl_put_item(sl, &sl->sprites.items.item2, nc);
		else if (sl->items[nc]->id_img == 3)
			sl_put_item(sl, &sl->sprites.items.item3, nc);
		else if (sl->items[nc]->id_img == 4)
			sl_put_item(sl, &sl->sprites.items.item4, nc);
		else if (sl->items[nc]->id_img == 5)
			sl_put_item(sl, &sl->sprites.items.item5, nc);
		nc++;
	}
}
