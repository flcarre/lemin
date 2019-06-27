/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:17:54 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/27 22:30:45 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
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

ft_printf("%{HGREEN}DIJKSTRA%{}:\n\n");
ft_travel(var.paths);
ft_printf("%{GREEN}%u%{} %{YELLOW}%u%{}\n", var.nb_ants, var.nb_path);
ft_printf("%{ORANGE}%u%{}\n\n", ft_how_many(&var, 0));
ft_printf("%{HGREEN}BFS%{}:\n\n");
ft_travel(var.bfs);
ft_printf("%{GREEN}%u%{} %{YELLOW}%u%{}\n", var.nb_ants, var.nb_bfs);
ft_printf("%{ORANGE}%u%{}\n", ft_how_many(&var, 1));
*/

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

static int	ft_choose_paths(t_var *var)
{
	t_ctn			*path;
	unsigned int	h_dij;
	unsigned int	h_bfs;

	while ((path = ft_dijkstra(var)) && ++var->nb_path)
		ft_enqueue_path(&var->paths, path);
	if (!var->paths)
		return (1);
	if (var->nb_path < var->max_nb_path && ft_bfs(&var, 8))
		return (1);
	if (var->bfs)
		h_bfs = ft_how_many(var, 1);
	else
	{
		var->elem = var->paths;
		return (0);
	}
	h_dij = ft_how_many(var, 0);
	var->elem = (h_dij < h_bfs) ? var->paths : var->bfs;
	return (0);
}

int			main(void)
{
	t_var			var;

	ft_bzero((void *)&var, sizeof(t_var));
	if (var_init(&var))
		return (1);
	if (!ft_gnl(3) || ft_get_graph(&var))
	{
		ft_putendl("ERROR");
		ft_gnl(0);
		return (!ft_del(&var));
	}
	if (ft_choose_paths(&var) && !ft_gnl(0))
		return (!ft_del(&var));
	//ft_travel(&var);
	ft_gnl(0);
	return (ft_del(&var));
}

/*
__attribute__((destructor)) int end()
{
	while (1);
}
*/
