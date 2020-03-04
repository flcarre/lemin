/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ff_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:51:05 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/04 09:46:18 by lutsiara         ###   ########.fr       */
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

int		ft_ff_bfs(t_var *var)
{
	unsigned int	t;
	unsigned int 	s;
	unsigned int	i_v;
	unsigned int	i_u;
	t_graph			*v_room;
	t_graph			*u_room;

	s = ft_return_index(var->visited, var->start->name, var->nb_rooms);
	t = ft_return_index(var->visited, var->end->name, var->nb_rooms);
	while (var->file)
	{
		u_room = ft_get_room(ft_dequeue(&var->file));
		ft_link_while(var);
	}
}