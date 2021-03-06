/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 14:59:32 by glafitte          #+#    #+#             */
/*   Updated: 2015/05/08 11:37:34 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_freetab(char ***tab)
{
	char	**s;
	int		i;

	if (tab == NULL)
		return ;
	i = 0;
	s = *tab;
	while (s[i] != NULL)
		ft_memdel((void **)&s[i++]);
	ft_memdel((void **)&s);
}
