/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 16:11:24 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/04 17:13:36 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_reset(t_graph *graph, unsigned char state)
{
	t_links			*link;

	if (!graph)
		return (1);
	link = graph->links;
	if ((graph->state ^ state) & state)
		return (0);
	graph->state ^= state;
	while (link)
	{
		ft_reset(link->room, state);
		link = link->next;
	}
	return (0);
}

int		ft_set(t_graph *graph, unsigned char state)
{
	t_links			*link;

	if (!graph)
		return (1);
	link = graph->links;
	if (graph->state & state)
		return (0);
	graph->state |= state;
	while (link)
	{
		ft_set(link->room, state);
		link = link->next;
	}
	return (0);
}
