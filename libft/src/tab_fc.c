/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_fc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 18:06:33 by glafitte          #+#    #+#             */
/*   Updated: 2015/05/09 10:50:23 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_count_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (-1);
	while (tab[i] != NULL)
		i++;
	return (i);
}

int		ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (-1);
	ft_putendl("array\n(\n");
	while (tab[i] != NULL)
	{
		ft_fprintf(1, "\t[%s]\n", tab[i]);
		i++;
	}
	ft_putendl(")");
	return (0);
}

char	**ft_tabdup(char **src)
{
	char	**arg;
	int		count;
	int		i;

	i = 0;
	count = ft_count_tab(src);
	if ((arg = (char **)ft_memalloc(sizeof(char *) * (count + 1))) == NULL)
		ERR_LOC("Erreur: allocation memoire");
	while (src[i] != NULL)
	{
		arg[i] = ft_strdup(src[i]);
		i++;
	}
	arg[i] = NULL;
	return (arg);
}
