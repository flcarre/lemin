/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ff_bfs_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:30:30 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/08 18:28:38 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_matrix	*ft_return_next_room(t_var *var, t_matrix *cell)
{
	unsigned int	i_row;
	unsigned int	i_col;

	i_row = ft_return_index(var->parent, (*cell).link->name, var->nb_rooms);
	i_col = ft_return_index(var->parent, (*cell).room->name, var->nb_rooms);
	if (var->residual_matrix[i_row + 1][i_col + 1].follow == (*cell).room)
	{
		// var->residual_matrix[i_col + 1][i_row + 1].value -= 1;
		return (&var->residual_matrix[i_row + 1][i_col + 1]);
	}
	if (var->residual_matrix[i_col + 1][i_row + 1].follow == (*cell).room)
	{
		// var->residual_matrix[i_row + 1][i_col + 1].value -= 1;
		return (&var->residual_matrix[i_col + 1][i_row + 1]);
	}
	return ((void *)0);
}

void		ft_rewind_to_start(t_var *var, t_matrix *cell)
{
	t_matrix		*next_room;
	unsigned int	indice_room;

	// if ((*cell).link == var->start)
	// 	return ;
	if ((next_room = ft_return_next_room(var, cell)))
	{
		indice_room = ft_return_index(var->visited, \
						(*next_room).room->name, var->nb_rooms);
		if (!var->visited[indice_room].value && \
			(*next_room).value < 0)
		{
			// (*next_room).value += 1;
			var->visited[indice_room].value = 1;
			ft_rewind_to_start(var, next_room);
		}
	}
}

void		ft_rewind_path(t_var *var, unsigned int i_u, unsigned int i_v, \
			t_graph *u_room)
{
	t_matrix	*cell;

	if (!(cell = ft_clear_path_forward(var, i_u, i_v)))
		return ;
	var->visited[i_v].value = 1;
	ft_rewind_to_start(var, cell);
	(*cell).link = (void *)0;
	// (*cell).value += 1;
	var->parent[i_v].link = u_room;
}

int			ft_is_none_else(t_var *var, \
			t_graph *current_room, unsigned int indice_next_room)
{
	t_links			*iterator;
	unsigned int	indice;

	iterator = current_room->links;
	while (iterator)
	{
		indice = ft_return_index(var->visited, \
				iterator->room->name, var->nb_rooms);
		if (indice != indice_next_room && !var->visited[indice].value)
			return (0);
		iterator = iterator->next;
	}
	return (1);
}

t_matrix	*ft_clear_path_forward(t_var *var, \
			unsigned int i_u, unsigned int i_v)
{
	t_matrix	*cell;

	if (var->residual_matrix[i_u + 1][i_v + 1].address)
		cell = var->residual_matrix[i_u + 1][i_v + 1].address;
	else
		cell = (void *)0;
	if (cell)
	{
		ft_recursive_clear(var, cell);
		(*cell).address = (void *)0;
		(*cell).address_follow = (void *)0;
		(*cell).follow = (void *)0;
		// (*cell).value += 1;
        // var->residual_matrix[i_v + 1][i_u + 1].value -= 1;
		return (cell);
	}
	return ((void *)0);
}
