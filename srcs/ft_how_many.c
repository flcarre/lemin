/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_how_many.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:37:48 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/24 18:38:32 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static unsigned int	ft_sum(t_var *var, unsigned int n, unsigned int i)
{
	unsigned int	ret;
	t_ctn			*elem;

	if (!n)
		return (0);
	ret = 0;
	elem = var->paths;
	while (i--)
	{
		ret += n + elem->len - 1;
		elem = elem->next;
	}
	return (ret);
}

unsigned int		ft_how_many(t_var *var)
{
	unsigned int	min;
	unsigned int	sum;
	unsigned int	ret;
	unsigned int	i;

	if (!var->start->nb_ants)
		return (0);
	min = 0;
	ret = 0;
	i = var->nb_path;
	while (i)
	{
		sum = ft_sum(var, var->start->nb_ants / i, i) / i;
		if (!min || (sum && min > sum))
		{
			min = sum;
			ret = i;
		}
		i--;
	}
	return (ret);
}
