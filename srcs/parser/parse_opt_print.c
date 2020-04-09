/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opt_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:51:25 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 18:20:42 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	room_print_extra(t_room *room)
{
	ft_fprintf(2, " %s :\n", room->name);
	ft_fprintf(2, "\tpoint = {%d,", room->pos.x);
	ft_fprintf(2, "\t%d}.\n", room->pos.y);
	ft_fprintf(2, "\tnb_links = %d.\n", room->links_count);
	ft_fprintf(2, "\ttype = ");
	if (room->type == STANDARD)
		ft_fprintf(2, "standard\n");
	else
	{
		if (room->type == START)
			ft_fprintf(2, "start\n");
		else
			ft_fprintf(2, "end\n");
	}
	ft_fprintf(2, "\tants = %d.\n", room->ants);
}

void	lem_in_print_all_rooms(t_lem_in *lem_in)
{
	t_glist *curr;

	curr = lem_in->rooms;
	ft_fprintf(2, "\n");
	ft_fprintf(2, "\t\tPrint_rooms\n");
	ft_fprintf(2, "length = %d\n\n", lem_in->room_count);
	while (curr != NULL)
	{
		room_print_extra(curr->gen.room);
		curr = curr->next;
	}
	ft_fprintf(2, " \n");
}
