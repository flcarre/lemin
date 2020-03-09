/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ek_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:51:05 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/09 17:26:11 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_enqueue(t_links **list, t_graph *room)
{
	t_links			*elem;
	t_links			**iterator;

	if (!(elem = ft_alloc_link()))
		return (1);
	if (!(*list) && (elem->room = room))
		return (!(*list = elem));
	iterator = list;
	while (*iterator)
		iterator = &(*iterator)->next;
	return (!(*iterator = elem));
}

t_matrix		*ft_return_next_room(t_var *var, t_matrix *cell)
{
	unsigned int	i_row;
	unsigned int	i_col;

	i_row = ft_return_index(var->parent, (*cell).link->name, var->nb_rooms);
	i_col = ft_return_index(var->parent, (*cell).room->name, var->nb_rooms);
	if (var->residual_matrix[i_row + 1][i_col + 1].follow == (*cell).room)
		return (&var->residual_matrix[i_row + 1][i_col + 1]);
	if (var->residual_matrix[i_col + 1][i_row + 1].follow == (*cell).room)
		return (&var->residual_matrix[i_col + 1][i_row + 1]);
	return ((void *)0);
}

static int		ft_minimum(int flow_a, int flow_b)
{
	return ((flow_a > flow_b) ? flow_b : flow_a);
}

static int		ft_link_while(t_var *var, t_graph *cur, \
				int *state, int *new_flow)
{
	unsigned int	i_v;
	unsigned int	i_u;
	t_links			*iter;

	i_u = ft_return_index(var->parent, cur->name, var->nb_rooms);
	iter = cur->links;
	while (iter)
	{
		i_v = ft_return_index(var->visited, iter->room->name, var->nb_rooms);
		if (var->parent[i_v].value == -1 && \
			var->residual_matrix[i_u + 1][i_v + 1].value > 0)
		{
			var->parent[i_v].link = cur;
			*new_flow = \
			ft_minimum(cur->flow, var->residual_matrix[i_u + 1][i_v + 1].value);
			if (iter->room == var->end)
				return (!(*state = 1));
			iter->room->flow = *new_flow;
			if (ft_enqueue(&var->file, iter->room))
				return (ft_del_links(&var->file) == 0);
		}
		iter = iter->next;
	}
	return (0);
}

int				ft_ek_bfs(t_var *var, unsigned int s, unsigned int t)
{
	t_graph			*cur;
	int				new_flow;
	int				state;

	(void)t;
	ft_fill_parent(var, -1);
	var->parent[s].value = -2;
	var->parent[s].room->flow = INF;
	if (ft_enqueue(&var->file, var->parent[s].room))
		return (0);
	while (var->file)
	{
		state = 0;
		cur = ft_dequeue(&var->file);
		if (ft_link_while(var, cur, &state, &new_flow))
			return (0);
		if (state)
			return (new_flow);
	}
	return (0);
}
