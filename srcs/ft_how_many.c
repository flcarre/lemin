/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_how_many.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:37:48 by lutsiara          #+#    #+#             */
/*   Updated: 2019/07/02 21:57:15 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static unsigned int	ft_sum(t_ctn *paths, unsigned int n, unsigned int i)
{
	unsigned int	ret;
	t_ctn			*elem;

	if (!n)
		return (0);
	ret = 0;
	elem = paths;
	while (i--)
	{
		ret += n + elem->len - 1;
		elem = elem->next;
	}
	return (ret);
}

unsigned int		ft_how_many(t_var *var, unsigned int *x, unsigned char m)
{
	unsigned int	min;
	unsigned int	sum;
	unsigned int	ret;
	unsigned int	i;

	if (!var->start->nb_ants)
		return (0);
	min = 0;
	ret = 0;
	i = (!m) ? var->nb_path : var->nb_bfs;
	while (i)
	{
		if (!m)
			sum = ft_sum(var->paths, var->start->nb_ants / i, i) / i;
		else
			sum = ft_sum(var->bfs, var->start->nb_ants / i, i) / i;
		if (!min || (sum && min > sum))
		{
			min = sum;
			*x = min;
			ret = i;
		}
		i--;
	}
	return (ret);
}
