/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 00:15:18 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/27 18:10:19 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_reset(t_var *var, unsigned char state)
{
	unsigned int	i;
	t_links			*link;

	i = 0;
	while (i < SIZE_HASH_TABLE)
	{
		link = var->hash_addr[i++];
		while (link)
		{
			if (!((link->room->state ^ state) & state))
				link->room->state ^= state;
			link = link->next;
		}
	}
	return (0);
}

int		ft_set(t_graph *start, unsigned char state)
{
	t_links			*link;

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
