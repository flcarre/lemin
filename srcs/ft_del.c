/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:14:01 by lutsiara          #+#    #+#             */
/*   Updated: 2019/05/24 20:03:17 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_del_path(t_path **path, unsigned int room)
{
	if (!(*path))
		return (0);
	ft_del_path(&((*path)->next), room);
	if (room)
		ft_del_room(&((*path)->room));
	ft_memdel((void **)&(*path));
	return (0);
}

int			ft_del_container(t_ctnl **paths, unsigned int path)
{
	if (!(*paths))
		return (0);
	ft_del_container(&((*paths)->next), path);
	if (path)
		ft_del_path(&((*paths)->path_box->path), 0);
	ft_memdel((void **)&((*paths)->path_box));
	ft_memdel((void **)&(*paths));
	return (0);
}

int			ft_del_graph(t_graph **graph, t_graph *prev_room)
{
	t_links			*link;

	link = (*graph)->links;
	if ((*graph)->state & 1)
	{
		while (link && link->room != prev_room)
			link = link->next;
		if (link)
			link->room = (void *)0;
		return (0);
	}
	(*graph)->state |= 1;
	while (link)
	{
		if (link->room)
			ft_del_graph(&(link->room), *graph);
		link = link->next;
	}
	ft_del_room(graph);
	return (0);
}

int			ft_del_room(t_graph **room)
{
	ft_memdel((void **)&((*room)->name));
	ft_del_links(&((*room)->links));
	ft_memdel((void **)&(*room));
	return (0);
}

int			ft_del_links(t_links **links)
{
	if (!(*links))
		return (0);
	ft_del_links(&((*links)->next));
	ft_memdel((void **)&(*links));
	return (0);
}
