/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opt_print_help.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:51:20 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/10 21:09:25 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_unknow(char *s)
{
	ft_fprintf(2, "Error arg : '%s' is not a valid option.\n\n", s);
	printf_help();
	ft_fprintf(2, "\n");
	lem_in_die();
}

void	printf_help(void)
{
	ft_fprintf(2, " ______________________________________________\n");
	ft_fprintf(2, "|                                              |\n");
	ft_fprintf(2, "|  Usage: ./lem-in [options] < map_info        |\n");
	ft_fprintf(2, "|    -h, -help: print help.                    |\n");
	ft_fprintf(2, "|    -r, --rooms: print graph's rooms.         |\n");
	ft_fprintf(2, "|    -g, --groups: print the choosen group.    |\n");
	ft_fprintf(2, "|    -n, --nblines: print lines total.         |\n");
	ft_fprintf(2, "|    -R, --route: print route used by ant.     |\n");
	ft_fprintf(2, "|    -d, --debug: print all debugs.            |\n");
	ft_fprintf(2, "|                                              |\n");
	ft_fprintf(2, "| (*) All extra print info goes on stderr (2)  |\n");
	ft_fprintf(2, "|______________________________________________|\n");
}
