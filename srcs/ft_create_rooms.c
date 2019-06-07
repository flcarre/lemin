/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_rooms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 21:33:57 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/08 00:51:20 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_create_room(char *line, t_var *var)
{
	t_graph			*room;
	t_path			*elem;

	if (!(room = ft_alloc_room()))
		return (1);
	if (ft_set_room(&room, line, var))
		return (1);
	room->state |= var->state;
	var->state = 0;
	if (!(elem = ft_alloc_path_elem()))
		return (1);
	elem->room = room;
	ft_push_room(&var->queue, elem);
	ft_gnl(1);
	if (var->state == 64)
		var->start = room;
	if (var->state == 128)
		var->end = room;
	return (0);
}

static int		ft_select_cmd(char *line, t_var *var)
{
	int				ret;
	static int		start = 0;
	static int		end = 0;

	if (ft_isvalidcmd(line) == START)
	{
		var->state = 64;
		ret = ft_create_rooms(var);
		if (ret == 1)
			start++;
		return ((start > 1) ? 2 : ret);
	}
	if (ft_isvalidcmd(line) == END)
	{
		var->state = 128;
		ret = ft_create_rooms(var);
		if (ret == 1)
			end++;
		return ((end > 1) ? 2 : ret);
	}
	return (0);
}

int				ft_create_rooms(t_var *var)
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
				return (ft_select_cmd(line, var));
			return (0);
		}
		if (rank == LINK)
			return ((!ft_make_link(line, var)) ? 3 : 2);
		return (2);
	}
	return ((!ft_create_room(line, var)) ? 1 : 2);
}
