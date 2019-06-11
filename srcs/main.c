/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:17:54 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/11 17:38:56 by lutsiara         ###   ########.fr       */
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
	if (!(var.hash_table = \
		(t_links **)ft_memalloc(sizeof(t_links *) * SIZE_HASH_TABLE)))
		return (1);
	if (!ft_gnl(3) || ft_get_graph(&var))
	{
		ft_putendl("ERROR");
		ft_gnl(0);
		ft_del(&var);
		return (1);
	}
	//ft_travel(var.start);
	ft_gnl(0);
	ft_del(&var);
	return (0);
}

/*
__attribute__((destructor)) int end()
{
	while (1);
}
*/
