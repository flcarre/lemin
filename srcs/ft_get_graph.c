/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 20:55:46 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/08 00:49:18 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_get_graph(t_var *var)
{
	int	ret;

	if (ft_get_ants(&var->nb_ants))
		return (1);
	while ((ret = ft_create_rooms(var)) <= 1)
		;
	if (ret != 3)
		return (1);
	while (!(ret = ft_make_links(var)))
		;
	if (ret != 2)
		return (1);
	if (ft_checkup(var))
		return (1);
	var->start->nb_ants = var->nb_ants;
	return (0);
}
