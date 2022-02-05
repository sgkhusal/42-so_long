/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_so_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:01:16 by coder             #+#    #+#             */
/*   Updated: 2022/02/05 05:52:23 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_error(char *msg)//, t_game *sl)
{
	printf("Error\n%s\n", msg);
	//sl_clean(sl);
	exit(EXIT_FAILURE);
}

void	sl_check_input(int argc, char *path)
{
	if(argc == 1)
		sl_error("Missing map file (*.ber format).");
	if(argc > 2)
		sl_error("To many arguments.");
	if(ft_strncmp(&path[ft_strlen(path) - 4], ".ber", 4))
		sl_error("Invalid map format - only supported .ber format.");
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
		sl_check_map_wall_char(line[ft_strlen(line) - 1]);
	}
	if(sl->map.total_lines == 1)
		sl->map.line_size = ft_strlen(line);	
}

void	sl_check_map_line(char *line, t_game *sl, int gnl)
{
	size_t	size;
	
	size = ft_strlen(line);
	if(sl->map.total_lines == 1 && size < 3)
		sl_error("The map doesn't have enough columns.");
	if(sl->map.total_lines > 1 && size != sl->map.line_size)
		sl_error("The map must be rectangular.");
	sl_check_map_limits(line, sl, gnl);
	/*if(sl->map.total_lines > 1 || gnl == GNL_READ_LINE)
		sl_check_map_char(); */
}

void	sl_read_map(char *path, t_game *sl)
{
	int		gnl;
	int		fd;
	t_list	new_line;

	fd = open(path, O_RDONLY);
	if (fd == OPEN_ERROR) // pode tirar porque o gnl verifica, mas a mensagem de erro não fica personalizada
		sl_error("File path/name nonexist or file open error.");
	sl->map.total_lines = 0;
	printf("%p\n", sl);
	printf("%p\n", sl->map.line_list);
	sl->map.line_list->content = (char	*)malloc(5 * sizeof(char));
	sl->map.line_list->content = "test";
	printf("%s\n", (char *)sl->map.line_list->content);
	
	gnl = GNL_READ_LINE;
	while(gnl == GNL_READ_LINE)
	{
		gnl = get_next_line(fd, (char **)&(new_line.content));
		sl_check_gnl_error(gnl);
		if(gnl == GNL_READ_LINE || gnl == GNL_EOF)
		{
			sl->map.total_lines++;
			sl_check_map_line(new_line.content, sl, gnl);
			//ft_lstadd_back(sl->map.line_list, &new_line);
			//free em new_line.content?
		}
	}
	if(sl->map.total_lines < 3)
		sl_error("The map doesn't have enough lines.");
	close(fd);
}

int	main(int argc, char **argv)
{
	t_game	so_long;
	
	sl_check_input(argc, argv[1]);
	sl_read_map(argv[1], &so_long);
	return (0);
}
