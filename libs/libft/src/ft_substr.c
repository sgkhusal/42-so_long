/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 03:31:09 by sguilher          #+#    #+#             */
/*   Updated: 2022/02/16 15:59:08 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	i;
	size_t			buffer;

	if (!s)
		return (NULL);
	if (ft_strlen((char *)s) < len)
		buffer = ft_strlen((char *)s);
	else
		buffer = len;
	substring = (char *)malloc((buffer + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	i = 0;
	while (i < len && ((start + i) < ft_strlen((char *)s)))
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
