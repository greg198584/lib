/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splittoken.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <glafitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 14:35:21 by glafitte          #+#    #+#             */
/*   Updated: 2015/05/08 10:36:13 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_isinlist(char c, char const *list)
{
	while (list && *list)
		if (*list++ == c)
			return (1);
	return (0);
}

static int	ft_count(char const *s, char const *tokens)
{
	int		i;
	int		j;
	int		w;

	w = 1;
	i = 0;
	while (*(s + i) != '\0')
	{
		while (ft_isinlist(*(s + i), tokens))
			i++;
		j = i;
		while (*(s + i) != 0 && !ft_isinlist(*(s + i), tokens))
			i++;
		if (i != j)
			w++;
	}
	return (w);
}

char		**ft_splittoken(char const *s, char const *tokens)
{
	char	**tab;
	int		i;
	int		j;
	int		w;

	if (!(tab = (char **)ft_memalloc(sizeof(char *) * ft_count(s, tokens))))
		return (NULL);
	w = 0;
	i = 0;
	while (*(s + i) != '\0' && !(j = 0))
	{
		while (ft_isinlist(*(s + i), tokens))
			i++;
		j = i;
		while (*(s + i) != 0 && !ft_isinlist(*(s + i), tokens))
			i++;
		if (i != j)
			tab[w++] = ft_strndup(s + j, i - j);
	}
	tab[w] = NULL;
	return (tab);
}
