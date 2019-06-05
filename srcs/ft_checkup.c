/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:27:03 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/05 22:24:08 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_is_there_path(t_graph *start, t_graph *end)
{
	t_links		*link;
	int			ret;

	ret = 0;
	if (start->state & end->state)
		return (1);
	link = start->links;
	if (start->state & 1)
		return (0);
	start->state |= 1;
	while (link && !ret)
	{
		ret = ft_is_there_path(link->room, end);
		link = link->next;
	}
	return (ret);
}

static int	ft_there_is_duplicate(t_path *rooms)
{
	t_path		*room;

	while (rooms)
	{
		room = rooms->next;
		while (room)
		{
			if (!ft_strcmp(room->room->name, rooms->room->name))
				return (1);
			room = room->next;
		}
		rooms = rooms->next;
	}
	return (0);
}

int			ft_checkup(t_path *rooms, t_graph *start)
{
	t_graph		*end;

	if (ft_there_is_duplicate(rooms))
		return (1);
	if (!start || !(end = ft_return_head(rooms, 128)))
		return (1);
	if (!ft_is_there_path(start, end))
		return (1);
	ft_reset(start, 1);
	return (0);
}
