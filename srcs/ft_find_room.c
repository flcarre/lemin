/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:38:50 by lutsiara          #+#    #+#             */
/*   Updated: 2019/05/31 15:50:22 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_graph		*ft_find_room(char *name, t_path *rooms)
{
	if (!rooms)
		return ((void *)0);
	if (ft_strncmp(name, rooms->room->name, ft_strlen(rooms->room->name)))
		return (ft_find_room(name, rooms->next));
	return (rooms->room);
}