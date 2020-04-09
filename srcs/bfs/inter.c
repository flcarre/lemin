/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:57:17 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/09 17:04:30 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_inter	*inter_new(t_lem_in *lem_in)
{
	t_inter			*res;
	static int		id;

	(void)lem_in;
	res = ft_memalloc(sizeof(t_inter));
	id++;
	return (res);
}

void	inter_del(t_lem_in *lem_in, t_inter *inter)
{
	t_inter	*del;
	t_inter	*curr;

	(void)lem_in;
	curr = inter;
	while (curr != NULL && curr->child_count == 0)
	{
		del = curr;
		if (curr->parent != NULL)
			curr->parent->child_count--;
		curr = curr->parent;
		free(del);
	}
}

t_inter	*inter_create_child(t_lem_in *lem_in, t_inter *parent, t_room *room)
{
	t_inter	*res;

	(void)lem_in;
	res = inter_new(lem_in);
	res->parent = parent;
	res->intersection = parent->intersection;
	res->augmentation = parent->augmentation;
	res->room = room;
	if (parent != NULL)
		parent->child_count++;
	return (res);
}

t_route	*inter_to_route(t_inter *inter)
{
	t_inter	*curr;
	t_route	*res;

	res = route_new();
	curr = inter;
	while (curr != NULL)
	{
		route_add_node(res, curr->room);
		curr = curr->parent;
	}
	return (res);
}
