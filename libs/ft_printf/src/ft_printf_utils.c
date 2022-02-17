/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:12:04 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/21 21:42:17 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	printf_pad(t_print *p, int var, int ref, char c)
{
	while (var > ref)
	{
		printf_putchar_fd(p, c);
		var--;
	}
}

void	printf_pad2(t_print *p, t_flags *f, int ref, char c)
{
	while ((*f).precision > ref)
	{
		printf_putchar_fd(p, c);
		(*f).precision--;
		(*f).width--;
	}
}

void	printf_zero(t_print *p, t_flags *f)
{
	if ((*f).point == NO || (*f).precision != 0)
		printf_putchar_fd(p, '0');
}

void	ft_toupper_str(char *s)
{
	while (*s)
	{
		*s = ft_toupper(*s);
		s++;
	}
}

int	ft_printf_atoi(t_print *p, const char *nptr, int *i)
{
	unsigned long long		n;

	n = 0;
	while (ft_isdigit(*nptr))
	{
		n = n * 10 + (*nptr - 48);
		nptr++;
		(*p).i++;
		(*i)++;
	}
	return (n);
}
