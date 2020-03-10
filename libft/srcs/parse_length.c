/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:53:02 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 14:20:40 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_length(t_formatinfo *info, const char *format, int *pos)
{
	char		*str;
	t_length	len;

	str = (char*)format + (*pos);
	if (!ft_strncmp(str, "hh", 2))
		len = LEN_CHAR;
	else if (!ft_strncmp(str, "h", 1))
		len = LEN_SHORT;
	else if (!ft_strncmp(str, "ll", 2))
		len = LEN_LLONG;
	else if (!ft_strncmp(str, "l", 1))
		len = LEN_LONG;
	else
		return (0);
	if (len == LEN_CHAR || len == LEN_LLONG)
		(*pos) += 2;
	else if (len == LEN_LONG || len == LEN_SHORT)
		(*pos) += 1;
	info->length = len;
	return (1);
}
