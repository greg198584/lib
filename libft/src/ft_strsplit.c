/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:18:41 by glafitte          #+#    #+#             */
/*   Updated: 2015/04/27 17:13:08 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_count(char const *s, char c)
{
	int		i;
	int		j;
	int		w;

	w = 1;
	i = 0;
	while (*(s + i) != '\0')
	{
		while (*(s + i) == c)
			i++;
		j = i;
		while (*(s + i) != 0 && *(s + i) != c)
			i++;
		if (i != j)
			w++;
	}
	return (w);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		w;

	if (!(tab = (char **)malloc(sizeof(char *) * ft_count(s, c))))
		return (NULL);
	w = 0;
	i = 0;
	while (*(s + i) != '\0')
	{
		while (*(s + i) == c)
			i++;
		j = i;
		while (*(s + i) != 0 && *(s + i) != c)
			i++;
		if (i != j)
			tab[w++] = ft_strndup(s + j, i - j);
	}
	tab[w] = NULL;
	return (tab);
}
