/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:13:04 by lutsiara          #+#    #+#             */
/*   Updated: 2019/10/19 18:31:45 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_link_rooms(t_var *var)
{
	t_links		*link;

	if (!(link = ft_alloc_link()))
		return (1);
	link->room = var->room2;
	var->room2->nb_links += 1;
	ft_push_link(&var->room1->links, link);
	if (!(link = ft_alloc_link()))
		return (1);
	link->room = var->room1;
	var->room1->nb_links += 1;
	ft_push_link(&var->room2->links, link);
	return (0);
}

int			ft_make_link(char *line, t_var *var)
{
	int			ret;

	var->ptr = var->queue;
	if (ft_control_names(line, var))
		return (1);
	ret = ft_link_rooms(var);
	var->room1 = (void *)0;
	var->room2 = (void *)0;
	return (ret);
}

int			ft_make_links(t_var *var)
{
	char		*line;
	t_rank		rank;

	line = (void *)0;
	if (!(line = ft_gnl(1)) || !(*line))
		return ((!line) ? 1 : 2);
	if ((rank = ft_rank_line(line)) != LINK)
	{
		if (rank == COMMAND || rank == COMMENT)
		{
			if (rank == COMMAND && ft_isvalidcmd(line))
				return (1);
			return (0);
		}
		return (1);
	}
	return (ft_make_link(line, var));
}
