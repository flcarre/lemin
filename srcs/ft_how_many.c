/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_how_many.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:37:48 by lutsiara          #+#    #+#             */
/*   Updated: 2019/08/27 04:24:38 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

unsigned int	ft_how_many(t_var *var, unsigned int *x, unsigned char m)
{
	t_min			min;

	ft_bzero((void *)&min, sizeof(t_min));
	min.save = var->cycle;
	min.i = (!m) ? var->nb_path : var->nb_bfs;
	min.travel = (!m) ? var->paths : var->bfs;
	while (min.i)
	{
		ft_cyclecount(var, &min);
		if (!min.min_cycle || min.min_cycle > var->cycle)
		{
			min.min_cycle = var->cycle;
			if (x)
				*x = min.min_cycle;
			min.ret = min.i;
		}
		var->cycle = 0;
		var->end->nb_ants = 0;
		var->start->nb_ants = var->nb_ants;
		min.i--;
	}
	var->cycle = min.save;
	return (min.ret);
}
