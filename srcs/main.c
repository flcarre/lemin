/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:17:54 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/05 20:50:28 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_travel(t_graph *graph)
{
	t_links			*link;

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
	t_graph		*start;
	//t_links		*i;

	if (!ft_gnl(3))
		return (ft_error(0));
	if (!(start = ft_get_graph()))
		return (ft_printf("%{HRED} %{} There is no graph !\n"));
	//ft_travel(start);
	//ft_reset(start, 1);
	/*
	i = start->links;
	while (i)
	{
		ft_printf("%{HPURPLE} %{} %s - %s\n", start->name, i->room->name);
		i = i->next;
	}
	*/
	ft_del_graph(start, (void *)0);
	ft_gnl(0);
	return (0);
}

/*
__attribute__((destructor)) int end()
{
	while (1);
}
*/
