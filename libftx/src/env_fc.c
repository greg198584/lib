/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_fc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 16:11:50 by glafitte          #+#    #+#             */
/*   Updated: 2015/05/08 11:24:08 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"
#include <stdlib.h>

char	*ftx_getenv(t_env *env, char *var_name)
{
	char	*var;

	var = ftx_find_element(env, var_name);
	return (var);
}

int		ftx_free_env(t_env *list)
{
	t_env	*tmp;
	t_env	*next;

	tmp = list->next;
	while (tmp != list)
	{
		next = tmp->next;
		ftx_memdel((void **)&tmp->data);
		ftx_memdel((void **)&tmp);
		tmp = next;
	}
	ftx_memdel((void **)&list);
	return (1);
}
