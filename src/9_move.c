/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:42:55 by coder             #+#    #+#             */
/*   Updated: 2022/02/17 18:39:19 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	print_move(t_game *sl)
{
	sl->moves++;
	ft_printf("Moves: %i\n", sl->moves);
}

void	put_floor_again(t_game *sl, int x, int y, int id_floor)
{
	if (id_floor == 0)
		put_sprite_in_game_img(sl, &sl->sprites.floor0, x, y);
	else
		put_sprite_in_game_img(sl, &sl->sprites.floor1, x, y);
}

void	put_floor_player(t_game *sl)
{
	put_floor_again(sl, sl->player.x - SMALL_IMG_OFFSET,
		sl->player.y - SMALL_IMG_OFFSET, sl->player.id_floor % 2);
}

void	sl_move_exit(t_game *sl)
{
	print_move(sl);
	ft_printf("YOU WON!!\n");
	close_game(sl);
}

void	check_collectible(t_game *sl, int i, int j)
{
	if (sl->map.map[i][j] == COLLECTIBLE)
	{
		put_floor_player(sl);
		sl->collect_items++;
		sl->map.map[i][j] = EMPTY;
	}
}

void	sl_move_right(t_game *sl)
{
	int	i;
	int	j;

	if (sl->player.status != RIGHT)
	{
		put_floor_player(sl);
		put_player(sl, &sl->sprites.right0);
		sl->player.status = RIGHT;
	}
	else
	{ 
		i = (sl->player.y - SMALL_IMG_OFFSET) / TILE_SIZE;
		j = (sl->player.x - SMALL_IMG_OFFSET) / TILE_SIZE + 1;
		if (sl->map.map[i][j] == EXIT && sl->collect_items == sl->map.total_c)
			sl_move_exit(sl);
		else if (sl->map.map[i][j] != WALL && sl->map.map[i][j] != EXIT)
		{
			put_floor_player(sl);
			sl->player.id_floor++;
			sl->player.x += 32;
			check_collectible(sl, i, j);
			put_player(sl, &sl->sprites.right0);
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
		put_floor_player(sl);
		put_player(sl, &sl->sprites.left0);
		sl->player.status = LEFT;
	}
	else
	{ 
		i = (sl->player.y - SMALL_IMG_OFFSET) / TILE_SIZE;
		j = (sl->player.x - SMALL_IMG_OFFSET) / TILE_SIZE - 1;
		if (sl->map.map[i][j] == EXIT && sl->collect_items == sl->map.total_c)
			sl_move_exit(sl);
		else if (sl->map.map[i][j] != WALL && sl->map.map[i][j] != EXIT)
		{
			put_floor_player(sl);
			sl->player.id_floor++;
			sl->player.x -= 32; ///
			check_collectible(sl, i, j);
			put_player(sl, &sl->sprites.left0);
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
		put_floor_player(sl);
		put_player(sl, &sl->sprites.back0);
		sl->player.status = BACK;
	}
	else
	{ 
		i = (sl->player.y - SMALL_IMG_OFFSET) / TILE_SIZE - 1;
		j = (sl->player.x - SMALL_IMG_OFFSET) / TILE_SIZE;
		if (sl->map.map[i][j] == EXIT && sl->collect_items == sl->map.total_c)
			sl_move_exit(sl);
		else if (sl->map.map[i][j] != WALL && sl->map.map[i][j] != EXIT)
		{
			put_floor_player(sl);
			sl->player.id_floor++;
			sl->player.y -= 32;
			check_collectible(sl, i, j);
			put_player(sl, &sl->sprites.back0);
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
		put_floor_player(sl);
		put_player(sl, &sl->sprites.front0);
		sl->player.status = FRONT;
	}
	else
	{ 
		i = (sl->player.y - SMALL_IMG_OFFSET) / TILE_SIZE + 1;
		j = (sl->player.x - SMALL_IMG_OFFSET) / TILE_SIZE;
		if (sl->map.map[i][j] == EXIT && sl->collect_items == sl->map.total_c)
			sl_move_exit(sl);
		else if (sl->map.map[i][j] != WALL && sl->map.map[i][j] != EXIT)
		{
			put_floor_player(sl);
			sl->player.id_floor++;
			sl->player.y += 32;
			check_collectible(sl, i, j);
			put_player(sl, &sl->sprites.front0);
			print_move(sl);
		}
	}
}
