/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:57:13 by sguilher          #+#    #+#             */
/*   Updated: 2022/02/04 21:27:24 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_strjoin(char **next, char *buffer)
{
	char	*aux;

	aux = ft_strjoin(*next, buffer);
	ft_clean(next);
	*next = aux;
}

void	ft_clean(char **str)
{
	if (str == NULL && !(*str))
		return ;
	if (*str)
		free(*str);
	*str = NULL;
}
