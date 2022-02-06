/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_check_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 02:37:25 by coder             #+#    #+#             */
/*   Updated: 2022/02/06 04:25:28 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	sl_check_map_wall_char(char c)
{
	if (c != WALL)
		sl_error("The map is not totally surrounded by '1' (walls).");
}

static void	sl_check_map_invalid_char(char c, t_game *sl)
{
	if (c == COLLECTIBLE)
		sl->map.total_c++;
	else if (c == EXIT)
		sl->map.total_e++;
	else if (c == PLAYER)
		sl->map.total_p++;
	else if (c != SPACE && c != WALL)
		sl_error("Invalid character in map file.");
}

static void	sl_check_map_line(char *line, t_game *sl, int index)
{
	int	j;

	if (ft_strlen(line) != sl->map.line_size)
		sl_error("The map must be rectangular.");
	j = 0;
	while (line[j])
	{
		if (j == 0)
			sl_check_map_wall_char(line[0]);
		else if (index == 0 || index == sl->map.total_lines - 1)
			sl_check_map_wall_char(line[j]);
		else
			sl_check_map_invalid_char(line[j], sl);
		j++;
	}
	sl_check_map_wall_char(line[j - 1]);
}

static void	sl_check_map_cep_char(t_game *sl)
{
	if (sl->map.total_c == 0)
		sl_error("Map must contain at least one collectible.");
	if (sl->map.total_e == 0)
		sl_error("Map must contain at least one exit.");
	if (sl->map.total_p == 0)
		sl_error("Map must contain at least one starting position.");
}

void	sl_check_map(t_game *sl)
{
	int	i;

	if (sl->map.total_lines < 3)
		sl_error("Map to small. The map doesn't have enough lines.");
	if (sl->map.line_size < 3)
		sl_error("Map to small. The map doesn't have enough columns.");
	i = 0;
	while (sl->map.map[i])
	{
		sl_check_map_line(sl->map.map[i], sl, i);
		i++;
	}
	sl_check_map_cep_char(sl);
}
