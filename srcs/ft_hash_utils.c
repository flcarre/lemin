/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 05:42:22 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/12 20:20:23 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_hash		*ft_new_hash(t_links *hash_addr, int *dist)
{
	t_hash	*elem;

	if (!(elem = ft_memalloc(sizeof(t_hash))))
		return ((void *)0);
	elem->hash = hash_addr;
	elem->dist = dist;
	elem->next = (void *)0;
	return (elem);
}

int			ft_order_hash(t_hash **hash, t_hash *elem)
{
	t_hash	*prev;
	t_hash	*next;
	t_hash	**curr;

	if (!elem)
		return (1);
	curr = hash;
	prev = (void *)0;
	while (*curr)
	{
		next = *curr;
		if (*((*curr)->dist) >= *(elem->dist))
		{
			elem->next = next;
			if (prev)
				prev->next = elem;
			else
				*curr = elem;
			return (0);
		}
		prev = *curr;
		curr = &(*curr)->next;
	}
	*curr = elem;
	return (0);
}

t_links		*ft_pop_hash(t_hash **hash)
{
	t_hash	*head;
	t_links	*elem;

	if (!(*hash))
		return ((void *)0);
	head = *hash;
	*hash = (*hash)->next;
	elem = head->hash;
	ft_memdel((void **)&head);
	return (elem);
}
