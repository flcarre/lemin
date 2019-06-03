/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:17:54 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/03 19:01:30 by lutsiara         ###   ########.fr       */
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

	if (!(start = ft_get_graph()))
		return (ft_printf("%{HRED} %{} There is no graph !\n"));
	ft_travel(start);
	ft_reset(start, 1);
	ft_del_graph(start, (void *)0);
	/*
	char	*line;
	int		ret;

	line = (void *)0;
	while((ret = gnl(STDIN_FILENO, &line)) == 1)
	{
		ft_printf("%{GREEN}%d%{} %s\n", ft_rank_line(line), line);
		ft_memdel((void **)&line);
	}
	*/
	return (0);
}

/*
__attribute__((destructor)) int end()
{
	while (1);
}
*/
