/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 00:15:18 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/08 00:16:57 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_reset(t_graph *start, unsigned char state)
{
	t_links		*link;

	if (!start)
		return (1);
	link = start->links;
	if ((start->state ^ state) & state)
		return (0);
	start->state ^= state;
	while (link)
	{
		ft_reset(link->room, state);
		link = link->next;
	}
	return (0);
}

int		ft_set(t_graph *start, unsigned char state)
{
	t_links		*link;

	if (!start)
		return (1);
	link = start->links;
	if (start->state & state)
		return (0);
	start->state |= state;
	while (link)
	{
		ft_set(link->room, state);
		link = link->next;
	}
	return (0);
}
