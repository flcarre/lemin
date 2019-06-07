/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 21:59:58 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/08 00:50:28 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	save_name(char *name, t_var *var)
{
	char	*tmp;

	tmp = var->names;
	if (!(var->names = ft_strjoin(tmp, " ")))
	{
		ft_memdel((void **)&tmp);
		return (1);
	}
	ft_memdel((void **)&tmp);
	tmp = var->names;
	if (!(var->names = ft_strjoin(tmp, name)))
	{
		ft_memdel((void **)&tmp);
		return (1);
	}
	ft_memdel((void **)&tmp);
	return (0);
}

int			ft_set_room(t_graph **room, char *line, t_var *var)
{
	char	*tmp;

	tmp = ft_strchr(line, ' ');
	*tmp = '\0';
	if (var->names)
		if (ft_strstr(var->names, line))
		{
			ft_memdel((void **)&(*room));
			return (1);
		}
	(*room)->name = line;
	(*room)->x = ft_atol(tmp + 1);
	(*room)->y = ft_atol(ft_strchr(tmp + 1, ' '));
	if (save_name(line, var))
		return (1);
	return (0);
}
