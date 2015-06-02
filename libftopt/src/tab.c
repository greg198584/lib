/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <glafitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 22:33:58 by glafitte          #+#    #+#             */
/*   Updated: 2015/06/02 22:40:44 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftopt.h"
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
	ft_fprintf(1, "array\n(\n");
	while (tab[i] != NULL)
	{
		ft_fprintf(1, "\t[%s]\n", tab[i]);
		i++;
	}
	ft_fprintf(1, ")");
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
