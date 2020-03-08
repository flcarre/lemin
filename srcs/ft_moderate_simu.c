/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moderate_simu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 06:04:30 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/04 11:32:54 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static unsigned int	sum(t_ctn *path, unsigned int n)
{
	if (!n)
		return (0);
	return (n + path->len - 1);
}

static int			isequal(t_min *x, t_min *min, unsigned int *rates)
{
	t_ctn			*ptr;

	ptr = min->travel;
	x->min = 0;
	while (ptr && x->min < min->i)
	{
		if (x->min != x->i && sum(ptr, ptr->ants) > rates[x->i])
			return (0);
		x->min++;
		ptr = ptr->next;
	}
	return (1);
}

static void			add(t_var *var, t_min *x, t_min *min, unsigned int *rates)
{
	t_ctn			*ptr;

	ptr = min->travel;
	x->i = 0;
	while (ptr && x->i < min->i && x->sum < var->nb_ants)
	{
		ptr->ants += 1;
		x->sum++;
		rates[x->i++] = sum(ptr, ptr->ants);
		ptr = ptr->next;
	}
}

static void			distrib(t_ctn *ants, t_min *min)
{
	t_min			i;

	i.travel = min->travel;
	i.sum = 0;
	i.min = 0;
	while (i.travel && i.min < min->i)
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

void				ft_moderate_simu(t_var *var, t_ctn *ants, t_min *min)
{
	t_ctn			*ptr;
	unsigned int	*rates;
	t_min			x;

	ft_bzero((void *)&x, sizeof(t_min));
	if (!(rates = ft_memalloc(sizeof(unsigned int) * min->i)))
		return ;
	while (min->travel->path->next->room == var->end && x.sum++ < var->nb_ants)
		min->travel->ants++;
	while (x.sum < var->nb_ants)
	{
		add(var, &x, min, rates);
		x.i = 0;
		ptr = min->travel;
		while (ptr && x.i < min->i && x.sum < var->nb_ants)
		{
			while (!isequal(&x, min, rates) && x.sum++ < var->nb_ants)
				rates[x.i] = sum(ptr, ++ptr->ants);
			x.i++;
			ptr = ptr->next;
		}
	}
	distrib(ants, min);
	ft_memdel((void **)&rates);
}