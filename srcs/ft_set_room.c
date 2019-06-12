/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 21:59:58 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/12 23:19:40 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_isunique(char *name, t_var *var)
{
	unsigned long	id;
	unsigned long	hash;

	hash = ft_djb2a(name);
	id = hash % SIZE_HASH_TABLE;
	if (var->hash_name[id] && ft_return_room(var, name))
			return (0);
	return (1);
}

int			ft_set_room(t_graph **room, char *line, t_var *var)
{
	char			*tmp;

	tmp = ft_strchr(line, ' ');
	*tmp = '\0';
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
