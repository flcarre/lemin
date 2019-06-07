/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_names.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:20:45 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/07 23:42:06 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		stop(char *line, t_graph *room1, t_graph *room2)
{
	char					*s1;
	char					*s2;

	if (!room1 || !room2)
		return (0);
	s1 = room1->name;
	s2 = room2->name;
	while (*s1 && *line && *s1 == *line)
	{
		s1++;
		line++;
	}
	if (!(*line) && *line != '-')
		return (0);
	line++;
	while (*s2 && *line && *s2 == *line)
	{
		s2++;
		line++;
	}
	return (!(*line) && !(*s1) && !(*s2));
}

static int		reset(char *line, t_var *var, unsigned long *len)
{
	int						ret;


	if (var && stop(line, var->room1, var->room2) \
	&& ft_strcmp(var->room1->name, var->room2->name))
		ret = 0;
	else
		ret = 1;
	len[0] = 0;
	len[1] = 0;
	return (ret);
}

int				ft_control_names(char *line, t_var *var)
{
	unsigned long			tmp;
	static unsigned long	len[2] = {0};

	if (!var->ptr || stop(line, var->room1, var->room2))
	{
		if (var->room1 && var->room2)
			return (reset(line, var, len));
		return (reset(line, (void *)0,len));
	}
	tmp = ft_strlen(var->ptr->room->name);
	if (!ft_strncmp(line, var->ptr->room->name, tmp))
	{
			len[0] = (tmp >= len[0]) ? tmp : len[0];
			if (tmp >= len[0])
				var->room1 = var->ptr->room;
	}
	if (!ft_strrevncmp(line, var->ptr->room->name, tmp))
	{
		len[1] = (tmp >= len[1]) ? tmp : len[1];
		if (tmp >= len[1])
			var->room1 = var->ptr->room;
	}
	var->ptr = var->ptr->next;
	return (ft_control_names(line, var));
}
