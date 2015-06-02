/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <glafitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 21:34:47 by glafitte          #+#    #+#             */
/*   Updated: 2015/06/02 23:02:54 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftopt.h"
#include <unistd.h>

static void	ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}

void		ft_putstr_color(const char *str, char *color, int i)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr("\033[0m");
	if (i == 1)
		write(1, "\n", 1);
}

int			ft_err(char *file, int line, char *msg)
{
	ft_putstr_color("[ Error ]", RED, 0);
	ft_fprintf(2,"%s\n", msg);
	ft_fprintf(2, "%s", file);
	ft_fprintf(2, " at line: ");
	ft_fprintf(2, "%d\n", line);
	return (1);
}
