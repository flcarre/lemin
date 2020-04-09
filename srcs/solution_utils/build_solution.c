/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:50:22 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 17:31:41 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool		ant_try_move(t_room *src, t_room *dest, t_solution *solution,
	int *ants_for_routes)
{
	int cpt;

	cpt = 0;
	while (src->ants > 0 && ant_can_move(dest))
	{
		if (src->type == START)
		{
			if ((*ants_for_routes) <= 0)
				return (FALSE);
			(*ants_for_routes)--;
			src->ant_id++;
		}
		src->ants--;
		dest->ants++;
		dest->ant_id = src->ant_id;
		solution_add_move(solution, dest);
		cpt++;
	}
	return ((cpt != 0) ? TRUE : FALSE);
}

t_bool		ant_can_move(t_room *room)
{
	if ((room->ants == 0 && room->type == STANDARD) || (room->type == END))
		return (TRUE);
	return (FALSE);
}

static void	run_route(t_lem_in *lem_in, t_route *route, int *ants_for_routes,
	t_solution *solution)
{
	t_glist	*curr;
	t_room	*room_a;
	t_room	*room_b;

	curr = route->rooms;
	while (curr->gen.room != lem_in->start)
	{
		room_a = curr->gen.room;
		room_b = curr->next->gen.room;
		ant_try_move(room_b, room_a, solution, ants_for_routes);
		curr = curr->next;
	}
}

static void	run_round(t_group *group, t_lem_in *lem_in, t_solution *solution)
{
	int		i;

	solution_add_round(solution);
	i = 0;
	while (i < group->route_count)
	{
		solution->route = i;
		run_route(lem_in, group->routes[i], &group->ants_distribution[i],
			solution);
		i++;
	}
}

void		build_solution(t_lem_in *lem_in, t_group *group,
			t_solution *solution)
{
	if (lem_in->opt.print_groups == TRUE)
	{
		ft_fprintf(2, "/===================================/\n");
		group_print(group);
		ft_fprintf(2, "/===================================/\n");
	}
	while ((lem_in->start->ants) >= 0
		&& lem_in->end->ants != lem_in->total_ants)
	{
		run_round(group, lem_in, solution);
	}
}
