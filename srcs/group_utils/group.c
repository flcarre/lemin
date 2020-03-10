/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:50:33 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 17:27:45 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	group_free(void *content, unsigned long size)
{
	t_group	*group;
	int		i;

	(void)size;
	group = (t_group*)content;
	i = 0;
	while (i < group->route_count)
	{
		route_free(group->routes[i], sizeof(t_route));
		i++;
	}
	free(group->routes);
	free(group->ants_distribution);
	free(group);
}

int		group_rounds_for_route(t_group *group, int index)
{
	if (group->ants_distribution[index] <= 0)
		return (0);
	return (group->routes[index]->len + group->ants_distribution[index] - 1);
}

void	group_print(t_group *group)
{
	int	i;

	ft_fprintf(2, "Group (routes=%d; total_rounds=%d):\n", group->route_count,
		group->total_rounds);
	i = 0;
	while (i < group->route_count)
	{
		ft_fprintf(2, "(ants=%d) (rounds=%d) ",
			group->ants_distribution[i],
			group_rounds_for_route(group, i));
		route_print(group->routes[i]);
		i++;
	}
}
