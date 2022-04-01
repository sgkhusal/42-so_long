/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_so_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:01:16 by coder             #+#    #+#             */
/*   Updated: 2022/04/01 20:11:10 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	sl_input_error(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}

static void	sl_check_input(int argc, char *path)
{
	int	fd;

	if (argc == 1)
		sl_input_error("Missing map file (*.ber format).");
	if (argc > 2)
		sl_input_error("To many arguments.");
	if (ft_strncmp(&path[ft_strlen(path) - 4], ".ber", 4))
		sl_input_error("Invalid map format. Game only supports '.ber' format.");
	fd = open(path, O_RDONLY);
	if (fd == OPEN_ERROR)
	{
		close(fd);
		sl_input_error("Wrong file path/name or file nonexist.");
	}	
}

int	main(int argc, char **argv)
{
	t_game	so_long;

	sl_check_input(argc, argv[1]);
	sl_map(argv[1], &so_long);
	sl_game_init(&so_long);
	sl_mlx_hooks(&so_long);
	mlx_loop(so_long.mlx.mlx);
	return (0);
}
