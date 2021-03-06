/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 09:43:56 by glafitte          #+#    #+#             */
/*   Updated: 2015/06/02 22:25:27 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

int	ftx_err_loc(char *file, int line, char *msg)
{
	ftx_fprintf(2, "Erreur: %s\n", msg);
	ftx_fprintf(2, "%s", file);
	ftx_fprintf(2, " at line: ");
	ftx_fprintf(2, "%d\n", line);
	return (1);
}
