/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bfs_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:56:08 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/09 17:04:30 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool			can_traverse(t_inter *inter, t_room *dst)
{
	if (inter->augmentation > 0 && dst->visited)
		return (FALSE);
	if (inter->augmentation == 0 && dst->visited2)
		return (FALSE);
	if (inter->room->prev != NULL && inter->room->prev == dst)
		return (FALSE);
	if (inter->intersection == dst)
		return (FALSE);
	if (inter->intersection != NULL
		&& inter->room == inter->intersection
		&& dst != inter->room->next)
	{
		return (FALSE);
	}
	if (inter->room->type == START && dst->prev == inter->room)
		return (FALSE);
	if (dst->type == START)
		return (FALSE);
	return (TRUE);
}

t_bool			in_intersection(t_room *src, t_room *dst)
{
	if (src->next != NULL && src->next == dst)
		return (FALSE);
	if (dst->prev == NULL)
		return (FALSE);
	if (dst->prev == src)
		return (FALSE);
	return (TRUE);
}

t_bool			out_intersection(t_room *src, t_room *dst)
{
	return (src->next != NULL && src->next != dst);
}

t_inter			*go_to_start(t_lem_in *lem_in, t_inter *inter)
{
	t_room	*room;
	t_inter	*res;

	room = inter->parent->room;
	while (room->prev->type != START)
	{
		room = room->prev;
	}
	if (inter->intersection == room)
	{
		return (NULL);
	}
	res = inter_create_child(lem_in, inter, lem_in->start);
	res = inter_create_child(lem_in, res, room);
	res->augmentation++;
	return (res);
}

void			mark_as_visited(t_inter *inter)
{
	if (inter->room->type == STANDARD && inter->room->next == NULL)
	{
		if (inter->augmentation > 0)
			inter->room->visited = TRUE;
		else
			inter->room->visited2 = TRUE;
	}
}
