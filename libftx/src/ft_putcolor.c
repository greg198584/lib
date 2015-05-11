/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 11:01:51 by glafitte          #+#    #+#             */
/*   Updated: 2015/04/28 14:35:08 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

void	ftx_putstr_color(const char *str, char *color, int i)
{
	ftx_putstr(color);
	ftx_putstr(str);
	ftx_putstr("\033[0m");
	if (i == 1)
		ftx_putchar('\n');
}
