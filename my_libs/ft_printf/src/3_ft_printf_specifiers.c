/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_ft_printf_specifiers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 08:01:30 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/21 22:44:03 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	check_specifier(t_flags *f, t_print *p, const char c)
{
	if (ft_strchr(CONVERSIONS, c))
	{
		(*p).i++;
		(*f).specifier = c;
		return (YES);
	}
	else
		return (NO);
}

void	print_specifier(t_print *p, t_flags *f, va_list args)
{
	if ((*f).specifier == 'c')
		printf_c(p, f, (char)va_arg(args, int));
	else if ((*f).specifier == 's')
		printf_s(p, f, va_arg(args, char *));
	else if ((*f).specifier == 'd')
		printf_idu(p, f, va_arg(args, int));
	else if ((*f).specifier == 'i')
		printf_idu(p, f, va_arg(args, int));
	else if ((*f).specifier == 'u')
		printf_idu(p, f, va_arg(args, unsigned int));
	else if ((*f).specifier == 'p')
		printf_p(p, f, va_arg(args, unsigned long int));
	else if (((*f).specifier == LOWX) || ((*f).specifier == UPPX))
		printf_x(p, f, va_arg(args, unsigned int));
}
