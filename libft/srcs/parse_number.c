/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:51:12 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 14:35:38 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_number(const char *format, int *pos, int *num)
{
	int	digit;

	if (!ft_isdigit(format[*pos]))
		return (0);
	*num = 0;
	while (ft_isdigit(format[*pos]))
	{
		digit = format[*pos] - '0';
		(*num) *= 10;
		(*num) += digit;
		(*pos)++;
	}
	return (1);
}
