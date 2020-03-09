/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edmonds_karp_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:50:05 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/09 13:55:24 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_matrix		**ft_alloc_matrix(unsigned int size)
{
	t_matrix		**matrix;
	t_matrix		**row;
	unsigned int	i_matrix;

	matrix = (void *)0;
	row = (void *)0;
	i_matrix = 0;
	if (!(matrix = (t_matrix **)ft_memalloc(sizeof(t_matrix *) * (1 + size))))
		return ((void *)0);
	while (i_matrix <= size)
	{
		row = &matrix[i_matrix];
		if (!(*row = (t_matrix *)ft_memalloc(sizeof(t_matrix) * (1 + size))))
			return (ft_freematrix(&matrix, i_matrix));
		i_matrix++;
	}
	return (matrix);
}

void			*ft_freematrix(t_matrix ***matrix, unsigned int limit)
{
	unsigned int	iterator;

	iterator = 0;
	while (iterator < limit)
	{
		ft_memdel((void **)&(*matrix)[iterator]);
		iterator++;
	}
	ft_memdel((void **)&(*matrix));
	return ((void *)0);
}

unsigned int	ft_return_index(t_matrix *array, char *name, \
				unsigned int size)
{
	unsigned int	iterator;

	iterator = 0;
	while (iterator < size)
	{
		if (!ft_strcmp(array[iterator].room->name, name))
			return (iterator);
		iterator++;
	}
	return (0);
}

int				ft_build_ek_path(t_var *var, t_ctn **paths, t_matrix *cell_to)
{
	t_ctn			*path;
	unsigned char	end;

	if (!(path = ft_alloc_ctn_elem()))
		return (1);
	if (ft_add(var, var->end, path))
		return (!ft_del_ctn(&path));
	end = 0;
	while (cell_to && !end)
	{
		if (ft_add(var, (*cell_to).room, path))
			return (!ft_del_ctn(&path));
		if ((*cell_to).link != var->start && \
			(cell_to = ft_return_next_room(var, cell_to)))
			;
		else if ((*cell_to).link == var->start)
			end = 1;
	}
	if (!end || ft_add(var, var->start, path))
		return (!ft_del_ctn(&path));
	++var->nb_bfs;
	ft_order_path(paths, path);
	return (0);
}

int				ft_build_ek_paths(t_ctn **paths, t_var *var)
{
	unsigned int	i_to;
	unsigned int	i_from;
	t_links			*i_link;
	t_matrix		*cell_to;

	i_link = var->end->links;
	i_from = ft_return_index(var->parent, var->end->name, var->nb_rooms);
	while (i_link)
	{
		i_to = ft_return_index(var->parent, i_link->room->name, var->nb_rooms);
		cell_to = &var->residual_matrix[i_to + 1][i_from + 1];
		if ((*cell_to).follow == var->end)
			if (ft_build_ff_path(var, paths, cell_to))
				return (1);
		i_link = i_link->next;
	}
	return (0);
}
