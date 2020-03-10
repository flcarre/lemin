/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:52:21 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 13:39:42 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_width(t_formatinfo *info, const char *format, int *pos)
{
	int	width;

	if (parse_number(format, pos, &width))
	{
		info->width = width;
		return (1);
	}
	return (0);
}
