/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_tube_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:58:42 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/05 20:49:17 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		stop(char *link, char *room1, char *room2)
{
	if (!room1 || !room2)
		return (0);
	while (*room1 && *link && *room1 == *link)
	{
		room1++;
		link++;
	}
	if (!(*link) && *link != '-')
		return (0);
	link++;
	while (*room2 && *link && *room2 == *link)
	{
		room2++;
		link++;
	}
	return (!(*link) && !(*room1) && !(*room2));
}

static int		reset(char *link, char *room1, char *room2, unsigned long *len)
{
	int						ret;

	if (stop(link, room1, room2) && ft_strcmp(room1, room2))
		ret = 0;
	else
		ret = 1;
	len[0] = 0;
	len[1] = 0;
	return (ret);
}

int				ft_control_tube_name(char *line, t_path *rooms, \
				t_graph **roomA, t_graph **roomB)
{
	unsigned long			tmp;
	static unsigned long	len[2] = {0};

	if (!rooms \
	|| (*roomA && *roomB && stop(line, (*roomA)->name, (*roomB)->name)))
	{
		//ft_printf("%{GREEN}%s%{} %s - %s\n", line, (*roomA)->name, (*roomB)->name);
		if (*roomA && *roomB)
			return (reset(line, (*roomA)->name, (*roomB)->name, len));
		return (reset(line, (void *)0, (void *)0, len));
	}
	tmp = ft_strlen(rooms->room->name);
	if (!ft_strncmp(line, rooms->room->name, tmp))
	{
			len[0] = (tmp >= len[0]) ? tmp : len[0];
			if (tmp >= len[0])
				*roomA = rooms->room;
	}
	if (!ft_strrevncmp(line, rooms->room->name, tmp))
	{
		len[1] = (tmp >= len[1]) ? tmp : len[1];
		if (tmp >= len[1])
			*roomB = rooms->room;
	}
	return (ft_control_tube_name(line, rooms->next, roomA, roomB));
}
