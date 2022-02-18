/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_load_sprites_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 03:08:49 by coder             #+#    #+#             */
/*   Updated: 2022/02/18 21:24:02 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static void	sl_load_sprites_player(t_game *sl, t_frames_player *pf, int p)
{	
	load_sprite(sl, &pf->idle_front[0], "assets/images/player_front0.xpm", p);
	ft_printf("Chegamos aqui\n");
	load_sprite(sl, &pf->idle_front[1], "assets/images/player_front1.xpm", p);
	load_sprite(sl, &pf->idle_front[2], "assets/images/player_front2.xpm", p);
  	load_sprite(sl, &pf->idle_back[0], "assets/images/player_back0.xpm", p);
	load_sprite(sl, &pf->idle_back[1], "assets/images/player_back1.xpm", p);
	load_sprite(sl, &pf->idle_back[2], "assets/images/player_back2.xpm", p);
	load_sprite(sl, &pf->idle_right[0], "assets/images/player_right0.xpm", p);
	load_sprite(sl, &pf->idle_right[1], "assets/images/player_right1.xpm", p);
	load_sprite(sl, &pf->idle_right[2], "assets/images/player_right2.xpm", p);
	load_sprite(sl, &pf->idle_left[0], "assets/images/player_left0.xpm", p);
	load_sprite(sl, &pf->idle_left[1], "assets/images/player_left1.xpm", p);
	load_sprite(sl, &pf->idle_left[2], "assets/images/player_left2.xpm", p);
}

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
	sl_load_sprites_player(sl, &sl->sprites.player, PLAYER_IMG);
}
