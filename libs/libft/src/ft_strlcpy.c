/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 22:00:24 by sguilher          #+#    #+#             */
/*   Updated: 2021/03/05 03:22:36 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t cpysize)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	if (!dst || !src)
		return (0);
	src_size = ft_strlen(src);
	if (cpysize <= 0 || !dst)
		return (ft_strlen(src));
	while (i < cpysize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_size);
}
