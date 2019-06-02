/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_tube_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:58:42 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/02 22:22:19 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_control_tube_name(char *line, t_path *rooms, \
		char **room1, char **room2)
{
	unsigned long	len;
	t_path			*room;

	room = rooms;
	while (room && ft_strncmp(line, room->room->name, \
		(len = ft_strlen(room->room->name))))
		room = room->next;
	if (!room)
		return (1);
	*room1 = room->room->name;
	line = line + len;
	if (*(line++) != '-')
		return (1);
	room = rooms;
	while (room && ft_strncmp(line, room->room->name, \
		(len = ft_strlen(room->room->name))))
		room = room->next;
	if (!room)
		return (1);
	*room2 = room->room->name;
	return ((ft_strcmp(*room1, *room2)) ? 0 : 1);
}
