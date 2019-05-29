/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rank_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:30:21 by lutsiara          #+#    #+#             */
/*   Updated: 2019/05/29 16:21:41 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_rank	ft_ants(char *line)
{
	if (ft_strchr((const char *)line, (int)'-'))
		return (LINK);
	while (*line && ft_isdigit((int)*line))
		line++;
	if (!(*line))
		return (NBANTS);
	return (NOTHING);
}

t_rank			ft_rank_line(char *line)
{
	char	*tmp;

	if (*line == '#')
	{
		line++;
		if (*line == '#')
			return (COMMAND);
		return (COMMENT);
	}
	if ((tmp = ft_strchr((const char *)line, (int)' ')))
	{
		if (*(++tmp) == '-')
			tmp++;
		while (*tmp && ft_isdigit((int)*tmp))
			tmp++;
		if (*(tmp++) != ' ')
			return (NOTHING);
		if (*tmp == '-')
			tmp++;
		while (*tmp && ft_isdigit((int)*tmp))
			tmp++;
		if (!(*tmp))
			return (ROOM);
	}
	return (ft_ants(line));
}
