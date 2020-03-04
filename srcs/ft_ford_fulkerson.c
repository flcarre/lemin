/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ford_fulkerson.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:34:46 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/03 14:16:31 by lutsiara         ###   ########.fr       */
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
	i_row_matrix = ft_return_matrix_index(matrix, parent->name, size);
	while (link)
	{
		i_column_marix = ft_return_matrix_index(matrix, link->room->name, size);
		matrix[i_row_matrix][i_column_marix].value = 1;
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
	iterator_size = 1;
	while (i_queue && iterator_size < size)
	{
		array[iterator_size].room = i_queue->room;
		i_queue = i_queue->next;
		iterator_size++;
	}
	return (array);
}

void			*ft_alloc_some_var(t_var * var)
{
	if (!(var->residual_matrix = ft_build_matrix(var, var->nb_rooms)))
		return ((void *)0);
	if (!(var->parent = ft_build_array(var, var->nb_rooms)))
		return (ft_free_some_var(var));
	if (!(var->visited = ft_build_array(var, var->nb_rooms)))
		return (ft_free_some_var(var));
}

void			*ft_free_some_var(t_var *var)
{
	if (var->residual_matrix)
		ft_freematrix(&var->residual_matrix, var->nb_rooms + 1);
	if (var->visited)
		ft_memdel((void **)&var->visited);
	if (var->parent)
		ft_memdel((void **)&var->parent);
	return ((void *)0);
}

void			ft_update_residual_matrix(t_var *var)
{
	unsigned int	i_v;
	unsigned int	i_u;
	t_graph			*v_room;
	t_graph			*u_room;

	v_room = var->end;
	while (v_room)
	{
		i_v = ft_return_index(var->parent, v_room->name, var->nb_rooms);
		u_room = var->parent[i_v].link;
		i_u = ft_return_index(var->parent, u_room->name, var->nb_rooms);
		var->residual_matrix[i_u][i_v].value -= 1;
		var->residual_matrix[i_v][i_u].value += 1;
		v_room = var->parent[i_v].link;
	}
}

t_ctn			*ft_ford_fulkerson(t_var *var)
{
	t_ctn		*paths;

	paths = (void *)0;
	if (!(ft_alloc_some_var(var)))
		return ((void *)0);
	while (ft_ff_bfs(var))
	{
		ft_init_visited(var);
		ft_update_residual_matrix(var);
		ft_build_path(&paths, var);
	}
	ft_free_some_var(var);
	return (paths);
}