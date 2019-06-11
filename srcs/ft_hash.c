/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:20:36 by flcarre           #+#    #+#             */
/*   Updated: 2019/06/11 16:35:57 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_push_hash(t_var *var, t_graph *room)
{
	t_links			*elem;
	unsigned long	id;

	id = ft_djb2a(room->name) % SIZE_HASH_TABLE;
	elem = ft_alloc_link();
	if (!elem)
		return (1);
	elem->room = room;
	ft_push_link(&var->hash_table[id], elem);
	return (0);
}

t_graph		*ft_return_room(t_var *var, char *name)
{
	t_links			*i;
	unsigned long	id;

	id = ft_djb2a(name) % SIZE_HASH_TABLE;
	i = var->hash_table[id];
	while (i)
	{
		if (!ft_strcmp(i->room->name, name))
			return (i->room);
		i = i->next;
	}
	return ((void *)0);
}
