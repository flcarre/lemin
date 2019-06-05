/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 16:58:00 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/05 13:49:02 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_make_link(char *line, t_path **list)
{
	t_graph		*room1;
	t_graph		*room2;
	int			ret;

	//if (ft_control_tube_name(*line, *list, &room1, &room2))
	if (ft_control_tube_name(line, *list, &room1, &room2))
	{
		ft_putendl("ft_control_tube_name");
	//	ft_memdel((void **)&(*line));
		return (1);
	}
	ret = ft_link_rooms(room1, room2);
	//ft_memdel((void **)&(*line));
	//ft_gnl(1);
	return (ret);
}

static int	ft_isvalid_cmd(char *line)
{
	int			ret;

	ret = 0;
	//if (!ft_strcmp((*line) + 2, "start") || !ft_strcmp((*line) + 2, "end"))
	if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
		ret = 1;
	//ft_memdel((void **)&(*line));
	return (ret);
}

int			ft_make_links(t_path **list)
{
	char		*line;
	t_rank		rank;
	//int			ret;

	line = (void *)0;
	//if ((ret = gnl(STDIN_FILENO, &line)) != 1)
	if (!(line = ft_gnl(1)) || !(*line))
		return ((!line) ? 1 : 2);
		//return ((ret == 0) ? 2 : 1);
	if ((rank = ft_rank_line(line)) != LINK)
	{
		if (rank == COMMAND || rank == COMMENT)
		{
			if (rank == COMMAND && ft_isvalid_cmd(line))
				return (1);
			//ft_memdel((void **)&line);
			return (0);
		}
		//ft_memdel((void **)&line);
		return (1);
	}
	return (ft_make_link(line, list));
}