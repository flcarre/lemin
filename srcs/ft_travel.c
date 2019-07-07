/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_travel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 20:36:20 by lutsiara          #+#    #+#             */
/*   Updated: 2019/07/07 22:19:23 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	send(t_ctn *ants, t_var *var)
{
	unsigned int		i;

	i = 0;
	while (i < var->nb_ants)
	{
		if (ants[i].path && ants[i].path->next \
		&& !(ants[i].path->next->room->state & 2) \
		&& !(ants[i].path->room->state & 2))
		{
			if (ants[i].path->room == var->start)
			{
				ants[i].id_ant = i + 1;
				if (ants[i].path->next->room != var->end)
					ants[i].path->next->room->state ^= 2;
			}
			if (ft_enqueue_ant(&var->ants, &ants[i]))
				return (1);
		}
		else if (ants[i].path && ants[i].path->room == var->end)
			if (ft_enqueue_ant(&var->ants, &ants[i]))
				return (1);
		i++;
	}
	return (0);
}

static void	moving(t_ctn *ant, t_var *var, unsigned char m)
{
	if (!ant->path)
		return ;
	if (ant->path->room != var->end)
		ant->path->room->nb_ants--;
	if (ant->path->room != var->start && ant->path->room != var->end)
		ant->path->room->state ^= 2;
	ant->path = ant->path->next;
	if (ant->path && ++ant->path->room->nb_ants && ant->path->room != var->end)
		ant->path->room->state ^= (((ant->path->room->state ^ 2) & 2)) ? 2 : 0;
	if (m & 2)
	{
		ft_printf("L%u-%s", ant->id_ant, ant->path->room->name);
		moving(ant, var, 0);
	}
}

static int	move(t_ctn *ants, t_var *var)
{
	unsigned char	space;
	t_ctn			*ant;

	space = 0;
	while (var->ants)
	{
		ant = ft_pop_ant(&var->ants);
		if (space == 1)
			ft_putchar(' ');
		if (ant->path->room != var->start)
			ft_printf("L%u-%s", ant->id_ant, ant->path->room->name);
		else
			space ^= 2;
		moving(ant, var, space);
		space = 1;
	}
	if (ft_repush_ants(var, ants))
		return (1);
	ft_putchar('\n');
	var->cycle++;
	return (0);
}

static int	done(t_ctn *ants, t_var *var)
{
	unsigned int	i;

	i = 0;
	while (i < var->nb_ants)
	{
		if (ants[i].path)
			return (0);
		i++;
	}
	return (1);
}

int			ft_travel(t_var *var)
{
	t_ctn			*ants;

	if (!(ants = (t_ctn *)ft_memalloc(sizeof(t_ctn) * var->nb_ants)))
		return (1);
	ft_moderate(var, ants);
	if (send(ants, var) || move(ants, var))
		return (1);
	while (!done(ants, var))
	{
		if (send(ants, var) || move(ants, var))
			return (1);
	}
	ft_memdel((void **)&ants);
	return (0);
}
