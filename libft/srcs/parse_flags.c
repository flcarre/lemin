/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:52:03 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 13:38:06 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_map(char *map)
{
	ft_bzero(map, MAP_SIZE);
	map['#'] = FLAG_PREPOUND;
	map['0'] = FLAG_ZERO;
	map['+'] = FLAG_PLUS;
	map['-'] = FLAG_MINUS;
	map[' '] = FLAG_SPACE;
}

int			parse_flags(t_formatinfo *info, const char *format, int *pos)
{
	t_bool	any;
	char	map[MAP_SIZE];
	char	flag;
	char	c;

	fill_map(map);
	any = FALSE;
	while (format[*pos] != '\0')
	{
		c = format[*pos];
		flag = map[(int)c];
		if (flag != 0)
		{
			info->flags |= flag;
			any = TRUE;
		}
		else
			return (any);
		(*pos)++;
	}
	return (any);
}
