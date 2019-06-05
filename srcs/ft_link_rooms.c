/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 17:24:59 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/05 20:24:18 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_link_rooms(t_graph *roomA, t_graph *roomB, t_graph **start)
{
	t_links		*link;

	if (start)
	{
		if (roomA->state & 64)
			*start = roomA;
		if (roomB->state & 64)
			*start = roomB;
	}
	if (!(link = ft_alloc_link()))
		return (1);
	ft_set_link(&link, roomB);
	ft_push_link(&(roomA->links), link);
	if (!(link = ft_alloc_link()))
		return (1);
	ft_set_link(&link, roomA);
	ft_push_link(&(roomB->links), link);
	return (0);
}
