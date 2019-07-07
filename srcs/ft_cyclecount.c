/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cyclecount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 20:36:20 by lutsiara          #+#    #+#             */
/*   Updated: 2019/07/07 20:03:04 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	send(t_path **ants, t_var *var, t_min *min, int reset)
{
	t_ctn				*ptr;
	t_path				*next;
	unsigned int		i;
	static unsigned int	r = 0;

	if (reset)
	{
		r = 0;
		return ;
	}
	i = 0;
	ptr = min->travel;
	next = ptr->path->next;
	while (i < min->i && i < var->start->nb_ants && r < var->nb_ants)
	{
		if (r < var->nb_ants && !(next->room->state & 2))
			ants[r++] = ptr->path;
		while (next->room == var->end && r < var->start->nb_ants \
		&& (i = var->start->nb_ants))
			ants[r++] = ptr->path;
		ptr = ptr->next;
		i++;
	}
}

static void	moving(t_path **ants, t_var *var, unsigned int i, unsigned char m)
{
	if (!ants[i])
		return ;
	if (ants[i]->room != var->end)
		ants[i]->room->nb_ants--;
	if (ants[i]->room != var->start && ants[i]->room != var->end)
		ants[i]->room->state ^= 2;
	ants[i] = ants[i]->next;
	if (ants[i] && ++ants[i]->room->nb_ants && ants[i]->room != var->end)
		ants[i]->room->state ^= 2;
	if (m & 2)
		moving(ants, var, i, 0);
}

static void	move(t_path **ants, t_var *var)
{
	unsigned int		i;
	unsigned char		space;

	space = 0;
	i = 0;
	while (i < var->nb_ants)
	{
		if (ants[i] && ants[i]->room == var->start)
			space ^= 2;
		moving(ants, var, i, space);
		space = 1;
		i++;
	}
	var->cycle++;
}

static int	done(t_path **ants, t_var *var)
{
	unsigned int		i;

	i = 0;
	while (i < var->nb_ants)
	{
		if (ants[i])
			return (0);
		i++;
	}
	return (1);
}

int			ft_cyclecount(t_var *var, t_min *min)
{
	t_path				**ants;

	if (!(ants = (t_path **)ft_memalloc(sizeof(t_path *) * (var->nb_ants + 1))))
		return (1);
	send(ants, var, min, 0);
	move(ants, var);
	while (!done(ants, var))
	{
		send(ants, var, min, 0);
		move(ants, var);
	}
	send(ants, var, min, 1);
	var->start->nb_ants = var->nb_ants;
	var->end->nb_ants = 0;
	ft_memdel((void **)&ants);
	return (0);
}
