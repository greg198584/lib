/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <glafitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/30 18:55:19 by glafitte          #+#    #+#             */
/*   Updated: 2015/05/07 16:20:01 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_woption(char c, char const *opt)
{
	ft_fprintf(2, "Error: wong option '%c'. Usage: [-%s]\n", c, opt);
	return (-1);
}

static int	ft_getopt(char c, char const *s)
{
	int	i;

	i = 0;
	while (s && *(s + i))
		if (c == *(s + i++))
			return (ft_pow(2, i - 1));
	return (0);
}

int			ft_option(int argc, char **argv, char const *opt, int *start)
{
	int	tmp;
	int	i;
	int	j;

	if (ft_strlen(opt) > 31)
		return (0);
	i = 0;
	*start = 0;
	while (++i < argc)
	{
		if (argv[i][0] != '-' || !ft_strcmp(argv[i], "--"))
			break ;
		j = ft_strlen(argv[i]);
		while (--j > 0)
		{
			if ((tmp = ft_getopt(argv[i][j], opt)) == 0)
				return (ft_woption(argv[i][j], opt));
			*start = *start | tmp;
		}
	}
	return (i);
}
