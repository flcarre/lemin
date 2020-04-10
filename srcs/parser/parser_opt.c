/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:51:20 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/10 21:09:25 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_opt(t_lem_in *lem_in)
{
	lem_in->opt.debug = FALSE;
	lem_in->opt.print_room = FALSE;
	lem_in->opt.print_groups = FALSE;
	lem_in->opt.print_nblines = FALSE;
	lem_in->opt.print_help = FALSE;
}

void	parse_arg_sym(t_lem_in *lem_in, char *s)
{
	int i;

	i = 1;
	while (s[i])
	{
		if (s[i] == 'd')
			lem_in->opt.debug = TRUE;
		else if (s[i] == 'h')
			lem_in->opt.print_help = TRUE;
		else if (s[i] == 'r')
			lem_in->opt.print_room = TRUE;
		else if (s[i] == 'g')
			lem_in->opt.print_groups = TRUE;
		else if (s[i] == 'R')
			lem_in->opt.print_route = TRUE;
		else if (s[i] == 'n')
			lem_in->opt.print_nblines = TRUE;
		else
			print_unknow(s);
		i++;
	}
}

void	parse_arg(char *s, t_lem_in *lem_in)
{
	if (s[0] != '-')
		print_unknow(s);
	else
	{
		if (ft_strequ("--debug", s))
			lem_in->opt.debug = TRUE;
		else if (ft_strequ("--help", s))
			lem_in->opt.print_help = TRUE;
		else if (ft_strequ("--rooms", s))
			lem_in->opt.print_room = TRUE;
		else if (ft_strequ("--groups", s))
			lem_in->opt.print_groups = TRUE;
		else if (ft_strequ("--route", s))
			lem_in->opt.print_route = TRUE;
		else if (ft_strequ("--nblines", s))
			lem_in->opt.print_nblines = TRUE;
		else
			parse_arg_sym(lem_in, s);
	}
}

void	parse_opt(t_lem_in *lem_in, int ac, char **av)
{
	int i;

	i = 1;
	ft_memset(&lem_in->opt, 0, sizeof(lem_in->opt));
	while (av[i] != NULL && i < ac)
	{
		parse_arg(av[i], lem_in);
		i++;
	}
}
