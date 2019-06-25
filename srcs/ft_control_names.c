/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_names.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:20:45 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/25 17:34:40 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_control_names(char *line, t_var *var)
{
	char			*tmp;

	tmp = ft_strchr(line, (int)'-');
	*tmp = '\0';
	var->room1 = ft_return_room(var, line);
	var->room2 = ft_return_room(var, tmp + 1);
	if (!var->room1 || !var->room2)
		return (1);
	if (!ft_strcmp(var->room1->name, var->room2->name))
		return (1);
	*tmp = '-';
	return (0);
}
