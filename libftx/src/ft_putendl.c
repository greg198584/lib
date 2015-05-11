/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:18:09 by glafitte          #+#    #+#             */
/*   Updated: 2015/04/28 14:35:24 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

void	ftx_putendl(char const *s)
{
	ftx_putstr(s);
	ftx_putchar('\n');
}