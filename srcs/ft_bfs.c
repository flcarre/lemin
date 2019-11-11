/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:17:05 by lutsiara          #+#    #+#             */
/*   Updated: 2019/11/07 10:50:25 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_traceback(t_var *var)
{
	t_links	*ptr;
	t_links	*i;

	i = var->end->links;
	while (i)
	{
		var->room2 = (void *)0;
		ptr = ft_return_link(var, i->room);
		if (ptr->prev && !(ptr->room->state & 32))
		{
			while (ptr)
			{
				if (ptr->room != var->start)
					ptr->room->state |= 32;
				var->room2 = ptr->room;
				ptr = ptr->prev;
			}
		}
		if (var->room2 && var->room2 != var->start)
			return (1);
		if (var->room2 && var->room2 == var->start)
			return (0);
		i = i->next;
	}
	return (0);
}

static int	ft_build_path(t_var *var, t_ctn *elem)
{
	var->dij = var->end->links;
	var->list = ft_return_link(var, var->dij->room);
	while (var->dij && !var->list->prev && var->list->room != var->start)
	{
		var->dij = var->dij->next;
		if (var->dij)
			var->list = ft_return_link(var, var->dij->room);
	}
	if (!var->dij)
		return (1);
	if (ft_add(var, var->end, elem))
		return (1);
	while (var->list)
	{
		if (ft_add(var, var->list->room, elem))
			return (1);
		var->list = var->list->prev;
	}
	return (0);
}

static int	ft_mark_and_trace(t_var *var, unsigned char m)
{
	t_links	*i;

	i = var->dij->room->links;
	while (i)
	{
		if (!(i->room->state & (32 + 1)))
			if (var->dij->room == var->start || !(var->dij->room->state & m) \
			|| ((var->dij->room->state & (m + 1)) \
			&& !(i->room->state & (m + 1))))
			{
				if (i->room != var->end && !ft_endisnext(var, i))
				{
					if (ft_enqueue_link(&var->list, i->room))
						return (1);
					i->room->state |= 1;
					(ft_return_link(var, i->room))->prev = \
					ft_return_link(var, var->dij->room);
				}
				else if (i->room == var->end \
				&& ft_enqueue_link(&var->list, i->room))
					return (1);
			}
		i = i->next;
	}
	return (0);
}

static void	reset(t_var *var)
{
	t_links	*link;
	int		i;

	var->dij = (void *)0;
	var->list = (void *)0;
	i = 0;
	while (i < SIZE_HASH_TABLE)
	{
		link = var->hash_addr[i++];
		while (link)
		{
			link->prev = (void *)0;
			if (!((link->room->state ^ 1) & 1))
				link->room->state ^= 1;
			link = link->next;
		}
	}
}

t_ctn		*ft_bfs(t_var *var, unsigned char m)
{
	t_ctn	*elem;

	if (!(elem = ft_alloc_ctn_elem()))
		return ((void *)0);
	if (ft_enqueue_link(&var->list, var->start) && !ft_del_ctn(&elem))
		return ((void *)0);
	var->start->state |= 1;
	while (var->list \
	&& (var->dij = ft_return_link(var, ft_dequeue(&var->list))))
	{
		if (var->dij->room != var->end && ft_mark_and_trace(var, m) \
		&& !ft_del_ctn(&elem) && !ft_del_links(&var->list))
			return ((void *)0);
		else if (var->dij->room == var->end)
		{
			if (ft_traceback(var) && !ft_del_links(&var->list) \
			&& !ft_del_ctn(&elem))
				return ((void *)0);
			ft_del_links(&var->list);
		}
	}
	if (!ft_del_links(&var->list) && ft_build_path(var, elem))
		ft_del_ctn(&elem);
	reset(var);
	return (elem);
}
