/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebuild_routes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:13:44 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/10 21:09:25 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		connect(t_room *prev, t_room *next)
{
	if (prev != NULL && prev->type != STANDARD && next->type != STANDARD)
	{
		return ;
	}
	if (prev != NULL && prev->type == STANDARD)
	{
		prev->next = next;
	}
	if (next->type == STANDARD)
	{
		next->prev = prev;
	}
}

static t_bool	has_route(t_room *room)
{
	return (room->next != NULL && room->prev != NULL);
}

static t_room	*route_start(t_room *room)
{
	t_room	*res;

	res = room;
	while (res->prev && res->prev->type != START)
	{
		res = res->prev;
	}
	return (res);
}

static void		break_route(t_room *room)
{
	t_room	*curr;
	t_room	*next;

	curr = route_start(room);
	while (curr && curr->type == STANDARD)
	{
		next = curr->next;
		curr->prev = NULL;
		curr->next = NULL;
		curr = next;
	}
}

void			rebuild_routes(t_lem_in *lem_in, t_route *route)
{
	t_glist	*curr;
	t_room	*prev;

	(void)lem_in;
	curr = route->rooms;
	prev = NULL;
	while (curr != NULL)
	{
		if (has_route(curr->gen.room))
		{
			break_route(curr->gen.room);
		}
		prev = curr->gen.room;
		curr = curr->next;
	}
	curr = route->rooms;
	prev = NULL;
	while (curr != NULL)
	{
		connect(prev, curr->gen.room);
		prev = curr->gen.room;
		curr = curr->next;
	}
}
