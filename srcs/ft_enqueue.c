/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enqueue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:49:00 by lutsiara          #+#    #+#             */
/*   Updated: 2019/05/22 18:41:25 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			ft_enqueue_room(t_path **path, t_path *elem)
{
	if (!(*path))
	{
		*path = elem;
		return (0);
	}
	return (ft_enqueue_room(&((*path)->next), elem));
}

int			ft_enqueue_link(t_links **links, t_links *elem)
{
	if (!(*links))
	{
		*links = elem;
		return (0);
	}
	return (ft_enqueue_link(&((*links)->next), elem));
}

int			ft_enqueue_path(t_ctnl **paths, t_ctnl *elem)
{
	if (!(*paths))
	{
		*paths = elem;
		return (0);
	}
	return (ft_enqueue_path(&((*paths)->next), elem));
}
