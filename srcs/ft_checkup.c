/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 00:11:40 by lutsiara          #+#    #+#             */
/*   Updated: 2019/10/19 18:32:13 by lutsiara         ###   ########.fr       */
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
	if (start->state & 1)
		return (0);
	link = start->links;
	start->state |= 1;
	while (link && !ret)
	{
		ret = ft_is_there_path(link->room, end);
		link = link->next;
	}
	return (ret);
}

static void	ft_print_input(void)
{
	char		*line;
	t_rank		t;

	line = ft_gnl(4);
	t = ft_rank_line(line);
	while (t == COMMENT || t == COMMAND)
	{
		ft_printf("%s\n", line);
		line = ft_gnl(1);
		t = ft_rank_line(line);
	}
	ft_printf("%s\n", line);
	while (*line)
	{
		line = ft_gnl(1);
		t = ft_rank_line(line);
		if (t == COMMAND || t == COMMENT || t == LINK)
			ft_printf("%s\n", line);
		else if (*line)
			ft_printf("%s %s\n", line, ft_gnl(1));
	}
	ft_putendl("");
}

static int		init(t_var *var)
{
	t_path	*i;

	i = var->queue;
	while (i)
	{
		if (i->room->state & 4)
			if (ft_push_hash2(var, i->room))
				return (1);
		i = i->next;
	}
	return (0);
}

int			ft_checkup(t_var *var)
{
	if (!var->start || !var->end)
		return (1);
	if (!ft_is_there_path(var->start, var->end))
		return (1);
	ft_print_input();
	var->max_nb_path = (var->end->nb_links < var->start->nb_links) \
	? var->end->nb_links : var->start->nb_links;
	ft_set(var->start, 4);
	if (init(var))
		return (1);
	ft_reset(var, 1);
	return (0);
}
