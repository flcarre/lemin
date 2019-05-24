/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:14:05 by lutsiara          #+#    #+#             */
/*   Updated: 2019/05/22 16:46:24 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			ft_set_room(t_graph **room, char *name, long x, long y)
{
	char			*tmp;

	if (!(tmp = ft_strchr((const char *)name, (int)' ')))
		return (1);
	*tmp = '\0';
	if (!((*room)->name = ft_strdup((const char *)name)))
		return (1);
	(*room)->x = x;
	(*room)->y = y;
	return (0);
}

int			ft_set_link(t_links **elem, t_graph *room)
{
	(*elem)->room = room;
	return (0);
}

int			ft_set_path_elem(t_path **elem, t_graph *room)
{
	(*elem)->room = room;
	return (0);
}

int			ft_set_container(t_container **box, t_path *path)
{
	t_path			*elem;
	unsigned int	len;

	len = 0;
	elem = path;
	while (elem)
	{
		len++;
		elem = elem->next;
	}
	(*box)->path = path;
	(*box)->len = len;
	return (0);
}

int			ft_set_ctnl(t_ctnl **elem, t_container *box)
{
	(*elem)->path_box = box;
	return (0);
}
