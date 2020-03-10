/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bfs_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:56:08 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 18:11:52 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool			can_traverse(t_tree *tree, t_room *dst)
{
	if (tree->augmentation > 0 && dst->visited)
		return (FALSE);
	if (tree->augmentation == 0 && dst->visited2)
		return (FALSE);
	if (tree->room->prev != NULL && tree->room->prev == dst)
		return (FALSE);
	if (tree->intersection == dst)
		return (FALSE);
	if (tree->intersection != NULL
		&& tree->room == tree->intersection
		&& dst != tree->room->next)
	{
		return (FALSE);
	}
	if (tree->room->type == START && dst->prev == tree->room)
		return (FALSE);
	if (dst->type == START)
		return (FALSE);
	return (TRUE);
}

t_bool			in_intersection(t_room *src, t_room *dst)
{
	if (src->next != NULL && src->next == dst)
		return (FALSE);
	if (dst->prev == NULL)
		return (FALSE);
	if (dst->prev == src)
		return (FALSE);
	return (TRUE);
}

t_bool			out_intersection(t_room *src, t_room *dst)
{
	return (src->next != NULL && src->next != dst);
}

t_tree			*go_to_start(t_lem_in *lem_in, t_tree *tree)
{
	t_room	*room;
	t_tree	*res;

	room = tree->parent->room;
	while (room->prev->type != START)
	{
		room = room->prev;
	}
	if (tree->intersection == room)
	{
		return (NULL);
	}
	res = tree_create_child(lem_in, tree, lem_in->start);
	res = tree_create_child(lem_in, res, room);
	res->augmentation++;
	return (res);
}

void			mark_as_visited(t_tree *tree)
{
	if (tree->room->type == STANDARD && tree->room->next == NULL)
	{
		if (tree->augmentation > 0)
			tree->room->visited = TRUE;
		else
			tree->room->visited2 = TRUE;
	}
}
