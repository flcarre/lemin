/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:41:27 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/15 22:17:26 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parse_ants_count(t_lem_in *lem_in, char **line)
{
	int i;

	i = 0;
	if ((i = gnl(lem_in, 0, line)) != -1)
	{
		if (ft_strlen(*line) <= MAX_NB_SIZE
			&& (i = parse_number_safe(*line)) > 0)
			lem_in->total_ants = i;
		else
		{
			ft_strdel(line);
			lem_in_error();
		}
		ft_strdel(line);
	}
	else
		lem_in_error();
}

int		read_room_line(t_lem_in *lem_in, char **line, t_roomtype type)
{
	if (gnl(lem_in, 0, line) == -1)
		lem_in_error();
	parse_room(lem_in, *line, type);
	return (1);
}

void	parse_rooms(t_lem_in *lem_in, char **line)
{
	int		state;

	while ((state = gnl(lem_in, 0, line)) != -1)
	{
		if (parse_is_link(*line))
		{
			break ;
		}
		if (ft_strnequ("##", *line, 2))
		{
			if (ft_strequ("##start", *line))
				read_room_line(lem_in, line, START);
			else if (ft_strequ("##end", *line))
				read_room_line(lem_in, line, END);
		}
		else
		{
			parse_room(lem_in, *line, STANDARD);
		}
	}
	if (state == -1 || lem_in->start == NULL || lem_in->end == NULL)
		lem_in_error();
}

void	parse_links(t_lem_in *lem_in, char **line)
{
	while (1)
	{
		if (!parse_is_link(*line))
		{
			ft_strdel(line);
			break ;
		}
		parse_link(lem_in, line);
		if (gnl(lem_in, 0, line) == -1)
		{
			lem_in_error();
		}
	}
	ft_strdel(line);
	if (lem_in->start->links == 0 || lem_in->end->links_count == 0)
		lem_in_error();
}
