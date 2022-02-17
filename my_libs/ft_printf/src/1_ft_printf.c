/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_ft_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 21:59:48 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/21 23:48:55 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	printf_fd(int fd, const char *str, va_list args)
{
	t_print	p;
	int		j;

	p.len = 0;
	p.sub_len = 0;
	p.i = 0;
	j = 0;
	p.fd = fd;
	while (str[p.i])
	{
		p.sub_len++;
		if (str[p.i] == '%')
		{
			printf_putstr_fd(&p, (char *)&str[j], p.sub_len - 1, NO);
			printf_flags(&p, &str[++p.i], args);
			j = p.i;
			p.sub_len = 0;
		}
		else
			p.i++;
	}
	printf_putstr_fd(&p, (char *)&str[j], p.sub_len, NO);
	return (p.len);
}

int	ft_printf_fd(int fd, const char *str, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, str);
	len = printf_fd(fd, str, ap);
	va_end(ap);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, str);
	len = printf_fd(STDOUT, str, ap);
	va_end(ap);
	return (len);
}
