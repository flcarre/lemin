/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ford_fulkerson.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:34:46 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/05 14:50:27 by lutsiara         ###   ########.fr       */
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
	i_row_matrix = ft_return_index(matrix[0] + 1, parent->name, size);
	while (link)
	{
		i_column_marix = ft_return_index(matrix[0] + 1, link->room->name, size);
		matrix[i_row_matrix + 1][i_column_marix + 1].value = 1;
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

void			*ft_alloc_some_var(t_var *var)
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

void			ft_save_address(t_matrix *address, \
				t_graph *prev_room, t_graph *u_room)
{
	(*address).address = address;
	(*address).follow = prev_room;
	(*address).link = u_room;
}

void			ft_update_residual_matrix(t_var *var, t_graph *v_room)
{
	unsigned int	i_v;
	unsigned int	i_u;
	t_graph			*prev_room;
	t_graph			*u_room;
	t_matrix		*address;

	prev_room = var->end;
	while (v_room)
	{
		i_v = ft_return_index(var->parent, v_room->name, var->nb_rooms);
		u_room = var->parent[i_v].link;
		i_u = ft_return_index(var->parent, u_room->name, var->nb_rooms);
		var->residual_matrix[i_u + 1][i_v + 1].value -= 1;
		var->residual_matrix[i_v + 1][i_u + 1].value += 1;
		if (v_room != var->start && var->end != v_room)
			var->residual_matrix[i_u + 1][i_v + 1].address_follow = address;
		address = &var->residual_matrix[i_u + 1][i_v + 1];
		if (var->end != v_room && var->start != v_room)
			ft_save_address(address, prev_room, u_room);
		prev_room = v_room;
		v_room = var->parent[i_v].link;
	}
}

t_ctn			*ft_ford_fulkerson(t_var *var)
{
	t_ctn			*paths;
	unsigned int	t;
	unsigned int	s;

	paths = (void *)0;
	if (!(ft_alloc_some_var(var)))
		return ((void *)0);
	s = ft_return_index(var->visited, var->start->name, var->nb_rooms);
	t = ft_return_index(var->visited, var->end->name, var->nb_rooms);
	while (ft_ff_bfs(var, s, t))
	{
		ft_init_visited(var);
		ft_update_residual_matrix(var, var->end);
		ft_build_path(&paths, var);
	}
	ft_free_some_var(var);
	return (paths);
}
