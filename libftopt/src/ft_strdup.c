/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 17:36:27 by glafitte          #+#    #+#             */
/*   Updated: 2015/06/02 21:43:28 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		str_source_size;
	char	*str;

	i = 0;
	str_source_size = 0;
	while (src[str_source_size] != '\0')
		str_source_size++;
	if ((str = (char *)malloc(sizeof(src) * (str_source_size + 1))) == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
