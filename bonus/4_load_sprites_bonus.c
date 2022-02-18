/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_load_sprites_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 03:08:49 by coder             #+#    #+#             */
/*   Updated: 2022/02/18 15:50:34 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

/* static void	sl_load_sprites_frames_malloc(t_game *sl, t_image *frames, int n)
{
	frames = (t_image *)malloc((n) * sizeof(t_image));
	if (!frames)
		sl_error("Malloc error in sl_load_sprites_frames_malloc", sl);
}

static void	sl_load_sprites_player_malloc(t_game *sl, int n)
{
	sl_load_sprites_frames_malloc(sl, sl->player.sprites.idle_front, n);
	sl_load_sprites_frames_malloc(sl, sl->player.sprites.idle_back, n);
	sl_load_sprites_frames_malloc(sl, sl->player.sprites.idle_right, n);
	sl_load_sprites_frames_malloc(sl, sl->player.sprites.idle_left, n); */
	/*sl_load_sprites_frames_malloc(sl, sl->player.sprites.run_front, n);
	sl_load_sprites_frames_malloc(sl, sl->player.sprites.run_back, n);
	sl_load_sprites_frames_malloc(sl, sl->player.sprites.run_right, n);
	sl_load_sprites_frames_malloc(sl, sl->player.sprites.run_left, n);
}

static void	sl_load_sprites_player(t_game *sl, t_player_frames *pf, int ts)
{	
	sl_load_sprites_player_malloc(sl, PLAYER_FRAMES + 1);
	ft_printf("Chegamos aqui\n");
	pf->idle_front[0]->img = mlx_xpm_file_to_image(sl->mlx.mlx,
		"assets/images/player_front0.xpm", &pf->idle_front[0]->line_size,
		&pf->idle_front[0]->height);
	if (!pf->idle_front[0]->img)
		sl_error("Mlx error loading player_front0.xpm", sl);
	pf->idle_front[0]->addr = mlx_get_data_addr(pf->idle_front[0]->img, &pf->idle_front[0]->bpp,
			&pf->idle_front[0]->line_size, &pf->idle_front[0]->endian);
	pf->idle_front[0]->height = TILE_SIZE / 2 + 4;
	pf->idle_front[0]->width = TILE_SIZE / 2;
	load_sprite(sl, &sl->player.sprites.idle_front[0], "assets/images/player_front0.xpm", ts);
	ft_printf("Chegamos aqui\n");
	load_sprite(sl, &pf->idle_front[1], "assets/images/player_front1.xpm", ts);
	load_sprite(sl, &pf->idle_front[2], "assets/images/player_front2.xpm", ts);
	//&pf->idle_front[3] = NULL;
 	load_sprite(sl, pf->idle_back[0], "assets/images/player_back0.xpm", ts);
	load_sprite(sl, pf->idle_back[1], "assets/images/player_back1.xpm", ts);
	load_sprite(sl, pf->idle_back[2], "assets/images/player_back2.xpm", ts);
	pf->idle_back[3] = NULL;
	load_sprite(sl, pf->idle_right[0], "assets/images/player_right0.xpm", ts);
	load_sprite(sl, pf->idle_right[1], "assets/images/player_right1.xpm", ts);
	load_sprite(sl, pf->idle_right[2], "assets/images/player_right2.xpm", ts);
	pf->idle_right[3] = NULL;
	load_sprite(sl, pf->idle_left[0], "assets/images/player_left0.xpm", ts);
	load_sprite(sl, pf->idle_left[1], "assets/images/player_left1.xpm", ts);
	load_sprite(sl, pf->idle_left[2], "assets/images/player_left2.xpm", ts);
	pf->idle_left[3] = NULL;
}
 */


void	sl_load_sprites(t_game *sl)
{
	load_sprite(sl, &sl->tiles.wall, "assets/images/wall.xpm", TILE);
	load_sprite(sl, &sl->tiles.corner, "assets/images/corner.xpm", TILE);
	load_sprite(sl, &sl->tiles.floor0, "assets/images/floor0.xpm", TILE);
	load_sprite(sl, &sl->tiles.floor1, "assets/images/floor1.xpm", TILE);
	load_sprite(sl, &sl->tiles.exit, "assets/images/stair_exit.xpm", TILE);
	load_sprite(sl, &sl->sprites.items.item0, "assets/images/tiger_eye.xpm", ITEM);
	load_sprite(sl, &sl->sprites.items.item1, "assets/images/item1.xpm", ITEM);
	load_sprite(sl, &sl->sprites.items.item2, "assets/images/item2.xpm", ITEM);
	load_sprite(sl, &sl->sprites.items.item3, "assets/images/item3.xpm", ITEM);
	load_sprite(sl, &sl->sprites.items.item4, "assets/images/item4.xpm", ITEM);
	load_sprite(sl, &sl->sprites.items.item5, "assets/images/item5.xpm", ITEM);
	//sl_load_sprites_player(sl, &sl->player.sprites, 3);
}
