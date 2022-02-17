/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:06:18 by sguilher          #+#    #+#             */
/*   Updated: 2022/02/16 15:45:12 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*newstr;

	if (!s || !f)
		return (NULL);
	newstr = ft_strdup(s);
	if (!newstr)
		return (NULL);
	i = 0;
	while (newstr[i])
	{
		newstr[i] = f(i, newstr[i]);
		i++;
	}
	return (newstr);
}
