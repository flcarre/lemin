/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:51:20 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 17:28:23 by lutsiara         ###   ########.fr       */
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
