/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:56:20 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/02 21:39:36 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_get_nb_ants(unsigned int *nb_ants)
{
	char			*line;
	t_rank			rank;

	line = (void *)0;
	if (gnl(STDIN_FILENO, &line) != 1)
		return (1);
	if ((rank = ft_rank_line(line)) != NBANTS)
	{
		ft_memdel((void **)&line);
		if (rank == COMMENT)
			return (ft_get_nb_ants(nb_ants));
		return (1);
	}
	*nb_ants = ft_atoui((const char *)line);
	ft_memdel((void **)&line);
	return (0);
}

t_graph			*ft_get_graph(void)
{
	t_graph			*start;
	t_path			*tmp;
	unsigned int	nb_ants;
	int				ret;

	tmp = (void *)0;
	if (ft_get_nb_ants(&nb_ants))
		return ((void *)0);
	while (!(ret = ft_create_rooms(&tmp, 0)))
		;
	if (ret != 2 && !ft_del_path(&tmp, 1))
		return ((void *)0);
	while (!(ret = ft_make_links(&tmp)))
		;
	if (ret != 2 && !ft_del_path(&tmp, 1))
		return ((void *)0);
	/*
	if (ft_checkup(tmp))
		return ((void *)ft_del_path(&tmp, 1));
	ft_rm_room_nolinked(tmp);
	*/
	start = ft_return_head(tmp);
	start->nb_ants = nb_ants;
	ft_del_path(&tmp, 0);
	return (start);
}
