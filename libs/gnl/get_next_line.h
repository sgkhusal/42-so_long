/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:57:23 by sguilher          #+#    #+#             */
/*   Updated: 2022/02/05 03:23:52 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/src/libft.h"
# include <limits.h>

# define READ_OK 1
# define MALLOC_ERROR -1
# define MALLOC_ERROR2 -2
# define INPUT_ERROR -1
# define NO_LINE_FEED -1

# define OPEN_MAX 256

int		get_next_line(int fd, char **line);
void	gnl_strjoin(char **next, char *buffer);
void	ft_clean(char **str);

#endif
