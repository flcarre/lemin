/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:17:05 by lutsiara          #+#    #+#             */
/*   Updated: 2019/07/03 18:34:14 by lutsiara         ###   ########.fr       */
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
		i = i->next;
	}
	return (0);
}

static int	ft_add(t_var *var, t_graph *room)
{
	if (!(var->ptr = ft_alloc_path_elem()))
		return (!ft_del_ctn(&var->elem));
	var->ptr->room = room;
	ft_push_room(&var->elem->path, var->ptr);
	if (room != var->start)
		var->elem->len++;
	return (0);
}

static int	ft_build_paths(t_var *var)
{
	var->dij = var->end->links;
	while (var->dij)
	{
		var->elem = (void *)0;
		var->list = ft_return_link(var, var->dij->room);
		if (var->list->prev || var->list->room == var->start)
		{
			if (!(var->elem = ft_alloc_ctn_elem()) || ft_add(var, var->end))
				return (1);
			while (var->list)
			{
				if (ft_add(var, var->list->room))
					return (1);
				var->list = var->list->prev;
			}
		}
		if (var->elem && ++var->nb_bfs)
			ft_order_path(&var->bfs, var->elem);
		var->dij = var->dij->next;
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

int			ft_bfs(t_var *var, unsigned char m)
{
	if (ft_enqueue_link(&var->list, var->start))
		return (1);
	var->dij = (void *)0;
	var->start->state |= 1;
	while (var->list)
	{
		var->dij = ft_return_link(var, ft_dequeue(&var->list));
		if (var->dij->room != var->end && ft_mark_and_trace(var, m))
			return (!ft_del_links(&var->list));
		else if (var->dij->room == var->end)
		{
			if (ft_traceback(var))
				return (!ft_del_links(&var->list));
		}
	}
	ft_reset(var, 8);
	ft_reset(var, 1);
	if (m == 32)
		return (ft_build_paths(var));
	return (ft_bfs(var, 32));
}
