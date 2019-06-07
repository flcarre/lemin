/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enqueue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:49:00 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/07 20:44:17 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_enqueue_room(t_path **path, t_path *elem)
{
	if (!elem)
		return (1);
	if (!(*path))
	{
		*path = elem;
		return (0);
	}
	return (ft_enqueue_room(&((*path)->next), elem));
}

int			ft_push_room(t_path **path, t_path *elem)
{
	t_path		*next;

	if (!elem)
		return (1);
	if (!(*path))
	{
		*path = elem;
		return (0);
	}
	next = *path;
	elem->next = next;
	*path = elem;
	return (0);
}

int			ft_push_link(t_links **links, t_links *elem)
{
	t_links		*next;

	if (!elem)
		return (1);
	if (!(*links))
	{
		*links = elem;
		return (0);
	}
	next = *links;
	elem->next = next;
	*links = elem;
	return (0);
}

int			ft_push_path(t_ctn **paths, t_ctn *elem)
{
	t_ctnl		*next;

	if (!elem)
		return (1);
	if (!(*paths))
	{
		*paths = elem;
		return (0);
	}
	next = *paths;
	elem->next = next;
	*paths = elem;
	return (0);
}
