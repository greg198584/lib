/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_fc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 18:06:33 by glafitte          #+#    #+#             */
/*   Updated: 2015/04/27 18:31:30 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_count_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (-1);
	while (tab[i] != NULL)
		i++;
	return (i);
}

int	ft_print_tab(char **tab)
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
