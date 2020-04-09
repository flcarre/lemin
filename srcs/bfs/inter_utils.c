/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:30:59 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/09 17:05:48 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			inter_del_list(t_lem_in *lem_in, t_glist **inters)
{
	while ((*inters) != NULL)
	{
		inter_del(lem_in, (*inters)->gen.inter);
		ft_glstdelone(inters, NULL);
	}
}

void			inter_print(t_inter *inter)
{
	if (inter->parent != NULL)
		inter_print(inter->parent);
	ft_fprintf(2, "BFS node [%-6s]\t(augmentation=%d, intersection=%s)\n", \
		inter->room->name, \
		inter->augmentation, \
		inter->intersection != NULL ? inter->intersection->name : NULL);
}
