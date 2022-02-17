/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:09:19 by sguilher          #+#    #+#             */
/*   Updated: 2021/03/06 19:12:42 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*element;
	t_list	*tmp;

	if (lst)
	{
		element = *lst;
		while (element->next)
		{
			tmp = element->next;
			ft_lstdelone(element, del);
			element = tmp;
		}
		ft_lstdelone(element, del);
	}
	*lst = NULL;
}
