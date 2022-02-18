/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_game_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:37:23 by coder             #+#    #+#             */
/*   Updated: 2022/02/18 21:18:33 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	sl_render_game(t_game *sl)
{
	int	i;
	int	j;
	int	id_floor;

	i = 0;
	id_floor = 0;
	while (i < sl->map.total_lines)
	{
		j = 0;
		while (j < (int)sl->map.line_size)
		{
			sl_put_static_map(sl, i, j, id_floor);
			j++;
			id_floor++;
		}
		i++;
		if ((int)sl->map.line_size % 2 == 0)
			id_floor++;
	}		
	sl_put_collectibles(sl);
	//sl_put_player(sl, &sl->player.sprites);
	//sl_put_enemy(sl);
	mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win, sl->img.img, 0, 0);
}

static void	sl_mlx_init(t_game *sl)
{
	sl->mlx.mlx = mlx_init();
	if (sl->mlx.mlx == NULL)
		sl_error("Mlx init error", sl);
	sl->mlx.width = sl->map.line_size * TILE_SIZE;
	sl->mlx.height = sl->map.total_lines * TILE_SIZE; ////// adicionar tamanho texto
	sl->mlx.win = mlx_new_window(sl->mlx.mlx, sl->mlx.width, sl->mlx.height,
			"So_long"); ////// mudar nome
	if (sl->mlx.win == NULL)
		sl_error("Mlx window error", sl);
}

void	sl_game_init(t_game *sl)
{
	sl->moves = 0;
	sl->collected_items = 0;
	sl->player_set = NOT_SET;
	sl_mlx_init(sl);
	sl->img.img = mlx_new_image(sl->mlx.mlx, sl->mlx.width, sl->mlx.height);
	if (!sl->img.img)
		sl_error("Mlx error creating sl->img.img", sl);
	sl->img.addr = mlx_get_data_addr(sl->img.img, &sl->img.bpp,
			&sl->img.line_size, &sl->img.endian);
	sl_load_sprites(sl);
	sl_set_collectibles(sl);
	sl_render_game(sl);
}
