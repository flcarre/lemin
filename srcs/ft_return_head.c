/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 19:56:01 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/03 16:48:01 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_graph		*ft_return_head(t_path *rooms, unsigned char state)
{
	if (!rooms)
		return ((void *)0);
	if (!rooms->room || !(rooms->room->state & state))
		return (ft_return_head(rooms->next, state));
	return (rooms->room);
}
