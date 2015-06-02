/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <glafitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 22:42:24 by glafitte          #+#    #+#             */
/*   Updated: 2015/06/02 22:45:49 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftopt.h"
#include <stdlib.h>

void	ft_memdel(void **ap)
{
	if (*ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
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
