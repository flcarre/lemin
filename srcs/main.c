/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:41:57 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/10 21:08:29 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(int ac, char **av)
{
	t_lem_in	lem_in;
	t_solution	solution;

	lem_in_init(&lem_in);
	parse_opt(&lem_in, ac, av);
	if (lem_in.opt.print_help == TRUE)
	{
		printf_help();
		return (0);
	}
	parse(&lem_in);
	solution_init(&solution);
	solve(&lem_in, &solution);
	print_output(&lem_in);
	solution_print(lem_in, &solution);
	solution_free(&solution);
	lem_in_free(&lem_in);
	return (0);
}
