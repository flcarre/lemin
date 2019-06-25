/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:17:54 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/25 17:50:46 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_travel(t_ctn *paths)
{
	t_path	*i;

	if (!paths)
		return (0);
	i = paths->path;
	ft_printf("Path length: %{CYAN}%d%{}\n", paths->len);
	while (i)
	{
		ft_printf("%s %{YELLOW}%ld %ld%{}\n", i->room->name, \
		i->room->x, i->room->y);
		i = i->next;
	}
	ft_printf("\n");
	return (ft_travel(paths->next));
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

	i = var->queue;
	while (i)
	{
		if (i->room->state & 4)
			if (ft_push_hash2(var, i->room))
				return (-1);
		i = i->next;
	}
	return (0);
}

int			main(void)
{
	t_var	var;
	t_ctn	*path;

	ft_bzero((void *)&var, sizeof(t_var));
	if (var_init(&var))
		return (1);
	if (!ft_gnl(3) || ft_get_graph(&var) || init(&var) == -1)
	{
		ft_putendl("ERROR");
		ft_gnl(0);
		ft_del(&var);
		return (1);
	}
	while ((path = ft_dijkstra(&var)) && ++var.nb_path)
		ft_enqueue_path(&var.paths, path);
	ft_travel(var.paths);
	ft_printf("%{GREEN}%u%{} %{YELLOW}%u%{}\n", var.nb_ants, var.nb_path);
	ft_printf("%{ORANGE}%u%{}\n", ft_how_many(&var));
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
