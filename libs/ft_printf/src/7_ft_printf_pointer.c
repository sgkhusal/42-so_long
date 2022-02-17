/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_ft_printf_pointer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:38:59 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/21 23:56:51 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	printf_pointer(t_print *p, t_flags *f, char *hex, int size)
{
	if ((*f).point == YES && (*f).precision > size)
		printf_pad(p, (*f).precision, size, '0');
	if (hex[0] == '0')
		printf_zero(p, f);
	else
		printf_putstr_fd(p, hex, size, NO);
}

static int	printf_print_psize(t_flags *f, int size, char c)
{
	if ((*f).point == YES && (*f).precision == 0 && c == '0')
		return (2);
	if ((*f).precision > size)
		return ((*f).precision + 2);
	else
		return (size + 2);
}

static void	printf_rjust_x(t_print *p, t_flags *f, char *hex, int size)
{
	int		aux;

	aux = printf_print_psize(f, size, hex[0]);
	if ((*f).zero == YES && (*f).point == NO)
	{
		printf_putstr_fd(p, "0x", 2, NO);
		printf_pad(p, (*f).width, aux, '0');
	}
	else
		printf_pad(p, (*f).width, aux, ' ');
	if ((*f).zero == NO || ((*f).zero == YES && (*f).point == YES))
		printf_putstr_fd(p, "0x", 2, NO);
	printf_pointer(p, f, hex, size);
}

void	printf_p(t_print *p, t_flags *f, unsigned long int n)
{
	char	*hex;
	int		size;
	int		aux;

	hex = printf_itohex(n);
	if (hex)
	{
		size = (int)ft_strlen(hex);
		if ((*f).minus == YES)
		{
			aux = printf_print_psize(f, size, hex[0]);
			printf_putstr_fd(p, "0x", 2, NO);
			printf_pointer(p, f, hex, size);
			printf_pad(p, (*f).width, aux, ' ');
		}
		else
			printf_rjust_x(p, f, hex, size);
		free(hex);
	}
}
