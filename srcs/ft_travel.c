/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_travel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 20:36:20 by lutsiara          #+#    #+#             */
/*   Updated: 2019/07/03 17:30:06 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	send(t_path **ants, t_var *var)
{
	t_ctn			*ptr;
	t_path			*next;
	unsigned int	i;
	unsigned int	r;

	i = 0;
	ptr = var->travel;
	next = ptr->path->next;
	r = 0;
	while (i < var->nb_travel && i < var->start->nb_ants)
	{
		while (var->cycle && r < var->nb_ants && !ants[r])
			r++;
		while (r < var->nb_ants && ants[r])
			r++;
		if (r < var->nb_ants && !(next->room->state & 2))
			ants[r] = ptr->path;
		while (next->room == var->end && ++r < var->start->nb_ants \
		&& (i = var->start->nb_ants))
			ants[r] = ptr->path;
		ptr = ptr->next;
		i++;
	}
}

static void	moving(t_path **ants, t_var *var, unsigned int i, unsigned char m)
{
	ants[i]->room->nb_ants--;
	if (ants[i]->room != var->start)
		ants[i]->room->state ^= 2;
	ants[i] = ants[i]->next;
	if (ants[i] && ++ants[i]->room->nb_ants && ants[i]->room != var->end)
		ants[i]->room->state ^= 2;
	if (m & 2)
	{
		ft_printf("L%u-%s", i + 1, ants[i]->room->name);
		moving(ants, var, i, 0);
	}
}

static void	move(t_path **ants, t_var *var)
{
	unsigned int	i;
	unsigned char	space;

	space = 0;
	i = 0;
	while (i < var->nb_ants)
	{
		while (i < var->nb_ants && !ants[i])
			i++;
		if (!ants[i])
			break ;
		if (space)
			ft_putchar(' ');
		if (ants[i]->room != var->start)
			ft_printf("L%u-%s", i + 1, ants[i]->room->name);
		else
			space ^= 2;
		moving(ants, var, i, space);
		space = 1;
		i++;
	}
	ft_putchar('\n');
	var->cycle++;
}

static int	done(t_path **ants, t_var *var)
{
	unsigned int	i;

	i = 0;
	while (i < var->nb_ants)
	{
		if (ants[i])
			return (0);
		i++;
	}
	return (1);
}

int			ft_travel(t_var *var)
{
	t_path			**ants;

	if (!(ants = (t_path **)ft_memalloc(sizeof(t_path *) * (var->nb_ants + 1))))
		return (1);
	send(ants, var);
	move(ants, var);
	while (!done(ants, var))
	{
		send(ants, var);
		move(ants, var);
	}
	ft_memdel((void **)&ants);
	return (0);
}
