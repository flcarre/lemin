/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 17:24:59 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/02 19:37:13 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_link_rooms(t_path *rooms, char *room1, char *room2)
{
	t_graph		*roomA;
	t_graph		*roomB;
	t_links		*link;

	roomA = ft_find_room(room1, rooms);
	roomB = ft_find_room(room2, rooms);
	if (!(link = ft_alloc_link()))
		return (1);
	ft_set_link(&link, roomB);
	ft_enqueue_link(&(roomA->links), link);
	if (!(link = ft_alloc_link()))
		return (1);
	ft_set_link(&link, roomA);
	ft_enqueue_link(&(roomB->links), link);
	return (0);
}
