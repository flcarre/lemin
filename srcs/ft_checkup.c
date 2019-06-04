/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:27:03 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/04 18:43:43 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_is_there_path(t_graph *start, t_graph *end)
{
	t_links		*link;
	int			ret;

	ret = 0;
	if (start->state & end->state)
		return (1);
	link = start->links;
	if (start->state & 1)
		return (0);
	start->state |= 1;
	while (link && !ret)
	{
		ret = ft_is_there_path(link->room, end);
		link = link->next;
	}
	return (ret);
}

int			ft_checkup(t_path *rooms)
{
	t_graph		*start;
	t_graph		*end;

	if (!(start = ft_return_head(rooms, 64)) \
	|| !(end = ft_return_head(rooms, 128)))
		return (1);
	/*
	t_links		*i;
	i = end->links;
	while (i)
	{
		ft_printf("%{HPURPLE} %{} %s - %s\n", end->name, i->room->name);
		i = i->next;
	}
	t_graph		*room;
	while (rooms)
	{
		room = rooms->room;
		ft_printf("%{HBLUE}%hhu%{} %{HCYAN}%u%{} %s %{YELLOW}%ld %ld%{}\n", \
		room->state, room->nb_ants, room->name, room->x, room->y);
		rooms = rooms->next;
	}
	ft_printf("%{HYELLOW} %{} %d\n", ft_is_there_path(start, end));
	*/
	if (!ft_is_there_path(start, end))
		return (1);
	ft_reset(start, 1);
	return (0);
}
