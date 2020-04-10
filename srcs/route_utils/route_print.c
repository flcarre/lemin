/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:51:20 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/10 21:09:25 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		route_print(t_route *route)
{
	t_bool	rev;

	rev = route->rooms->gen.room->type == END;
	ft_fprintf(2, "Route #%d (len=%d)\t", route->id_route, route->len);
	if (rev)
		ft_glstrev(&route->rooms);
	print_nodes(route->rooms);
	if (rev)
		ft_glstrev(&route->rooms);
}
