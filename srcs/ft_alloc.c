/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:53:35 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/27 08:26:40 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_graph		*ft_alloc_room(void)
{
	t_graph		*elem;

	if (!(elem = (t_graph *)ft_memalloc(sizeof(t_graph))))
		return ((void *)0);
	elem->links = (void *)0;
	elem->state = 0;
	elem->nb_ants = 0;
	elem->nb_links = 0;
	elem->id_ants = 0;
	elem->dist = -1;
	elem->name = (void *)0;
	elem->x = 0;
	elem->y = 0;
	return (elem);
}

t_links		*ft_alloc_link(void)
{
	t_links		*elem;

	if (!(elem = (t_links *)ft_memalloc(sizeof(t_links))))
		return ((void *)0);
	elem->room = (void *)0;
	elem->prev = (void *)0;
	elem->next = (void *)0;
	return (elem);
}

t_path		*ft_alloc_path_elem(void)
{
	t_path		*elem;

	if (!(elem = (t_path *)ft_memalloc(sizeof(t_path))))
		return ((void *)0);
	elem->room = (void *)0;
	elem->next = (void *)0;
	return (elem);
}

t_ctn		*ft_alloc_ctn_elem(void)
{
	t_ctn		*elem;

	if (!(elem = (t_ctn *)ft_memalloc(sizeof(t_ctn))))
		return ((void *)0);
	elem->path = (void *)0;
	elem->len = 0;
	elem->next = (void *)0;
	return (elem);
}
