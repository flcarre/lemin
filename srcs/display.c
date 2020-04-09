/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:04:36 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 19:47:04 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	save_output(t_lem_in *lem_in, char *line)
{
	t_list *new;

	new = NULL;
	if (line)
	{
		new = ft_lstnew(ft_strdup(line), 1);
		ft_lstadd(&lem_in->display, new);
	}
}

void	print_output_line(t_list *display)
{
	while (display && display->content != NULL)
	{
		ft_printf("%s\n", display->content);
		display = display->next;
	}
}

void	print_output(t_lem_in *lem_in)
{
	ft_lstrev(&lem_in->display);
	print_output_line(lem_in->display);
	ft_printf("\n");
}

void	free_saved_output(t_lem_in *lem_in)
{
	ft_lst_del(&lem_in->display);
}
