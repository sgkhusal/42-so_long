/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ft_printf_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 23:09:22 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/21 23:53:11 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	printf_putchar_fd(t_print *p, char c)
{
	write((*p).fd, &c, 1);
	(*p).len++;
}

void	printf_putcharnb_fd(t_print *p, char c)
{
	if (c)
	{
		write((*p).fd, &c, 1);
		(*p).len++;
	}
}

void	printf_putstr_fd(t_print *p, char *s, int size, int free_null)
{
	if (s)
		(*p).len = (*p).len + write((*p).fd, s, size);
	if (free_null == YES)
		free(s);
}

void	printf_c(t_print *p, t_flags *f, char c)
{
	if ((*f).minus == YES)
		printf_putchar_fd(p, c);
	if ((*f).minus == NO && (*f).zero == YES)
		printf_pad(p, (*f).width, 1, '0');
	else
		printf_pad(p, (*f).width, 1, ' ');
	if ((*f).minus == NO)
		printf_putchar_fd(p, c);
}

void	printf_s(t_print *p, t_flags *f, char *s)
{
	int	size;
	int	free_null;

	free_null = NO;
	if (!s)
	{
		s = ft_strdup("(null)");
		free_null = YES;
	}
	size = (int)ft_strlen(s);
	if ((*f).point == YES && (*f).precision < size)
		size = (*f).precision;
	if ((*f).minus == YES)
	{
		printf_putstr_fd(p, s, size, free_null);
		printf_pad(p, (*f).width, size, ' ');
	}
	else
	{
		if ((*f).zero == YES)
			printf_pad(p, (*f).width, size, '0');
		else
			printf_pad(p, (*f).width, size, ' ');
		printf_putstr_fd(p, s, size, free_null);
	}
}
