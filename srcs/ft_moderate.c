/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moderate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 06:04:30 by lutsiara          #+#    #+#             */
/*   Updated: 2019/08/28 17:00:21 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static unsigned int	sum(t_ctn *path, unsigned int n)
{
	if (!n)
		return (0);
	return (n + path->len - 1);
}

static int			isequal(t_var *var, t_min *x, unsigned int *rates)
{
	t_ctn			*ptr;

	ptr = var->travel;
	x->min = 0;
	while (ptr && x->min < var->nb_travel)
	{
		if (x->min != x->i && sum(ptr, ptr->ants) > rates[x->i])
			return (0);
		ptr = ptr->next;
		x->min++;
	}
	return (1);
}

static void			add(t_var *var, t_min *x, unsigned int *rates)
{
	t_ctn			*ptr;

	ptr = var->travel;
	x->i = 0;
	while (ptr && x->i < var->nb_travel && x->sum < var->nb_ants)
	{
		ptr->ants += 1;
		x->sum++;
		rates[x->i++] = sum(ptr, ptr->ants);
		ptr = ptr->next;
	}
}

static void			distrib(t_ctn *ants, t_var *var)
{
	t_min			i;

	i.travel = var->travel;
	i.sum = 0;
	i.min = 0;
	while (i.travel && i.min < var->nb_travel)
	{
		i.i = 0;
		while (i.travel->ants > i.i)
		{
			ants[i.sum + i.i].path = i.travel->path;
			i.i++;
		}
		i.sum += i.i;
		i.min++;
		i.travel = i.travel->next;
	}
}

void				ft_moderate(t_var *var, t_ctn *ants)
{
	t_ctn			*ptr;
	unsigned int	*rates;
	t_min			x;

	ft_bzero((void *)&x, sizeof(t_min));
	if (!(rates = ft_memalloc(sizeof(unsigned int) * var->nb_travel)))
		return ;
	while (var->travel->path->next->room == var->end && x.sum++ < var->nb_ants)
		var->travel->ants++;
	while (x.sum < var->nb_ants)
	{
		add(var, &x, rates);
		x.i = 0;
		ptr = var->travel;
		while (ptr && x.i < var->nb_travel && x.sum < var->nb_ants)
		{
			while (!isequal(var, &x, rates) && x.sum++ < var->nb_ants)
				rates[x.i] = sum(ptr, ++ptr->ants);
			x.i++;
			ptr = ptr->next;
		}
	}
	distrib(ants, var);
	ft_memdel((void **)&rates);
}
