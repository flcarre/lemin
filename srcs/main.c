/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:17:54 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/07 20:47:44 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_travel(t_graph *graph)
{
	t_links	*link;

	link = graph->links;
	if (graph->state & 1)
		return (0);
	graph->state |= 1;
	while (link)
	{
		ft_travel(link->room);
		link = link->next;
	}
	ft_printf("%{HBLUE}%hhu%{} %{HCYAN}%u%{} %s %{YELLOW}%ld %ld%{}\n", \
	graph->state, graph->nb_ants, graph->name, graph->x, graph->y);
	return (0);
}

int		main(void)
{
	t_var	var;

	ft_bzero((void *)&var, sizeof(t_var));
	if (!ft_gnl(3) || ft_get_graph(&var))
	{
		ft_putendl("ERROR");
		return (1);
	}

	return (0);
}

/*
__attribute__((destructor)) int end()
{
	while (1);
}
*/
