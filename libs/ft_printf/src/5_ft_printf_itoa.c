/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ft_printf_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:53:38 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/21 21:17:09 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	printf_nbsize(unsigned int n)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*printf_itoa(unsigned int n)
{
	char	*charnb;
	int		size;

	size = printf_nbsize(n);
	charnb = NULL;
	if (size > 0)
		charnb = (char *)malloc((size + 1) * sizeof(char));
	if (!(charnb))
		return (NULL);
	else
	{
		charnb[size] = '\0';
		while (--size >= 0)
		{
			charnb[size] = (n % 10) + '0';
			n = n / 10;
		}
		return (charnb);
	}
}
