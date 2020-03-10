/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:52:40 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 14:35:32 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_precision(t_formatinfo *info, const char *format, int *pos)
{
	int	precision;

	if (format[*pos] == '.')
	{
		(*pos)++;
		if (!parse_number(format, pos, &precision))
			precision = 0;
		info->precision = precision;
		info->flags |= FLAG_HASPRECISION;
		return (1);
	}
	return (0);
}
