/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_names.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:20:45 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/10 19:28:01 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_control_names(char *line, t_var *var)
{
	char			*tmp;

	tmp = ft_strchr(line, (int)'-');
	*(tmp++) = '\0';
	var->room1 = var->hash_table[ft_djb2a(line) % SIZE_HASH_TABLE];
	var->room2 = var->hash_table[ft_djb2a(tmp) % SIZE_HASH_TABLE];
	if (!var->room1 || !var->room2)
		return (1);
	if (!ft_strcmp(var->room1->name, var->room2->name))
		return (1);
	return (0);
}
