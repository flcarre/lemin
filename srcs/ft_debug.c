/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:00:40 by lutsiara          #+#    #+#             */
/*   Updated: 2019/07/09 18:20:22 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_paths(t_var *var)
{
	unsigned int	i;
	t_ctn			*ptr;
	t_path			*e;

	i = 0;
	ptr = var->travel;
	while (i < var->nb_travel)
	{
		e = ptr->path;
		while (e)
		{
			if (e->room == var->start)
				ft_printf("%{GREEN}[%s]%{}-", e->room->name);
			else if (e->room == var->end)
				ft_printf("%{RED}[%s]%{}", e->room->name);
			else
				ft_printf("%{BLUE}[%s]%{}-", e->room->name);
			e = e->next;
		}
		ft_putendl("");
		i++;
		ptr = ptr->next;
	}
}

void		ft_debug(int ac, char **av, t_var *var)
{
	if (ac != 2 || ft_strcmp(av[ac - 1], "--details"))
		return ;
	ft_printf("\nAnts: %u\n", var->end->nb_ants);
	ft_printf("Cycles: %u\n\n", var->cycle);
	ft_printf("Nombres de paths: %u\n", var->nb_travel);
	print_paths(var);
}
