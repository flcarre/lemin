/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_tube_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:58:42 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/04 19:12:40 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static unsigned long	ft_search_separator(char *line, t_path *rooms)
{
	unsigned long	len;
	unsigned long	tmp;

	len = 0;
	while (rooms)
	{
		tmp = ft_strlen(rooms->room->name);
		if (!ft_strncmp(line, rooms->room->name, tmp))
			len = (tmp >= len) ? tmp : len;
		rooms = rooms->next;
	}
	return (len);
}

int						ft_control_tube_name(char *line, t_path *rooms, \
						char **room1, char **room2)
{
	unsigned long	i;
	t_path			*room;

	i = ft_search_separator(line, rooms);
	line[i] = '\0';
	room = rooms;
	while (room && ft_strcmp(line, room->room->name))
		room = room->next;
	if (!room)
		return (1);
	*room1 = room->room->name;
	room = rooms;
	while (room && ft_strcmp(line + i + 1, room->room->name))
		room = room->next;
	if (!room)
		return (1);
	*room2 = room->room->name;
	return ((ft_strcmp(*room1, *room2)) ? 0 : 1);
}
