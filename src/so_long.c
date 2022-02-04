/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:01:16 by coder             #+#    #+#             */
/*   Updated: 2022/02/04 22:56:54 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	so_long_check_input()
	so_long_check_map();
	
}

int		so_long_check_input(int argc, char *map_file)
{
	if(argc == 1)
		so_long_error("Missing map file (*.ber)");
	if(argc > 2)
		so_long_error("To many arguments.");
	if(ma)
	
}

int	so_long_error(*msg)
{
	printf("Error\n%s\n", msg);
	exit(0);
}