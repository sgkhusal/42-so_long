/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_ft_printf_itohex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:53:38 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/21 22:43:15 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	itohex_conversion(int n)
{
	if (n < 10)
		return (n + '0');
	else
		return ((n - 10) + 'a');
}

static void	printf_strtranslate(char *s, int idcopy)
{
	int	i;

	i = 0;
	while (s[idcopy])
	{
		s[i] = s[idcopy];
		i++;
		idcopy++;
	}
	s[i] = s[idcopy];
}

char	*printf_itohex(unsigned long int n)
{
	char	*hexnb;
	int		size;

	size = 16;
	hexnb = (char *)malloc((size + 1) * sizeof(char));
	if (!(hexnb))
		return (NULL);
	else
	{
		hexnb[size] = '\0';
		while (--size >= 0 && n >= 16)
		{
			hexnb[size] = itohex_conversion(n % 16);
			n = n / 16;
		}
		hexnb[size] = itohex_conversion(n % 16);
		if (size > 0)
			printf_strtranslate(hexnb, size);
		return (hexnb);
	}
}
