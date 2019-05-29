/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enqueue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:49:00 by lutsiara          #+#    #+#             */
/*   Updated: 2019/05/29 18:17:12 by lutsiara         ###   ########.fr       */
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

int			ft_enqueue_link(t_links **links, t_links *elem)
{
	if (!elem)
		return (1);
	if (!(*links))
	{
		*links = elem;
		return (0);
	}
	return (ft_enqueue_link(&((*links)->next), elem));
}

int			ft_enqueue_path(t_ctnl **paths, t_ctnl *elem)
{
	if (!elem)
		return (1);
	if (!(*paths))
	{
		*paths = elem;
		return (0);
	}
	return (ft_enqueue_path(&((*paths)->next), elem));
}
