/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ff_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:51:05 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/08 19:52:27 by lutsiara         ###   ########.fr       */
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

int				ft_push(t_links **list, t_graph *room)
{
	t_links			*elem;

	if (!(elem = ft_alloc_link()))
		return (1);
	if (!(*list) && (elem->room = room))
		return (!(*list = elem));
	elem->room = room;
	elem->next = *list;
	*list = elem;
	return (0);
}

void			ft_recursive_clear(t_var *var, t_matrix *cell)
{
	t_matrix	*go;

	if (!cell)
		return ;
	(*cell).room = (void *)0;
	(*cell).link = (void *)0;
	(*cell).follow = (void *)0;
	(*cell).address = (void *)0;
	// (*cell).value += 1;
	go = (*cell).address_follow;
	(*cell).address_follow = (void *)0;
	ft_recursive_clear(var, go);
}

static int		ft_link_while(t_var *var, t_graph *u_room, unsigned int i_u)
{
	unsigned int	i_v;
	t_links			*iter;

	iter = u_room->links;
	while (iter)
	{
		i_v = ft_return_index(var->visited, iter->room->name, var->nb_rooms);
		if (!var->visited[i_v].value && \
			var->residual_matrix[i_u + 1][i_v + 1].value > 0)
		{
			if (ft_enqueue(&var->file, iter->room))
				return (ft_del_links(&var->file) == 0);
			var->parent[i_v].link = u_room;
			var->visited[i_v].value = 1;
		}
		else if (!var->visited[i_v].value && \
			ft_is_none_else(var, u_room, i_v) && \
			var->residual_matrix[i_v + 1][i_u + 1].value == 1)
		{
			ft_rewind_path(var, i_u, i_v, u_room);
			 if (ft_push(&var->file, iter->room))
			 	return (ft_del_links(&var->file) == 0);
		}
		iter = iter->next;
	}
	return (0);
}

int				ft_ff_bfs(t_var *var, unsigned int s, unsigned int t)
{
	unsigned int	i_u;
	t_graph			*u_room;

	var->parent[s].value = -1;
	var->visited[s].value = 1;
	if (ft_enqueue(&var->file, var->parent[s].room))
		return (0);
	while (var->file)
	{
		u_room = ft_dequeue(&var->file);
		if (u_room == var->end)
		{
			ft_del_links(&var->file);
			break ;
		}
		i_u = ft_return_index(var->parent, u_room->name, var->nb_rooms);
		if (ft_link_while(var, u_room, i_u))
			return (0);
	}
	return (var->visited[t].value == 1);
}
