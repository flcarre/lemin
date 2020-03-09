/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ek_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:51:05 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/09 13:53:41 by lutsiara         ###   ########.fr       */
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

t_matrix	*ft_return_next_room(t_var *var, t_matrix *cell)
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

int				ft_ek_bfs(t_var *var, unsigned int s, unsigned int t)
{
	return (0);
}
