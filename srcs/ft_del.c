/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 00:31:30 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/09 14:02:10 by lutsiara         ###   ########.fr       */
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

int			ft_del_ctn(t_ctn **paths)
{
	if (!(*paths))
		return (0);
	ft_del_ctn(&((*paths)->next));
	ft_del_path(&((*paths)->path), 0);
	ft_memdel((void **)&(*paths));
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
	if (!(*links))
		return (0);
	ft_del_links(&((*links)->next));
	ft_memdel((void **)&(*links));
	return (0);
}

int			ft_del(t_var *var)
{
	ft_del_ctn(&var->paths);
	ft_del_path(&var->queue, 1);
	return (0);
}
