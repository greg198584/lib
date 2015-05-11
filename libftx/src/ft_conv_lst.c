/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 17:34:17 by glafitte          #+#    #+#             */
/*   Updated: 2015/05/08 10:49:08 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"
#include <stdlib.h>

static char	*ft_strchr(const char *s, int c)
{
	const char	*ptr;

	if (s == NULL)
		return (NULL);
	ptr = s;
	while (*ptr != (char)c)
	{
		if (*ptr == 0)
			return (NULL);
		ptr++;
	}
	return (char *)ptr;
}

char		**ft_conv_lst(t_env *env)
{
	t_env	*tmp;
	char	**arr;
	int		i;
	int		count;

	if (!env)
		return (NULL);
	count = 0;
	tmp = env->next;
	while (tmp != env)
	{
		++count;
		tmp = tmp->next;
	}
	if ((arr = ftx_memalloc(sizeof(char *) * (count + 1))) == NULL)
		X_ERR_LOC("Erreur d'allocation memoire");
	i = -1;
	tmp = env->next;
	while (tmp != env)
	{
		arr[++i] = ftx_strdup(tmp->data);
		tmp = tmp->next;
	}
	arr[++i] = NULL;
	return (arr);
}

char		**ft_tab_var(char **arg)
{
	char	**arr;
	int		i;
	int		count;

	i = -1;
	count = -1;
	if (arg == NULL)
		return (NULL);
	while (arg[++count] != NULL)
	{
		if (ft_strchr(arg[count], '='))
			i++;
	}
	if ((arr = ftx_memalloc(sizeof(char *) * ((count - i) + 1))) == NULL)
		X_ERR_LOC("Erreur d'allocation memoire");
	i = -1;
	count = 0;
	while (arg[++i] != NULL)
	{
		if (ft_strchr(arg[i], '='))
			arr[count++] = ftx_strdup(arg[i]);
	}
	arr[count] = NULL;
	return (arr);
}

char		**ft_tab_not_var(char **arg)
{
	char	**arr;
	int		i;
	int		count;

	i = -1;
	count = -1;
	if (arg == NULL)
		return (NULL);
	while (arg[++count] != NULL)
	{
		if (ft_strchr(arg[count], '='))
			i++;
	}
	if ((arr = malloc(sizeof(char *) * ((count - i) + 1))) == NULL)
		X_ERR_LOC("Erreur d'allocation memoire");
	i = -1;
	count = 0;
	while (arg[++i] != NULL)
	{
		if (!ft_strchr(arg[i], '=') && !ftx_strcmp_sh(arg[i], "env", 0) &&
			!ftx_strcmp_sh(arg[i], "-i", 0))
			arr[count++] = ftx_strdup(arg[i]);
	}
	arr[count] = NULL;
	return (arr);
}
