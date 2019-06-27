/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 00:31:30 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/27 02:28:05 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_del_path(t_path **path, unsigned int room)
{
	t_path			*elem;
	t_path			*del;

	elem = *path;
	while (elem)
	{
		del = elem;
		elem = elem->next;
		if (room)
			ft_del_room(&(del->room));
		ft_memdel((void **)&del);
	}
	return (0);
}

int			ft_del_ctn(t_ctn **paths)
{
	t_ctn			*elem;
	t_ctn			*del;

	if (!(*paths))
		return (0);
	elem = *paths;
	while (elem)
	{
		del = elem;
		elem = elem->next;
		ft_del_path(&(del->path), 0);
		ft_memdel((void **)&del);
	}
	*paths = (void *)0;
	return (0);
}

int			ft_del_room(t_graph **room)
{
	if (!(*room))
		return (0);
	ft_del_links(&((*room)->links));
	ft_memdel((void **)&(*room));
	return (0);
}

int			ft_del_links(t_links **links)
{
	t_links			*elem;
	t_links			*del;

	elem = *links;
	while (elem)
	{
		del = elem;
		elem = elem->next;
		ft_memdel((void **)&del);
	}
	return (0);
}

int			ft_del(t_var *var)
{
	unsigned long	i;

	i = 0;
	while (i < SIZE_HASH_TABLE)
		ft_del_links(&var->hash_name[i++]);
	ft_memdel((void **)&var->hash_name);
	i = 0;
	while (i < SIZE_HASH_TABLE)
		ft_del_links(&var->hash_addr[i++]);
	ft_memdel((void **)&var->hash_addr);
	ft_del_ctn(&var->paths);
	ft_del_ctn(&var->bfs);
	ft_del_path(&var->queue, 1);
	return (0);
}
