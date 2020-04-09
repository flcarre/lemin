/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bfs_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:56:50 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/09 17:04:30 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_inter	*traverse(t_lem_in *lem_in, t_inter *node, t_room *dst)
{
	t_inter			*res;
	int				augmentation;
	t_room			*intersection;

	if (!can_traverse(node, dst))
		return (NULL);
	augmentation = node->augmentation;
	if (in_intersection(node->room, dst))
	{
		augmentation--;
		if (augmentation < 0)
			return (NULL);
		intersection = dst;
	}
	else if (out_intersection(node->room, dst))
		intersection = NULL;
	else
		intersection = node->intersection;
	res = inter_create_child(lem_in, node, dst);
	res->augmentation = augmentation;
	res->intersection = intersection;
	return (res);
}

t_inter	*traverse_end(t_lem_in *lem_in, t_inter *node)
{
	t_inter	*res;

	if (node->parent->room->next != NULL)
	{
		res = go_to_start(lem_in, node);
		return (res);
	}
	return (NULL);
}

t_route	*try_finalize_traverse(t_inter *node)
{
	if (node->augmentation > 0)
	{
		return (inter_to_route(node));
	}
	return (NULL);
}

t_route	*extend_node(t_lem_in *lem_in, t_inter *node,
	t_glist **next_nodes)
{
	t_glist			*curr;
	t_inter			*new_node;
	t_route			*res;

	new_node = NULL;
	mark_as_visited(node);
	if (node && node->room->type == END)
	{
		if ((res = try_finalize_traverse(node)) != NULL)
			return (res);
		new_node = traverse_end(lem_in, node);
		if (new_node != NULL)
			ft_glstadd(next_nodes, ft_glstnew(new_node, sizeof(t_inter)));
		return (NULL);
	}
	curr = node->room->links;
	while (curr != NULL)
	{
		new_node = traverse(lem_in, node, curr->gen.room);
		if (new_node != NULL)
			ft_glstadd(next_nodes, ft_glstnew(new_node, sizeof(t_inter)));
		curr = curr->next;
	}
	return (NULL);
}

t_route	*extend_nodes_list(t_lem_in *lem_in, t_glist *nodes,
	t_glist **next_nodes)
{
	t_glist		*curr;
	t_route		*res;

	curr = nodes;
	while (curr != NULL)
	{
		if ((res = extend_node(lem_in, curr->gen.inter, next_nodes)))
			return (res);
		curr = curr->next;
	}
	return (NULL);
}
