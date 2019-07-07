/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_travel_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:09:11 by lutsiara          #+#    #+#             */
/*   Updated: 2019/07/07 19:09:06 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ctn		*ft_pop_ant(t_ctn **stack)
{
	t_ctn			*ant;
	t_ctn			*head;

	if (!(*stack))
		return ((void *)0);
	head = *stack;
	*stack = (*stack)->next;
	ant = head->ant;
	ft_memdel((void **)&head);
	return (ant);
}

int			ft_enqueue_ant(t_ctn **stack, t_ctn *ant)
{
	t_ctn			*elem;
	t_ctn			**i;

	if (!(elem = ft_alloc_ctn_elem()))
		return (1);
	elem->ant = ant;
	if (!(*stack) && (*stack = elem))
		return (0);
	i = stack;
	while (*i)
		i = &(*i)->next;
	*i = elem;
	return (0);
}

int			ft_repush_ants(t_var *var, t_ctn *ants)
{
	unsigned int	i;

	i = 0;
	while (i < var->nb_ants)
	{
		if (ants[i].path && (ants[i].path->room->state & 2))
		{
			if (ft_enqueue_ant(&var->ants, &ants[i]))
				return (1);
		}
		i++;
	}
	return (0);
}
