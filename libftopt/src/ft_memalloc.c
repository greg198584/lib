/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 07:58:35 by glafitte          #+#    #+#             */
/*   Updated: 2015/06/02 22:39:45 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftopt.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if ((size <= 0 || (mem = malloc(size)) == NULL))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
