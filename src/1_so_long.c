/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_so_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:01:16 by coder             #+#    #+#             */
/*   Updated: 2022/02/05 19:32:38 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	sl_error(char *msg)//, t_game *sl)
{
	printf("Error\n%s\n", msg);
	//sl_clean(sl);
	exit(EXIT_FAILURE);
}

void	sl_check_input(int argc, char *path)
{
	int	fd;
	
	if(argc == 1)
		sl_error("Missing map file (*.ber format).");
	if(argc > 2)
		sl_error("To many arguments.");
	if(ft_strncmp(&path[ft_strlen(path) - 4], ".ber", 4))
		sl_error("Invalid map format. So_long game only supports .ber format.");
	fd = open(path, O_RDONLY);
	if (fd == OPEN_ERROR)
	{
		close(fd);
		sl_error("File path or name nonexist.");
	}	
}

void	sl_check_gnl_error(int gnl)
{
	if(gnl == GNL_ERROR)
			sl_error("Map read error.");
}

void	sl_check_map_wall_char(char c)
{
	if(c != '1')
		sl_error("The map is not totally surrounded by walls.");
}

void	sl_check_map_limits(char *line, t_game *sl, int gnl)
{
	int		i;
	
	if(sl->map.total_lines == 1 || gnl == GNL_EOF)
	{
		i = 0;
		while (line[i])
		{
			sl_check_map_wall_char(line[i]);
			i++;
		}
	}
	else
	{
		sl_check_map_wall_char(line[0]);
		sl_check_map_wall_char(line[ft_strlen(line) - 2]);
	}	
}

void	sl_check_map_line(char *line, t_game *sl, int gnl)
{
	if(sl->map.total_lines == 1 && ft_strlen(line) < 3)
		sl_error("The map doesn't have enough columns.");
	/* if(sl->map.total_lines == 1)
		sl->map.line_size = ft_strlen(line);
	else if(sl->map.total_lines > 1 && size != sl->map.line_size)
		sl_error("The map must be rectangular."); */
	sl_check_map_limits(line, sl, gnl);
	/*if(sl->map.total_lines > 1)
		sl_check_map_char(); */
}

void	sl_read_map(char *path, t_game *sl)
{
	int		gnl;
	int		fd;
	char	*aux;

	fd = open(path, O_RDONLY);
	sl->map.total_lines = 0;
	gnl = GNL_READ_LINE;
	while(gnl == GNL_READ_LINE)
	{
		gnl = get_next_line(fd, &aux);
		sl_check_gnl_error(gnl);
		if(gnl == GNL_READ_LINE || gnl == GNL_EOF)
		{
			sl->map.total_lines++;
			sl_check_map_line(aux, sl, gnl);
			if(sl->map.linear_map == NULL)
				sl->map.linear_map = ft_strdup(aux);
			else
				gnl_strjoin(&(sl->map.linear_map), aux);
			//precisa verificar se retorna null!!
			//free em aux?
		}
	}
	printf("total lines = %i\n", sl->map.total_lines);
	printf("linear map = %s\n", sl->map.linear_map);
	if(sl->map.total_lines < 3)
		sl_error("The map doesn't have enough lines.");
	close(fd);
}

int	main(int argc, char **argv)
{
	t_game	so_long;
	
	sl_check_input(argc, argv[1]);
	so_long.map.linear_map = NULL;
	sl_read_map(argv[1], &so_long);
	return (0);
}
