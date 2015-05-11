/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_implode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 17:24:45 by glafitte          #+#    #+#             */
/*   Updated: 2015/04/27 17:36:41 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_implode(char **tab, char const *to_put)
{
	char	*dst;
	int		size;
	int		i;

	i = -1;
	size = 0;
	if (tab == NULL)
		return (NULL);
	if (to_put == NULL)
		to_put = "";
	while (tab[++i] != NULL && (size += ft_strlen(tab[i])))
		if (tab[i + 1] != NULL)
			size += ft_strlen(to_put);
	if ((dst = (char *)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	ft_bzero((void *)dst, size + 1);
	i = -1;
	while (tab[++i] != NULL)
	{
		dst = ((!i) ? ft_strcpy(dst, tab[i]) : ft_strcat(dst, tab[i]));
		if (tab[i + 1] != NULL)
			ft_strcat(dst, to_put);
	}
	return (dst);
}
