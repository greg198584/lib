/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:46:42 by glafitte          #+#    #+#             */
/*   Updated: 2015/04/28 14:35:58 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"
#include <unistd.h>

void	ftx_putendl_fd(char const *s, int fd)
{
	write(fd, s, ftx_strlen(s));
	ftx_putchar_fd('\n', fd);
}
