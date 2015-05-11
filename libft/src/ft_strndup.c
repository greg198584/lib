/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 08:56:58 by glafitte          #+#    #+#             */
/*   Updated: 2015/05/08 11:57:22 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *src, size_t len)
{
	char	*dst;
	char	*s;

	if (!(dst = ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	s = dst;
	while((*s++ = *src++) != '\0' && --len)
		continue;
	*s = '\0';
	return (dst);
}
