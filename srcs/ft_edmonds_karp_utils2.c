/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edmonds_karp_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:44:01 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/09 17:12:09 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_init_visited(t_var *var)
{
	unsigned int	iterator;

	iterator = 0;
	while (iterator < var->nb_rooms)
	{
		var->visited[iterator].value = 0;
		var->parent[iterator].link = (void *)0;
		iterator++;
	}
}

void			ft_fill_matrix(t_matrix **matrix, t_graph *parent, \
				unsigned int size)
{
	t_links			*link;
	unsigned int	i_row_matrix;
	unsigned int	i_column_marix;

	i_row_matrix = 0;
	i_column_marix = 0;
	if (parent->state & 1)
		return ;
	link = parent->links;
	parent->state |= 1;
	i_row_matrix = ft_return_index_matrix(matrix[0], parent->name, size);
	while (link)
	{
		i_column_marix = \
		ft_return_index_matrix(matrix[0], link->room->name, size);
		matrix[i_row_matrix][i_column_marix].value = 1;
		matrix[i_row_matrix][i_column_marix].room = link->room;
		ft_fill_matrix(matrix, link->room, size);
		link = link->next;
	}
}

t_matrix		**ft_build_matrix(t_var *var, unsigned int size)
{
	t_matrix		**matrix;
	t_path			*i_queue;
	unsigned int	iterator_size;

	if (!(matrix = ft_alloc_matrix(size)))
		return ((void *)0);
	i_queue = var->queue;
	iterator_size = 1;
	while (i_queue && iterator_size <= size)
	{
		matrix[0][iterator_size].room = i_queue->room;
		matrix[iterator_size][0].room = i_queue->room;
		i_queue = i_queue->next;
		iterator_size++;
	}
	ft_fill_matrix(matrix, var->start, var->nb_rooms);
	ft_reset(var, 1);
	return (matrix);
}

t_matrix		*ft_build_array(t_var *var, unsigned int size)
{
	t_matrix		*array;
	t_path			*i_queue;
	unsigned int	iterator_size;

	if (!(array = (t_matrix *)ft_memalloc(sizeof(t_matrix) * size)))
		return ((void *)0);
	i_queue = var->queue;
	iterator_size = 0;
	while (i_queue && iterator_size < size)
	{
		array[iterator_size].room = i_queue->room;
		i_queue = i_queue->next;
		iterator_size++;
	}
	return (array);
}
