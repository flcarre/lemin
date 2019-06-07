/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 00:11:40 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/08 00:19:52 by lutsiara         ###   ########.fr       */
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

int			ft_checkup(t_var *var)
{
	if (!var->start || !var->end)
		return (1);
	if (!ft_is_there_path(var->start, var->end))
		return (1);
	ft_reset(var->start, 1);
	return (0);
}
