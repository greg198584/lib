/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 10:09:33 by glafitte          #+#    #+#             */
/*   Updated: 2015/05/08 11:21:11 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"
#include <stdlib.h>

void	ftx_add_elem(t_env **list, char *var_name, char *var)
{
	t_env	*new;
	int		i;
	int		j;
	int		s;

	if ((new = malloc(sizeof(*new))) == NULL)
		X_ERR_LOC("allocation memoire !");
	s = (var_name != NULL) ? ftx_strlen(var_name) : 0;
	if ((new->data = malloc(sizeof(char) * s + ftx_strlen(var) + 1)) == NULL)
		X_ERR_LOC("allocation memoire");
	j = -1;
	i = -1;
	while (var_name != NULL && var_name[++i])
		new->data[++j] = var_name[i];
	i = -1;
	if (j != -1)
		new->data[++j] = '=';
	while (var[++i])
		new->data[++j] = var[i];
	new->data[++j] = '\0';
	new->prev = (*list)->prev;
	new->next = (*list);
	(*list)->prev->next = new;
	(*list)->prev = new;
}

t_env	*ftx_retenv(char **env)
{
	t_env	*root;
	int		i;

	if ((root = malloc(sizeof(*root))) == NULL)
		X_ERR_LOC("allocation memoire !");
	root->next = root;
	root->prev = root;
	i = -1;
	while (env[++i])
		ftx_add_elem(&root, NULL, env[i]);
	return (root);
}

void	ftx_remove_elem(t_env **list, char *value)
{
	t_env	*tmp;

	tmp = (*list)->next;
	while (tmp != (*list) && !ftx_strcmp_sh(tmp->data, value, 1))
		tmp = tmp->next;
	if (tmp != (*list))
	{
		ftx_memdel((void **)&tmp->data);
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		ftx_memdel((void **)&tmp);
	}
}
