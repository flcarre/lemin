/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:39:09 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/15 22:17:26 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_in_init(t_lem_in *lem_in)
{
	ft_bzero(lem_in, sizeof(t_lem_in));
}

void	lem_in_add_room(t_lem_in *lem_in, t_room *room)
{
	t_glist	*new;

	new = ft_glstnew(room, sizeof(t_room));
	ft_glstadd(&lem_in->rooms, new);
	lem_in->room_count++;
	if (room->type == START)
	{
		if (lem_in->start != NULL)
			lem_in_error();
		lem_in->start = room;
	}
	else if (room->type == END)
	{
		if (lem_in->end != NULL)
			lem_in_error();
		lem_in->end = room;
	}
}

void	lem_in_free(t_lem_in *lem_in)
{
	ft_glstdel(&lem_in->rooms, room_free);
	free(lem_in->array_room);
	free_saved_output(lem_in);
}

void	lem_in_remove_room(t_lem_in *lem_in, t_room *room)
{
	t_glist	**curr;

	curr = &lem_in->rooms;
	while (*curr != NULL)
	{
		if ((*curr)->gen.room == room)
		{
			ft_glstdelone(curr, room_free);
			lem_in->room_count--;
			return ;
		}
		curr = &(*curr)->next;
	}
}

void	lem_in_error(void)
{
	ft_putendl("ERROR");
	exit(EXIT_FAILURE);
}
