/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_game_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:37:23 by coder             #+#    #+#             */
/*   Updated: 2022/02/20 19:39:25 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	sl_render_game(t_game *sl)
{
	int	i;
	int	j;
	int	id_floor;

	i = -1;
	id_floor = 0;
	while (++i < sl->map.total_lines)
	{
		j = 0;
		while (j < (int)sl->map.line_size)
		{
			sl_put_static_map(sl, i, j, id_floor);
			j++;
			id_floor++;
		}
		if ((int)sl->map.line_size % 2 == 0)
			id_floor++;
	}
	put_sprite_in_game_img(sl, &sl->img_moves, IMG_MOVE_X, IMG_MOVE_Y);
	sl_put_collectibles(sl);
	sl_put_player(sl);
	if (sl->map.total_p > 1)
		sl_put_enemies(sl);
	mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win, sl->img.img, 0, 0);
	print_move(sl);
}

static void	sl_init_imgs(t_game *sl)
{
	sl->img.img = mlx_new_image(sl->mlx.mlx, sl->mlx.width, sl->mlx.height);
	if (!sl->img.img)
		sl_error("Mlx error creating sl->img.img", sl);
	sl->img.addr = mlx_get_data_addr(sl->img.img, &sl->img.bpp,
			&sl->img.line_size, &sl->img.endian);
	sl->img_moves.width = IMG_MOVE_WIDTH;
	sl->img_moves.height = IMG_MOVE_HEIGHT;
	sl->img_moves.img = mlx_new_image(sl->mlx.mlx, sl->img_moves.width,
			sl->img_moves.height);
	if (!sl->img_moves.img)
		sl_error("Mlx error creating sl->img_moves.img", sl);
	sl->img_moves.addr = mlx_get_data_addr(sl->img_moves.img,
			&sl->img_moves.bpp, &sl->img_moves.line_size,
			&sl->img_moves.endian);
	put_background_colors(&sl->img_moves, 0xDEDDA2, 2, 0x3B1D2D);
}

static void	sl_mlx_init(t_game *sl)
{
	sl->mlx.mlx = mlx_init();
	if (sl->mlx.mlx == NULL)
		sl_error("Mlx init error", sl);
	sl->mlx.width = sl->map.line_size * TILE_SIZE;
	sl->mlx.height = sl->map.total_lines * TILE_SIZE;
	sl->mlx.win = mlx_new_window(sl->mlx.mlx, sl->mlx.width, sl->mlx.height,
			"So_long - Help the jawa get some cool stuffs to sell");
	if (sl->mlx.win == NULL)
		sl_error("Mlx window error", sl);
}

void	sl_game_init(t_game *sl)
{
	sl->moves = 0;
	sl->collected_items = 0;
	sl_mlx_init(sl);
	sl_init_imgs(sl);
	sl_load_sprites(sl);
	sl_set_collectibles(sl);
	if (sl->map.total_p > 1)
		sl_set_enemies(sl);
	sl_render_game(sl);
}
