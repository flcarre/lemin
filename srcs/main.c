/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:17:54 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/03 23:21:50 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_travel(t_graph *graph)
{
	t_links			*link;

	link = graph->links;
	if (graph->state & 1)
		return (0);
	graph->state |= 1;
	while (link)
	{
		ft_travel(link->room);
		link = link->next;
	}
	ft_printf("%{HBLUE}%hhu%{} %{HCYAN}%u%{} %s %{YELLOW}%ld %ld%{}\n", \
	graph->state, graph->nb_ants, graph->name, graph->x, graph->y);
	return (0);
}

static void		ft_setzero(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			*str = '\0';
		str++;
	}
}

static char		*ft_read(void)
{
	char					buff[8192];
	char					*buffer;
	char					*tmp;
	long					ret;

	buffer = (void *)0;
	while ((ret = read(STDIN_FILENO, buff, 8191)) > 0)
	{
		buff[ret] = '\0';
		tmp = buffer;
		buffer = ft_strjoin(buffer, buff);
		ft_memdel((void **)&tmp);
		if (!buffer)
			return ((void *)0);
	}
	if (ret < 0)
	{
		ft_memdel((void **)&buffer);
		return ((void *)0);
	}
	return (buffer);
}

char			*ft_gnl(unsigned char mode)
{
	static char				*buffer = (void *)0;
	static char				*line = (void *)0;
	static unsigned long	len = 0;

	if (mode == 2)
		return (line);
	if (!mode)
	{
		ft_memdel((void **)&buffer);
		return ((void *)0);
	}
	if (mode == 3)
	{
		if (!(buffer = ft_read()))
			return ((void *)0);
		len = ft_strlen(buffer);
		ft_printf("%{HGREEN} %{}ok\n");
		ft_setzero(buffer);
		ft_printf("%{HGREEN} %{}ok\n");
		line = buffer;
		return (line);
	}
	line = ft_strrchr(line, (int)'\0');
	if ((unsigned long)line - (unsigned long)buffer < len)
		line++;
	return (line);
}

int		main(void)
{
	/*
	t_graph		*start;

	if (!(start = ft_get_graph()))
		return (ft_printf("%{HRED} %{} There is no graph !\n"));
	ft_travel(start);
	ft_reset(start, 1);
	ft_del_graph(start, (void *)0);
	*/
	char	*line;

	ft_gnl(3);
	line = ft_gnl(2);
	ft_printf("%{GREEN}%d%{} %s\n", ft_rank_line(line), line);
	while((line = ft_gnl(1)) && *line)
		ft_printf("%{GREEN}%d%{} %s\n", ft_rank_line(line), line);
	ft_gnl(0);
	return (0);
}

/*
__attribute__((destructor)) int end()
{
	while (1);
}
*/
