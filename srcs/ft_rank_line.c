/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rank_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:30:21 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/07 19:41:38 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_isaname(char *line)
{
	if (!line || *line == 'L' || *line == '#')
		return (0);
	while (*line && *line != '-' && *line != ' ')
		line++;
	if (!(*line) || *line == '-')
		return (0);
	return (1);
}

static int		ft_isalink(char *line)
{
	if (!line || *line == 'L' || *line == '#')
		return (0);
	while (*line && *line != '-' && *line != ' ')
		line++;
	if (!(*line) || *line == ' ')
		return (0);
	if (*line == '-')
		line++;
	if (*line == 'L' || *line == '#')
		return (0);
	while (*line && *line != '-' && *line != ' ')
		line++;
	if (*line == '-' || *line == ' ')
		return (0);
	return (1);
}

static t_rank	ft_next(char *line)
{
	if (ft_isalink(line))
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
		if (*(++line) == '#')
			return (COMMAND);
		return (COMMENT);
	}
	if (ft_isaname(line) && (tmp = ft_strchr(line, ' ')))
	{
		if (*(++tmp) == '-')
			tmp++;
		while (*tmp && ft_isdigit((int)*tmp))
			tmp++;
		if (!(*tmp) || *(tmp++) != ' ')
			return (NOTHING);
		if (*tmp == '-')
			tmp++;
		while (*tmp && ft_isdigit((int)*tmp))
			tmp++;
		if (!(*tmp))
			return (ROOM);
	}
	return (ft_next(line));
}
