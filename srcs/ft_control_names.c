/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_names.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:20:45 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/27 02:46:07 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_control_names(char *line, t_var *var)
{
	char			*tmp;
	t_links			*li;

	tmp = ft_strchr(line, (int)'-');
	*tmp = '\0';
	var->room1 = ft_return_room(var, line);
	var->room2 = ft_return_room(var, tmp + 1);
	if (!var->room1 || !var->room2)
		return (1);
	li = var->room1->links;
	while (li)
	{
		if (li->room == var->room2)
			return (1);
		li = li->next;
	}
	if (!ft_strcmp(var->room1->name, var->room2->name))
		return (1);
	*tmp = '-';
	return (0);
}
