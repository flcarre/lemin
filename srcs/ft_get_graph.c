/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:56:20 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/04 19:17:47 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_get_nb_ants(unsigned int *nb_ants)
{
	char			*line;
	t_rank			rank;

	line = (void *)0;
	//if (gnl(STDIN_FILENO, &line) != 1)
	if (!(line = ft_gnl(2)) || !(*line))
		return (1);
	if ((rank = ft_rank_line(line)) != NBANTS)
	{
	//	ft_memdel((void **)&line);
		if (rank == COMMENT)
			return (ft_get_nb_ants(nb_ants));
		return (1);
	}
	*nb_ants = ft_atoui((const char *)line);
	//ft_memdel((void **)&line);
	return (0);
}

static void		ft_rm_room_nolinked(t_path *rooms)
{
	t_path			*tmp;

	if (!rooms)
		return ;
	ft_set(ft_return_head(rooms, 64), 1);
	tmp = rooms;
	while (tmp)
	{
		if (!(tmp->room->state & 1))
			ft_del_room(&(tmp->room));
		tmp = tmp->next;
	}
	ft_reset(ft_return_head(rooms, 64), 1);
}

t_graph			*ft_get_graph(void)
{
	t_graph			*start;
	t_path			*tmp;
	unsigned int	nb_ants;
	int				ret;
	unsigned char	state;

	state = 0;
	tmp = (void *)0;
	if (ft_get_nb_ants(&nb_ants))
		return ((void *)0);
	while (!(ret = ft_create_rooms(&tmp, &state)))
		;
	if (ret != 2 && !ft_del_path(&tmp, 1))
		return ((void *)0);
	while (!(ret = ft_make_links(&tmp)))
		;
	if (ret != 2 && !ft_del_path(&tmp, 1))
		return ((void *)0);
	if (ft_checkup(tmp) && !ft_del_path(&tmp, 1))
		return ((void *)0);
	ft_rm_room_nolinked(tmp);
	start = ft_return_head(tmp, 64);
	start->nb_ants = nb_ants;
	ft_del_path(&tmp, 0);
	return (start);
}
