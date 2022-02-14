/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_so_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:01:16 by coder             #+#    #+#             */
/*   Updated: 2022/02/13 00:37:17 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	sl_check_input(int argc, char *path, t_game *sl)
{
	int	fd;

	if (argc == 1)
		sl_error("Missing map file (*.ber format).", sl);
	if (argc > 2)
		sl_error("To many arguments.", sl);
	if (ft_strncmp(&path[ft_strlen(path) - 4], ".ber", 4))
		sl_error("Invalid map format. Game only supports .ber format.", sl);
	fd = open(path, O_RDONLY);
	if (fd == OPEN_ERROR)
	{
		close(fd);
		sl_error("Wrong file path/name or file nonexist.", sl);
	}	
}

int	main(int argc, char **argv)
{
	t_game	so_long;

	sl_check_input(argc, argv[1], &so_long);
	sl_map(argv[1], &so_long);
	int i = 0;
	while (so_long.map.map[i])
	{
		printf("%s\n", so_long.map.map[i]);
		i++;
	}
	sl_game(&so_long);
	mlx_loop(so_long.mlx.mlx);
	clean_map(&so_long);
	clean_items(&so_long);
	clean_mlx(&so_long);
	return (0);
}
