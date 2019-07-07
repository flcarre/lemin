/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:17:54 by lutsiara          #+#    #+#             */
/*   Updated: 2019/07/07 20:28:39 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_debug(t_ctn *paths)
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
	return (ft_debug(paths->next));
}
/*
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

static int	ft_find_paths(t_var *var, int m)
{
	t_ctn			*path;

	if (m)
		while ((path = ft_dijkstra(var)) && ++var->nb_path)
			ft_enqueue_path(&var->paths, path);
	if (!var->paths && m)
		return (1);
	if (var->nb_path < var->max_nb_path)
	{
		if ((path = ft_bfs(var, 8)) && ++var->nb_bfs)
			ft_order_path(&var->bfs, path);
		else if (!path)
			return (1);
		ft_reset(var, 8);
		if (m)
			while ((path = ft_bfs(var, 32)) && ++var->nb_bfs)
				ft_order_path(&var->bfs, path);
	}
	return (0);
}

static int	ft_choose_paths(t_var *var, int m)
{
	unsigned int	h_dij;
	unsigned int	h_bfs;
	unsigned int	nb_dij;
	unsigned int	nb_bfs;

	h_dij = 0;
	if (ft_find_paths(var, m))
		return (1);
	if (var->bfs)
		nb_bfs = ft_how_many(var, &h_bfs, 1);
	else
	{
		var->nb_travel = ft_how_many(var, &h_dij, 0);
		var->travel = var->paths;
		return (0);
	}
	nb_dij = ft_how_many(var, &h_dij, 0);
	var->travel = (h_dij == 0 || h_dij > h_bfs) ? var->bfs : var->paths;
	var->nb_travel = (h_dij == 0 || h_dij > h_bfs) ? nb_bfs : nb_dij;
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
	if (ft_choose_paths(&var, !ft_endisnext(&var, var.start->links)) \
	&& !ft_gnl(0))
		return (!ft_del(&var));
	ft_travel(&var);
	ft_printf("\nAnts: %u\n", var.nb_ants);
	ft_printf("Cycles: %u\n", var.cycle);
	ft_printf("Algo: %{YELLOW}%s%{}\n", (var.travel == var.paths) ? "DIJKSTRA" : "BFS");
	ft_printf("Nombres de paths: %u\n", var.nb_travel);
	/*
	ft_printf("%{HGREEN}DIJKSTRA%{}:\n\n");
	ft_debug(var.paths);
	ft_printf("%{HGREEN}BFS%{}:\n\n");
	ft_debug(var.bfs);
	*/
	ft_gnl(0);
	return (ft_del(&var));
}

/*
__attribute__((destructor)) int end()
{
	while (1);
}
*/
