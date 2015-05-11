/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/30 11:02:12 by glafitte          #+#    #+#             */
/*   Updated: 2015/04/30 11:13:10 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strrep(char const *str, char *sub, char *rep, int r)
{
	char	*result;
	char	*pos1;
	char	*pos2;
	int		f;

	f = 0;
	pos1 = (char *)str;
	while ((pos1 = ft_strstr(pos1, sub)) && f++)
		pos1 += ft_strlen(sub);
	f = ((ft_strlen(str) - (ft_strlen(sub) * f)) + (ft_strlen(rep) * f)) + 1;
	result = (char *)ft_memalloc(f);
	pos1 = (char *)str;
	while ((pos2 = ft_strstr(pos1, sub)))
	{
		f = (pos2 - pos1);
		ft_strncat(result, pos1, f);
		ft_strncat(result, rep, ft_strlen(rep));
		pos1 = (pos2 + ft_strlen(sub));
		if (!r)
			break ;
	}
	if (pos1 != (str + ft_strlen(str)))
		ft_strncat(result, pos1, (str - pos1));
	return (result);
}

char	*ft_strrepf(char const *str, char *sub, char *rep, int r)
{
	char	*result;
	char	*pos1;
	char	*pos2;
	int		f;

	f = 0;
	pos1 = (char *)str;
	while ((pos1 = ft_strstr(pos1, sub)) && f++)
		pos1 += ft_strlen(sub);
	f = ((ft_strlen(str) - (ft_strlen(sub) * f)) + (ft_strlen(rep) * f)) + 1;
	result = (char *)ft_memalloc(f);
	pos1 = (char *)str;
	while ((pos2 = ft_strstr(pos1, sub)))
	{
		f = (pos2 - pos1);
		ft_strncat(result, pos1, f);
		ft_strncat(result, rep, ft_strlen(rep));
		pos1 = (pos2 + ft_strlen(sub));
		if (!r)
			break ;
	}
	if (pos1 != (str + ft_strlen(str)))
		ft_strncat(result, pos1, (str - pos1));
	free((void *)str);
	return (result);
}
