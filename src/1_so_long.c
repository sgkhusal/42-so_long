/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_so_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:01:16 by coder             #+#    #+#             */
/*   Updated: 2022/02/06 04:08:55 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	sl_error(char *msg)//, t_game *sl)
{
	printf("Error\n%s\n", msg);
	//sl_clean(sl);
	exit(EXIT_FAILURE);
}

static void	sl_map_init(t_game *sl){
	sl->map.total_lines = 0;
	sl->map.linear_map = ft_strdup("");
	if(sl->map.linear_map == NULL)
		sl_error("Memory allocation error");
	sl->map.total_c = 0;
	sl->map.total_e = 0;
	sl->map.total_p = 0;
}

static void	sl_check_input(int argc, char *path)
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
		sl_error("Wrong file path/name or file nonexist.");
	}	
}

int	main(int argc, char **argv)
{
	t_game	so_long;
	
	sl_check_input(argc, argv[1]);
	sl_map_init(&so_long);
	sl_read_map(argv[1], &so_long);
	so_long.map.map = ft_split(so_long.map.linear_map, '\n');
	if(so_long.map.map == NULL)
		sl_error("Map split error");
	sl_check_map(&so_long);
	return (0);
}
