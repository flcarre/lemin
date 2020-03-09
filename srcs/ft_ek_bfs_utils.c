/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ek_bfs_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:30:30 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/09 17:26:34 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_fill_parent(t_var *var, int with)
{
	t_path			*i_queue;
	unsigned int	iterator_size;

	i_queue = var->queue;
	iterator_size = 0;
	while (iterator_size < var->nb_rooms)
	{
		var->parent[iterator_size].value = with;
		iterator_size++;
	}
}

unsigned int	ft_return_index_matrix(t_matrix *array, char *name, \
				unsigned int size)
{
	unsigned int	iterator;

	iterator = 1;
	while (iterator <= size)
	{
		if (!ft_strcmp(array[iterator].room->name, name))
			return (iterator);
		iterator++;
	}
	return (0);
}
