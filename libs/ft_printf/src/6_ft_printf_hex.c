/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_ft_printf_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 23:09:26 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/21 23:55:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	printf_hash(t_print *p, t_flags *f, char c)
{
	if ((*f).hashtag == YES && c != '0')
	{
		if ((*f).specifier == LOWX)
			printf_putstr_fd(p, "0x", 2, NO);
		else if ((*f).specifier == UPPX)
			printf_putstr_fd(p, "0X", 2, NO);
	}
}

static void	printf_hex(t_print *p, t_flags *f, char *hex, int size)
{
	if ((*f).point == YES && (*f).precision > size)
		printf_pad(p, (*f).precision, size, '0');
	if (hex[0] == '0')
		printf_zero(p, f);
	else
	{
		if ((*f).specifier == UPPX)
			ft_toupper_str(hex);
		printf_putstr_fd(p, hex, ft_strlen(hex), NO);
	}
}

static int	printf_print_xsize(t_flags *f, int size, char c)
{
	if ((*f).point == YES && (*f).precision == 0 && c == '0')
		return (0);
	if ((*f).precision > size)
	{
		if ((*f).hashtag == YES && c != '0')
			return ((*f).precision + 2);
		else
			return ((*f).precision);
	}
	else
	{
		if ((*f).hashtag == YES && c != '0')
			return (size + 2);
		else
			return (size);
	}
}

static void	printf_rjust_x(t_print *p, t_flags *f, char *hex, int size)
{
	int		aux;

	aux = printf_print_xsize(f, size, hex[0]);
	if ((*f).zero == YES && (*f).point == NO)
	{
		printf_hash(p, f, hex[0]);
		printf_pad(p, (*f).width, aux, '0');
	}
	else
		printf_pad(p, (*f).width, aux, ' ');
	if ((*f).zero == NO || ((*f).zero == YES && (*f).point == YES))
		printf_hash(p, f, hex[0]);
	printf_hex(p, f, hex, size);
}

void	printf_x(t_print *p, t_flags *f, unsigned int n)
{
	char	*hex;
	int		size;
	int		aux;

	hex = printf_itohex(n);
	if (hex)
	{
		size = ft_strlen(hex);
		if ((*f).minus == YES)
		{
			aux = printf_print_xsize(f, size, hex[0]);
			printf_hash(p, f, hex[0]);
			printf_hex(p, f, hex, size);
			printf_pad(p, (*f).width, aux, ' ');
		}
		else
			printf_rjust_x(p, f, hex, size);
		free(hex);
	}
}
