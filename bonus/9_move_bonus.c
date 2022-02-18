/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_move_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:42:55 by coder             #+#    #+#             */
/*   Updated: 2022/02/18 15:58:10 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	sl_move_right(t_game *sl)
{
	int	i;
	int	j;

	if (sl->player.status != RIGHT)
	{
		sl->player.status = RIGHT;
		update_player_sprite(sl);
	}
	else
	{
		i = (sl->player.y - SMALL_IMG_OFFSET) / TILE_SIZE;
		j = (sl->player.x - SMALL_IMG_OFFSET) / TILE_SIZE + 1;
		if (sl->map.map[i][j] == EXIT && sl->collected_items == sl->map.total_c)
			sl_move_exit(sl);
		else if (sl->map.map[i][j] != WALL && sl->map.map[i][j] != EXIT)
		{
			put_floor_player(sl);
			sl->player.id_floor++;
			sl->player.x += 32;
			check_collectible(sl, i, j);
			sl_put_player(sl, &sl->sprites.player, sl->sprites.player.frame);
			print_move(sl);
		}
	}
}

void	sl_move_left(t_game *sl)
{
	int	i;
	int	j;

	if (sl->player.status != LEFT)
	{
		sl->player.status = LEFT;
		update_player_sprite(sl);
	}
	else
	{
		i = (sl->player.y - SMALL_IMG_OFFSET) / TILE_SIZE;
		j = (sl->player.x - SMALL_IMG_OFFSET) / TILE_SIZE - 1;
		if (sl->map.map[i][j] == EXIT && sl->collected_items == sl->map.total_c)
			sl_move_exit(sl);
		else if (sl->map.map[i][j] != WALL && sl->map.map[i][j] != EXIT)
		{
			put_floor_player(sl);
			sl->player.id_floor++;
			sl->player.x -= 32;
			check_collectible(sl, i, j);
			sl_put_player(sl, &sl->sprites.player, sl->sprites.player.frame);
			print_move(sl);
		}
	}
}

void	sl_move_up(t_game *sl)
{
	int	i;
	int	j;

	if (sl->player.status != BACK)
	{
		sl->player.status = BACK;
		update_player_sprite(sl);
	}
	else
	{
		i = (sl->player.y - SMALL_IMG_OFFSET) / TILE_SIZE - 1;
		j = (sl->player.x - SMALL_IMG_OFFSET) / TILE_SIZE;
		if (sl->map.map[i][j] == EXIT && sl->collected_items == sl->map.total_c)
			sl_move_exit(sl);
		else if (sl->map.map[i][j] != WALL && sl->map.map[i][j] != EXIT)
		{
			put_floor_player(sl);
			sl->player.id_floor++;
			sl->player.y -= 32;
			check_collectible(sl, i, j);
			sl_put_player(sl, &sl->sprites.player, sl->sprites.player.frame);
			print_move(sl);
		}
	}
}

void	sl_move_down(t_game *sl)
{
	int	i;
	int	j;

	if (sl->player.status != FRONT)
	{
		sl->player.status = FRONT;
		update_player_sprite(sl);
	}
	else
	{
		i = (sl->player.y - SMALL_IMG_OFFSET) / TILE_SIZE + 1;
		j = (sl->player.x - SMALL_IMG_OFFSET) / TILE_SIZE;
		if (sl->map.map[i][j] == EXIT && sl->collected_items == sl->map.total_c)
			sl_move_exit(sl);
		else if (sl->map.map[i][j] != WALL && sl->map.map[i][j] != EXIT)
		{
			put_floor_player(sl);
			sl->player.id_floor++;
			sl->player.y += 32;
			check_collectible(sl, i, j);
			sl_put_player(sl, &sl->sprites.player, sl->sprites.player.frame);
			print_move(sl);
		}
	}
}
