/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 16:41:07 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/10 21:09:25 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parse(t_lem_in *lem_in)
{
	char *line;

	line = NULL;
	parse_ants_count(lem_in, &line);
	parse_rooms(lem_in, &line);
	lem_in->array_room = (t_room**)glist_to_array(lem_in->rooms);
	array_sort((void **)lem_in->array_room, lem_in->room_count, room_cmp);
	parse_links(lem_in, &line);
	lem_in->start->ants = lem_in->total_ants;
	parse_optimizer(lem_in);
	ft_strdel(&line);
}
