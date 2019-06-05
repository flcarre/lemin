/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_tube_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:58:42 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/05 13:55:29 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int						ft_control_tube_name(char *line, t_path *rooms, \
						t_graph **roomA, t_graph **roomB)
{
	unsigned long			tmp;
	static unsigned long	len[2] = {0};
	static char				*room1 = (void *)0;
	static char				*room2 = (void *)0;

	if (!rooms)
		return((room1 && room2) ? ft_strcmp(room1, room2) : 1);
	tmp = ft_strlen(rooms->room->name);
	if (!ft_strncmp(line, rooms->room->name, tmp))
	{
			len[0] = (tmp >= len[0]) ? tmp : len[0];
			if (tmp >= len[0])
				*roomA = rooms->room;
			if (tmp >= len[0])
				room1 = rooms->room->name;
	}
	ft_printf("%d\n", ft_strrevncmp(line, rooms->room->name, tmp));
	ft_printf("room = %s\n", rooms->room->name);
	ft_printf("links = %s\n", line);
	ft_printf("room1 = %s\n", room1);
	ft_printf("room2 = %s\n", room2);
	if (!ft_strrevncmp(line, rooms->room->name, tmp))
	{
		len[1] = (tmp >= len[1]) ? tmp : len[1];
		if (tmp >= len[1])
			*roomB = rooms->room;
		if (tmp >= len[1])
			room2 = rooms->room->name;
	}
	return (ft_control_tube_name(line, rooms->next, roomA, roomB));
}
