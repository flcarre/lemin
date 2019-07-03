/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dijkstra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 23:02:06 by lutsiara          #+#    #+#             */
/*   Updated: 2019/07/03 17:08:23 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		reset(t_var *var)
{
	t_links	*link;
	int		i;

	i = 0;
	while (i < SIZE_HASH_TABLE)
	{
		link = var->hash_addr[i++];
		while (link)
		{
			link->room->dist = -1;
			link->prev = (void *)0;
			if (!((link->room->state ^ 1) & 1))
				link->room->state ^= 1;
			if (!((link->room->state ^ 16) & 16))
				link->room->state ^= 16;
			link = link->next;
		}
	}
}

static int		ft_calc_dist(t_var *var, t_links *link)
{
	while (link)
	{
		var->dij = ft_return_link(var, link->room);
		if (!(link->room->state & 1) && !(link->room->state & 8))
		{
			if (var->dij->room->dist == -1 \
			|| var->dij->room->dist > var->room1->dist + 1)
			{
				var->dij->room->dist = var->room1->dist + 1;
				var->dij->prev = ft_return_link(var, var->room1);
			}
			if (!(var->dij->room->state & 16))
			{
				var->dij->room->state |= 16;
				if (ft_order_hash(&var->hash, \
					ft_new_hash(var->dij, &var->dij->room->dist)))
					return (1);
			}
		}
		link = link->next;
	}
	return (0);
}

static int		ft_build_path(t_var *var, t_ctn *elem)
{
	t_graph	*last_room;

	last_room = (void *)0;
	var->dij = ft_return_link(var, var->end);
	elem->len = var->dij->room->dist;
	while (var->dij)
	{
		if (var->dij->room != var->start && var->dij->room != var->end)
			var->dij->room->state |= 8;
		if (!(var->ptr = ft_alloc_path_elem()))
			return (1);
		var->ptr->room = var->dij->room;
		ft_push_room(&elem->path, var->ptr);
		last_room = var->dij->room;
		var->dij = var->dij->prev;
	}
	if (last_room != var->start)
		return (1);
	return (0);
}

t_ctn			*ft_dijkstra(t_var *var)
{
	t_ctn	*elem;
	t_links	*tmp;

	if (!(elem = ft_alloc_ctn_elem()))
		return ((void *)0);
	var->room1 = var->start;
	var->start->dist = 0;
	var->start->state |= 16;
	tmp = (void *)1;
	while (tmp)
	{
		var->room1->state |= 1;
		if (ft_calc_dist(var, var->room1->links))
		{
			ft_memdel((void **)&elem);
			return ((void *)0);
		}
		tmp = ft_pop_hash(&var->hash);
		var->room1 = (tmp) ? tmp->room : (void *)0;
	}
	if (ft_build_path(var, elem))
		ft_del_ctn(&elem);
	reset(var);
	return ((elem) ? elem : (void *)0);
}
