/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:33:38 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 17:53:45 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_round(t_lem_in lem_in, t_round *round)
{
	t_dlist		*curr;
	t_move		*move;

	curr = ft_dlstfirst(round->moves);
	while (curr != NULL)
	{
		move = (t_move*)curr->content;
		if (lem_in.opt.print_route == TRUE)
			ft_printf("R%d:L%d-%s", move->id_route, move->ant_id,
				move->dst->name);
		else
			ft_printf("L%d-%s", move->ant_id, move->dst->name);
		if ((curr = curr->prev) != NULL)
			ft_putchar(' ');
	}
	ft_putendl("");
}

void		solution_print(t_lem_in lem_in, t_solution *solution)
{
	t_dlist	*curr;

	curr = ft_dlstfirst(solution->rounds);
	while (curr != NULL)
	{
		print_round(lem_in, (t_round*)curr->content);
		curr = curr->prev;
	}
	if (lem_in.opt.print_nblines == TRUE)
		ft_printf("\n#-> Number of line written :%d \n", solution->round);
}
