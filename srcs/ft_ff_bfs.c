/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ff_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:51:05 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/04 16:51:23 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_enqueue(t_links **list, t_graph *room)
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

t_graph	*ft_dequeue(t_links **list)
{
	t_links			*head;
	t_graph			*room;

	if (!(*list))
		return ((void *)0);
	head = *list;
	room = head->room;
	*list = head->next;
	ft_memdel((void **)&head);
	return (room);
}

void	ft_init_visited(t_var *var)
{
	unsigned int	iterator;

	iterator = 0;
	while (iterator < var->nb_rooms)
	{
		var->visited[iterator].value = 0;
		iterator++;
	}
}

void	ft_rewind_path(t_var *var, unsigned int i_u, unsigned int i_v)
{
	t_graph		*u_room;
	t_graph		*v_room;

	u_room = var->residual_matrix[i_u + 1][i_v + 1].link;
	v_room = 
	ft_clear_path_forward(var, i_u, i_v);
	i_u = ft_return_index
}

int		ft_link_while(t_var *var, t_graph *u_room, unsigned int i_u)
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
			var->residual_matrix[i_u + 1][i_v + 1].link && \
			var->residual_matrix[i_u + 1][i_v + 1].follow)
			ft_rewind_path(var, i_u, i_v);
		iter = iter->next;
	}
	return (0);
}

int		ft_ff_bfs(t_var *var, unsigned int s, unsigned int t)
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
			continue ;
		i_u = ft_return_index(var->parent, u_room->name, var->nb_rooms);
		if (ft_link_while(var, u_room, i_u))
			return (0);
	}
	return (var->visited[t].value == 1);
}
