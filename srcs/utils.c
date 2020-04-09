/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 09:59:35 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/09 17:11:09 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_tab(char ***tab)
{
	int i;

	i = 0;
	if (*tab == NULL)
		return ;
	while ((*tab)[i] != NULL)
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
	*tab = NULL;
}

int		ft_strindex(const char *str, char c)
{
	int i;

	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		gnl(t_lem_in *lem_in, const int fd, char **line)
{
	int	res;

	res = 0;
	ft_strdel(line);
	while (1)
	{
		res = get_next_line(fd, line);
		if (res <= 0)
		{
			return (res);
		}
		save_output(lem_in, *line);
		if (!ft_strnequ("#", *line, 1)
			|| (ft_strequ("##start", *line))
			|| (ft_strequ("##end", *line)))
			return (res);
		ft_strdel(line);
	}
}

void	print_nodes(t_glist *nodes)
{
	t_glist	*curr;
	t_room	*room;
	char	*label;
	char	*padding;

	curr = nodes;
	while (curr != NULL)
	{
		room = curr->gen.room;
		if (room->type == START)
			label = "\033[32m";
		else if (room->type == END)
			label = "\033[31m";
		else
			label = "\033[36m";
		if (curr->next != NULL)
			padding = "-";
		else
			padding = "";
		ft_fprintf(2, "%s%s\033[m%s", label, room->name, padding);
		curr = curr->next;
	}
	ft_fprintf(2, "\n");
}
