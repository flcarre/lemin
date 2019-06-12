/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:17:54 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/12 23:17:29 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_travel(t_ctn *paths)
{
	t_path	*i;

	i = paths->path;
	ft_printf("Path length: %{CYAN}%d%{}\n", paths->len);
	while (i)
	{
		ft_printf("%s %{YELLOW}%ld %ld%{}\n", i->room->name, \
		i->room->x, i->room->y);
		i = i->next;
	}
	return (0);
}

static int	var_init(t_var *var)
{
	if (!(var->hash_name = \
		(t_links **)ft_memalloc(sizeof(t_links *) * SIZE_HASH_TABLE)))
		return (1);
	if (!(var->hash_addr = \
		(t_links **)ft_memalloc(sizeof(t_links *) * SIZE_HASH_TABLE)))
		return (1);
	return (0);
}

static int		init(t_var *var)
{
	t_path	*i;
	int		len;

	len = 0;
	i = var->queue;
	while (i)
	{
		if ((i->room->state & 4))
		{
			if (ft_push_hash2(var, i->room))
				return (-1);
			len++;
		}
		i = i->next;
	}
	return (len);
}

int			main(void)
{
	t_var	var;
	int		i;

	ft_bzero((void *)&var, sizeof(t_var));
	if (var_init(&var))
		return (1);
	if (!ft_gnl(3) || ft_get_graph(&var) || (i = init(&var)) == -1)
	{
		ft_putendl("ERROR");
		ft_gnl(0);
		ft_del(&var);
		return (1);
	}
	if ((var.paths = ft_dijkstra(&var, i)))
		ft_travel(var.paths);
	ft_gnl(0);
	ft_del(&var);
	return (0);
}

/*
__attribute__((destructor)) int end()
{
	while (1);
}
*/
