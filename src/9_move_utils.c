/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_move_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:02:57 by coder             #+#    #+#             */
/*   Updated: 2022/02/17 22:03:35 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	print_move(t_game *sl)
{
	sl->moves++;
	ft_printf("Moves: %i\n", sl->moves);
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
