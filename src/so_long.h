/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:01:49 by coder             #+#    #+#             */
/*   Updated: 2022/02/04 22:52:49 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "get_next_line.h"
# include <libft.h>

// include do printf
# include <stdio.h>

# define VALID_CHAR	"01CEP"
# define WALL '1'

typedef struct s_map
{
	int		total_c;
	int		total_e;
	int		total_p;
}				t_map;

typedef struct s_game
{
	int		moves;
}				t_game;

/*
so_long functions
*/




#endif