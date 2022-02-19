/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:51:39 by coder             #+#    #+#             */
/*   Updated: 2022/02/17 18:31:04 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

# include "libs.h"

# define VALID_CHAR	"01CEP"
# define WALL '1'
# define EMPTY '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define ENEMY 'I'
# define OPEN_ERROR -1
# define GNL_ERROR -1
# define GNL_EOF 0
# define GNL_READ_LINE 1

typedef struct s_map
{
	char	*linear_map;
	char	**map;
	int		total_c;
	int		total_e;
	int		total_p;
	int		total_lines;
	size_t	line_size;
}				t_map;

#endif
