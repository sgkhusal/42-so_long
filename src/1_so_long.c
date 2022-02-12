/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_so_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:01:16 by coder             #+#    #+#             */
/*   Updated: 2022/02/12 01:52:48 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	sl_mlx_init(t_game *sl)
{
	sl->mlx.mlx = mlx_init();
	if (sl->mlx.mlx == NULL)
		sl_error("Mlx init error", sl);
	sl->mlx.width = sl->map.line_size * TILE_SIZE;
	sl->mlx.height = sl->map.total_lines * TILE_SIZE;
	sl->mlx.win = mlx_new_window(sl->mlx.mlx, sl->mlx.width, sl->mlx.height,
			"So_long");
	if (sl->mlx.win == NULL)
		sl_error("Mlx window error", sl);
}

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
	sl_mlx_init(&so_long);
	sl_render_map(&so_long);
	mlx_loop(so_long.mlx.mlx);
	clean_map(&so_long);
	clean_mlx(&so_long);
	return (0);
}
