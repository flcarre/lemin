/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:30:59 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 18:13:11 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			tree_del_list(t_lem_in *lem_in, t_glist **trees)
{
	while ((*trees) != NULL)
	{
		tree_del(lem_in, (*trees)->gen.tree);
		ft_glstdelone(trees, NULL);
	}
}

void			tree_print(t_tree *tree)
{
	if (tree->parent != NULL)
		tree_print(tree->parent);
	ft_fprintf(2, "BFS node [%-6s]\t(augmentation=%d, intersection=%s)\n",
		tree->room->name,
		tree->augmentation,
		tree->intersection != NULL ? tree->intersection->name : NULL);
}
