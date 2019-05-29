/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:17:54 by lutsiara          #+#    #+#             */
/*   Updated: 2019/05/29 18:53:44 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	char	*line;
	int		ret;
	t_path	*queue;
	t_path	*elem;

	line = (void *)0;
	queue = (void *)0;
	while ((ret = gnl(STDIN_FILENO, &line)) == 1)
	{
		ft_printf("%{RED}%d%{} : %{GREEN}%s%{}\n", ft_rank_line(line), line);
		if (ft_rank_line(line) == ROOM)
		{
			if (!(elem = ft_alloc_path_elem()))
				return (ft_printf("%{HRED} %{}ft_alloc_path_elem failed\n"));
			if (!(elem->room = ft_alloc_room()))
			{
				ft_printf("%{HRED} %{}ft_alloc_room failed\n");
				if (queue)
					ft_del_path(&queue, 1);
				ft_del_path(&elem, 0);
				return (1);
			}
			ft_set_room(&(elem->room), line, 0, 0);
			ft_enqueue_room(&queue, elem);
		}
		else
			ft_memdel((void **)&line);
	}
	ft_putendl("");
	elem = queue;
	while (elem)
	{
		ft_printf("%{HGREEN} %{} %s\n", elem->room->name);
		elem = elem->next;
	}
	ft_del_path(&queue, 1);
	return ((ret < 0) ? -ret : ret);
}

/*
__attribute__((destructor)) int end()
{
	while (1);
}
*/
