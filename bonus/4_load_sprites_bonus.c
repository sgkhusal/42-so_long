/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_load_sprites_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 03:08:49 by coder             #+#    #+#             */
/*   Updated: 2022/02/19 02:10:08 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static void	sl_load_sprites_enemy(t_game *sl, t_frames_enemy *ef, int e)
{	
	load_sprite(sl, &ef->walk_right.img0, "assets/images/walk_right01.xpm", e);
	load_sprite(sl, &ef->walk_right.img1, "assets/images/walk_right02.xpm", e);
	load_sprite(sl, &ef->walk_right.img2, "assets/images/walk_right03.xpm", e);
	load_sprite(sl, &ef->walk_right.img3, "assets/images/walk_right04.xpm", e);
  	load_sprite(sl, &ef->walk_right.img4, "assets/images/walk_right05.xpm", e);
	load_sprite(sl, &ef->walk_right.img5, "assets/images/walk_right06.xpm", e);
	load_sprite(sl, &ef->walk_right.img6, "assets/images/walk_right07.xpm", e);
	load_sprite(sl, &ef->walk_right.img7, "assets/images/walk_right08.xpm", e);
	/* load_sprite(sl, &ef->walk_left.img0, "assets/images/walk_left01.xpm", e);
	load_sprite(sl, &ef->walk_left.img1, "assets/images/walk_left02.xpm", e);
	load_sprite(sl, &ef->walk_left.img2, "assets/images/walk_left03.xpm", e);
	load_sprite(sl, &ef->walk_left.img3, "assets/images/walk_left04.xpm", e);
	load_sprite(sl, &ef->walk_left.img4, "assets/images/walk_left05.xpm", e);
	load_sprite(sl, &ef->walk_left.img5, "assets/images/walk_left06.xpm", e);
	load_sprite(sl, &ef->walk_left.img6, "assets/images/walk_left07.xpm", e);
	load_sprite(sl, &ef->walk_left.img7, "assets/images/walk_left08.xpm", e); */
}

static void	sl_load_sprites_player(t_game *sl, t_frames_player *pf, int p)
{	
	load_sprite(sl, &pf->idle_front.img0, "assets/images/player_front0.xpm", p);
	load_sprite(sl, &pf->idle_front.img1, "assets/images/player_front1.xpm", p);
	load_sprite(sl, &pf->idle_front.img2, "assets/images/player_front2.xpm", p);
	load_sprite(sl, &pf->idle_front.img3, "assets/images/player_front1.xpm", p);
  	load_sprite(sl, &pf->idle_back.img0, "assets/images/player_back0.xpm", p);
	load_sprite(sl, &pf->idle_back.img1, "assets/images/player_back1.xpm", p);
	load_sprite(sl, &pf->idle_back.img2, "assets/images/player_back2.xpm", p);
	load_sprite(sl, &pf->idle_back.img3, "assets/images/player_back1.xpm", p);
	load_sprite(sl, &pf->idle_right.img0, "assets/images/player_right0.xpm", p);
	load_sprite(sl, &pf->idle_right.img1, "assets/images/player_right1.xpm", p);
	load_sprite(sl, &pf->idle_right.img2, "assets/images/player_right2.xpm", p);
	load_sprite(sl, &pf->idle_right.img3, "assets/images/player_right1.xpm", p);
	load_sprite(sl, &pf->idle_left.img0, "assets/images/player_left0.xpm", p);
	load_sprite(sl, &pf->idle_left.img1, "assets/images/player_left1.xpm", p);
	load_sprite(sl, &pf->idle_left.img2, "assets/images/player_left2.xpm", p);
	load_sprite(sl, &pf->idle_left.img3, "assets/images/player_left1.xpm", p);
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
	sl_load_sprites_enemy(sl, &sl->sprites.enemy, TILE);
}
