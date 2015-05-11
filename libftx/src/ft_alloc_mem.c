/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 10:20:36 by glafitte          #+#    #+#             */
/*   Updated: 2015/05/08 10:24:34 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	ftx_bzero(void *s, size_t n)
{
	unsigned char	*buffer;

	buffer = s;
	while (n--)
		*buffer++ = 0;
}
void	*ftx_memalloc(size_t size)
{
	void	*mem;

	if ((size <= 0 || (mem = malloc(size)) == NULL))
		return (NULL);
	ftx_bzero(mem, size);
	return (mem);
}

void	ftx_memdel(void **ap)
{
	if (*ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
