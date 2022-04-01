/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_move_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:02:57 by coder             #+#    #+#             */
/*   Updated: 2022/04/01 20:13:21 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	print_move(t_game *sl)
{
	char	*text;
	char	*moves;

	moves = ft_itoa(sl->moves);
	text = ft_strjoin("Moves: ", moves);
	mlx_string_put(sl->mlx.mlx, sl->mlx.win, MOVE_X, MOVE_Y, 0x3B1D2D, text);
	free(text);
	free(moves);
}

void	sl_move_exit(t_game *sl)
{
	//print_move(sl);
	ft_printf("\nYOU WON!!!!!!! CONGRATULATIONS =)\n\n");
	close_game(sl);
}

void	check_collectible(t_game *sl, int i, int j)
{
	if (sl->map.map[i][j] == COLLECTIBLE)
	{
		put_floor_player(sl);
		sl->collected_items++;
		sl->map.map[i][j] = EMPTY;
	}
}

void	put_floor_again(t_game *sl, int x, int y, int id_floor)
{
	if (id_floor == 0)
		put_sprite_in_game_img(sl, &sl->tiles.floor0, x, y);
	else
		put_sprite_in_game_img(sl, &sl->tiles.floor1, x, y);
}

void	put_floor_player(t_game *sl)
{
	put_floor_again(sl, sl->player.x - IMG_OFFSET,
		sl->player.y - IMG_OFFSET, sl->player.id_floor % 2);
}
