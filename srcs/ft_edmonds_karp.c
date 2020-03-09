/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edmonds_karp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:34:46 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/09 13:55:28 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		*ft_free_some_var(t_var *var)
{
	if (var->residual_matrix)
		ft_freematrix(&var->residual_matrix, var->nb_rooms + 1);
	if (var->visited)
		ft_memdel((void **)&var->visited);
	if (var->parent)
		ft_memdel((void **)&var->parent);
	return ((void *)0);
}

static void		*ft_alloc_some_var(t_var *var)
{
	if (!(var->residual_matrix = ft_build_matrix(var, var->nb_rooms)))
		return ((void *)0);
	if (!(var->parent = ft_build_array(var, var->nb_rooms)))
		return (ft_free_some_var(var));
	if (!(var->visited = ft_build_array(var, var->nb_rooms)))
		return (ft_free_some_var(var));
	return ((void *)0);
}

static void		ft_save_address(t_matrix *address, t_graph *prev_room, \
				t_graph *u_room, t_graph *v_room)
{
	(*address).room = v_room;
	(*address).address = address;
	(*address).follow = prev_room;
	(*address).link = u_room;
}

static void		ft_update_residual_matrix(t_var *var, t_graph *v_room)
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
			ft_save_address(address, prev_room, u_room, v_room);
		prev_room = v_room;
		v_room = var->parent[i_v].link;
	}
}

t_ctn			*ft_edmonds_karp(t_var *var)
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
		ft_del_links(&var->file);
		ft_update_residual_matrix(var, var->end);
	}
	if (ft_build_ek_paths(&paths, var) && ft_del_ctn(&paths))
		;
	ft_free_some_var(var);
	return (paths);
}
