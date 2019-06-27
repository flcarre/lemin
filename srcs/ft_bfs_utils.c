/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:25:10 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/27 21:31:29 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_enqueue_link(t_links **list, t_graph *room, t_links *e)
{
	//static t_links	**prev;
	t_links			**i;

	if (!(e = ft_alloc_link()))
		return (1);
	e->room = room;
	if (!(*list) && (*list = e))
		return (0);
	i = list;
	/*
	prev = (void *)0;
	while (*i && !((*i)->room->state & 8) && !((*i)->room->state & 32) \
	&& (prev = i))
		i = &(*i)->next;
	if (!(room->state & 8) && !(room->state & 32))
	{
		e->next = *i;
		if (prev)
			(*prev)->next = e;
		else
			*i = e;
		return (0);
	}*/
	while (*i)
		i = &(*i)->next;
	*i = e;
	return (0);
}

t_graph	*ft_dequeue(t_links **list)
{
	t_links			*head;
	t_graph			*room;

	if (!(*list))
		return ((void *)0);
	head = *list;
	room = head->room;
	*list = head->next;
	ft_memdel((void **)&head);
	return (room);
}

int		ft_order_path(t_ctn **paths, t_ctn *elem)
{
	t_ctn			*prev;
	t_ctn			*next;
	t_ctn			**curr;

	if (!elem)
		return (1);
	curr = paths;
	prev = (void *)0;
	while (*curr)
	{
		next = *curr;
		if ((*curr)->len >= elem->len)
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

int		ft_endisnext(t_var *var, t_links *links)
{
	while (links)
	{
		if (links->room == var->end)
			return (1);
		links = links->next;
	}
	return (0);
}
