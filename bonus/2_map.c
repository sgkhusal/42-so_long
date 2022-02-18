/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 03:13:33 by coder             #+#    #+#             */
/*   Updated: 2022/02/18 15:05:41 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static void	sl_check_gnl_error(int gnl, t_game *sl)
{
	if (gnl == GNL_ERROR)
		sl_error("Map read error.", sl);
}

static void	sl_read_map(char *path, t_game *sl)
{
	int		gnl;
	int		fd;
	char	*aux;

	fd = open(path, O_RDONLY);
	gnl = GNL_READ_LINE;
	while (gnl == GNL_READ_LINE)
	{
		gnl = get_next_line(fd, &aux);
		sl_check_gnl_error(gnl, sl);
		if (gnl == GNL_READ_LINE || gnl == GNL_EOF)
		{
			sl->map.total_lines++;
			if (sl->map.total_lines == 1)
				sl->map.line_size = ft_strlen(aux) - 1;
			gnl_strjoin(&(sl->map.linear_map), aux);
			if (sl->map.linear_map == NULL)
				sl_error("Memory allocation error", sl);
		}
		ft_clean(&aux);
	}
	ft_clean(&aux);
	close(fd);
}

static void	sl_map_init(t_game *sl)
{
	sl->map.total_lines = 0;
	sl->map.line_size = 0;
	sl->map.linear_map = ft_strdup("");
	if (sl->map.linear_map == NULL)
		sl_error("Memory allocation error", sl);
	sl->map.map = NULL;
	sl->map.total_c = 0;
	sl->map.total_e = 0;
	sl->map.total_p = 0;
}

void	sl_map(char *path, t_game *sl)
{
	sl_map_init(sl);
	sl_read_map(path, sl);
	sl->map.map = ft_split(sl->map.linear_map, '\n');
	if (sl->map.map == NULL)
		sl_error("Map split error", sl);
	sl_check_map(sl);
}
