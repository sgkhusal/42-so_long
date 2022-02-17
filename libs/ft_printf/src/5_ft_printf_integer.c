/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ft_printf_integer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 23:09:30 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/21 23:54:14 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	printf_nbsign(t_flags *f, long int *n)
{
	if ((*f).specifier == 'i' || (*f).specifier == 'd')
	{
		if (*n < 0)
		{
			*n *= -1;
			return ('-');
		}
		else if ((*f).plus == YES)
			return ('+');
		else if ((*f).space == YES)
			return (' ');
		else
			return (0);
	}
	else
		return (0);
}

static void	printf_number(t_print *p, t_flags *f, unsigned int n, int size)
{
	char	*nchar;

	if ((*f).point == YES && (*f).precision > size)
		printf_pad(p, (*f).precision, size, '0');
	if (n == 0)
		printf_zero(p, f);
	else
	{
		nchar = printf_itoa(n);
		printf_putstr_fd(p, nchar, ft_strlen(nchar), NO);
		free(nchar);
	}
}

static int	printf_print_isize(t_flags *f, int size, long int n, char sign)
{
	if ((*f).point == YES && (*f).precision == 0 && n == 0)
	{
		if (sign)
			return (1);
		else
			return (0);
	}
	if (sign)
	{
		if ((*f).precision > size)
			return ((*f).precision + 1);
		else
			return (size + 1);
	}
	else
	{
		if ((*f).precision > size)
			return ((*f).precision);
		else
			return (size);
	}
}

static void	printf_rjust_idu(t_print *p, t_flags *f, long int n, char sign)
{
	int	size;
	int	aux;

	size = printf_nbsize(n);
	aux = printf_print_isize(f, size, n, sign);
	if ((*f).zero == YES && (*f).point == NO)
	{
		printf_putcharnb_fd(p, sign);
		printf_pad(p, (*f).width, aux, '0');
	}
	else
		printf_pad(p, (*f).width, aux, ' ');
	if ((*f).zero == NO || ((*f).zero == YES && (*f).point == YES))
		printf_putcharnb_fd(p, sign);
	printf_number(p, f, n, size);
}

void	printf_idu(t_print *p, t_flags *f, long int n)
{
	char	sign;
	int		size;
	int		aux;

	sign = printf_nbsign(f, &n);
	if ((*f).minus == YES)
	{
		size = printf_nbsize(n);
		aux = printf_print_isize(f, size, n, sign);
		printf_putcharnb_fd(p, sign);
		printf_number(p, f, n, size);
		printf_pad(p, (*f).width, aux, ' ');
	}
	else
		printf_rjust_idu(p, f, n, sign);
}
