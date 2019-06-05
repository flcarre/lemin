/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_rooms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:18:51 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/05 22:09:29 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_create_room(char *line, t_path **list, unsigned char *state)
{
	t_graph			*room;
	char			*tmp;
	t_path			*elem;

	if (!(room = ft_alloc_room()))
		return (1);
	if (!(tmp = ft_strchr((const char *)line, (int)' ')) \
	|| ft_set_room(&room, line, ft_atol(tmp), \
	ft_atol(ft_strchr((const char *)(tmp + 1), (int)' '))))
		return (1);
	room->state |= *state;
	*state = 0;
	if (!(elem = ft_alloc_path_elem()))
		return (1);
	ft_set_path_elem(&elem, room);
	ft_push_room(list, elem);
	ft_gnl(1);
	return (0);
}

static int		ft_select_cmd(char *line, t_path **list, unsigned char *state)
{
	int				ret;
	static int		start = 0;
	static int		end = 0;

	if (!ft_strcmp(line + 2, "end"))
	{
		*state = 128;
		ret = ft_create_rooms(list, state);
		if (ret)
			end++;
		return ((end > 1) ? 2 : ret);
	}
	if (!ft_strcmp(line + 2, "start"))
	{
		*state = 64;
		ret = ft_create_rooms(list, state);
		if (ret)
			start++;
		return ((start > 1) ? 2 : ret);
	}
	return (0);
}

int				ft_create_rooms(t_path **list, unsigned char *state)
{
	char			*line;
	t_rank			rank;

	line = (void *)0;
	if (!(line = ft_gnl(1)) || !(*line))
		return (2);
	if ((rank = ft_rank_line(line)) != ROOM)
	{
		if (rank == COMMAND || rank == COMMENT)
		{
			if (rank == COMMAND)
				return (ft_select_cmd(line, list, state));
			return (0);
		}
		if (rank == LINK)
			return ((!ft_make_link(line, list, (void *)0)) ? 3 : 2);
		return (2);
	}
	return ((!ft_create_room(line, list, state)) ? 1 : 2);
}
