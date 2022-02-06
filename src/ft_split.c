/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 02:55:08 by sguilher          #+#    #+#             */
/*   Updated: 2022/02/06 04:21:33 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static size_t	wcount(char const *s, char c)
{
	int		i;
	size_t	count;

	if (!s || !s[0])
		return (0);
	i = 1;
	count = 0;
	if (s[0] != c && s[0])
		count = 1;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static size_t	lcount(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (s[count] != c && s[count])
		count++;
	return (count);
}

static void	free_pointer(char *p)
{
	free(p);
	p = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	wc;
	size_t	lc;
	size_t	i;
	int		k;
	char	**words;

	if (!s)
		return (NULL);
	wc = wcount(s, c);
	if (!(words = (char **)malloc((wc + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	k = 0;
	while (i < wc)
	{
		while (s[k] == c && s[k])
			k++;
		lc = lcount(&s[k], c);
		if (!(words[i] = ft_substr(&s[k], 0, lc)))
			free_pointer(words[i]);
		k = k + lc;
		i++;
	}
	words[i] = NULL;
	return (words);
}
