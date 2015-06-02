/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <glafitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 22:41:39 by glafitte          #+#    #+#             */
/*   Updated: 2015/06/02 23:31:14 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftopt.h"
#include <stdlib.h>

void	ft_add_elem(t_opt **list, char *var)
{
	t_opt	*new;

	if ((new = malloc(sizeof(*new))) == NULL)
		ERR_LOC("allocation memoire !");
	new->value = ft_strdup(var);
	new->prev = (*list)->prev;
	new->next = (*list);
	(*list)->prev->next = new;
	(*list)->prev = new;
}

t_opt	*ft_create_list(char **arg)
{
	t_opt	*root;
	int		i;

	if ((root = malloc(sizeof(*root))) == NULL)
		ERR_LOC("allocation memoire !");
	root->next = root;
	root->prev = root;
	i = -1;
	while (arg[++i])
		ft_add_elem(&root, arg[i]);
	return (root);
}

int		ft_free_env(t_opt *list)
{
	t_opt	*tmp;
	t_opt	*next;

	tmp = list->next;
	while (tmp != list)
	{
		next = tmp->next;
		if (tmp->value != NULL)
			ft_memdel((void **)&tmp->value);
		if (tmp->arg != NULL)
			ft_freetab(&tmp->arg);
		ft_memdel((void **)&tmp);
		tmp = next;
	}
	ft_memdel((void **)&list);
	return (1);
}
