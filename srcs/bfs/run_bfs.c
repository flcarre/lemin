/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:35:28 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 18:12:31 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			reset_visited(t_lem_in *lem_in)
{
	t_glist	*curr;

	curr = lem_in->rooms;
	while (curr != NULL)
	{
		curr->gen.room->visited = FALSE;
		curr->gen.room->visited2 = FALSE;
		curr = curr->next;
	}
}

static t_glist		*init_first_level(t_lem_in *lem_in)
{
	t_glist	*res;
	t_tree	*tree;

	res = NULL;
	tree = tree_new(lem_in);
	tree->room = lem_in->start;
	tree->augmentation = 1;
	ft_glstadd(&res, ft_glstnew(tree, sizeof(t_tree)));
	return (res);
}

t_route				*run_bfs(t_lem_in *lem_in)
{
	t_glist			*nodes;
	t_glist			*next_nodes;
	t_route			*res;

	reset_visited(lem_in);
	nodes = init_first_level(lem_in);
	next_nodes = NULL;
	while (1)
	{
		res = extend_nodes_list(lem_in, nodes, &next_nodes);
		tree_del_list(lem_in, &nodes);
		if (res != NULL)
		{
			tree_del_list(lem_in, &next_nodes);
			return (res);
		}
		if (next_nodes == NULL)
			return (NULL);
		nodes = next_nodes;
		next_nodes = NULL;
	}
}
