/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_read_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 03:13:33 by coder             #+#    #+#             */
/*   Updated: 2022/02/11 19:04:30 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	sl_check_gnl_error(int gnl, t_game *sl)
{
	if (gnl == GNL_ERROR)
		sl_error("Map read error.", sl);
}

void	sl_read_map(char *path, t_game *sl)
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
