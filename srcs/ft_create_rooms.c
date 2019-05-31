/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_rooms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:18:51 by lutsiara          #+#    #+#             */
/*   Updated: 2019/05/31 17:34:07 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_create_room(char *line, t_path **list, unsigned char state)
{
	//creating a room
	return (0);
}

int				ft_create_rooms(t_path **list, unsigned char state)
{
	char			*line;
	t_rank			rank;
	int				ret;

	line = (void *)0;
	if (gnl(STDIN_FILENO, &line) != 1)
		return (1);
	if ((rank = ft_rank_line(line)) != ROOM)
	{
		if (rank == COMMAND || rank == COMMENT)
		{
			if (rank == COMMAND)
				return (ft_select_cmd(&line, list));
			ft_memdel((void **)&line);
			return (ft_create_rooms(list, state));
		}
		if (rank == LINK)
			return ((!ft_make_link(&line, list)) ? 2 : 1);
		ft_memdel((void **)&line);
		return (1);
	}
	ret = ft_create_room(line, list, state);
	ft_memdel((void **)&line);
	return (ret);
}
