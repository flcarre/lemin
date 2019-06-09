/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 21:59:58 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/09 14:03:18 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_isunique(char *name, t_var *var)
{
	if (!var->ptr)
		return (1);
	if (!ft_strcmp(var->ptr->room->name, name))
		return (0);
	var->ptr = var->ptr->next;
	return (ft_isunique(name, var));
}

int			ft_set_room(t_graph **room, char *line, t_var *var)
{
	char	*tmp;

	tmp = ft_strchr(line, ' ');
	*tmp = '\0';
	var->ptr = var->queue;
	if (!ft_isunique(line, var))
	{
		ft_memdel((void **)&(*room));
		return (1);
	}
	(*room)->name = line;
	(*room)->x = ft_atol(tmp + 1);
	(*room)->y = ft_atol(ft_strchr(tmp + 1, ' '));
	return (0);
}
