/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_create_links.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 16:51:25 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/10 21:09:25 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_bool	room_find_duplicate_link(t_room *room, char *name)
{
	t_glist	*curr;

	if (room->links == NULL && room->links_count == 0)
		return (FALSE);
	curr = room->links;
	while (curr)
	{
		if (ft_strequ(curr->gen.room->name, name))
			return (TRUE);
		curr = curr->next;
	}
	return (FALSE);
}

void			room_add_link(t_lem_in *lem_in, char *origin, char *target)
{
	t_room	*origin_room;
	t_room	*target_room;
	t_glist	*new_o;
	t_glist	*new_t;

	origin_room = room_find_by_name(lem_in, origin);
	target_room = room_find_by_name(lem_in, target);
	if (room_find_duplicate_link(origin_room, target) == FALSE)
	{
		new_t = ft_glstnew(target_room, sizeof(t_room));
		ft_glstadd(&origin_room->links, new_t);
		origin_room->links_count++;
		new_o = ft_glstnew(origin_room, sizeof(t_room));
		ft_glstadd(&target_room->links, new_o);
		target_room->links_count++;
	}
}

void			room_remove_link(t_room *room, t_room *link)
{
	t_glist	**curr;

	curr = &room->links;
	while (*curr != NULL)
	{
		if ((*curr)->gen.room == link)
		{
			ft_glstdelone(curr, NULL);
			room->links_count--;
			return ;
		}
		curr = &(*curr)->next;
	}
}
