/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_is_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:51:31 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 13:13:17 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		value_is_zero(t_formatinfo *info, va_list ap)
{
	t_u64	num;
	va_list	ap2;

	va_copy(ap2, ap);
	num = read_argument_unsigned(info, ap2);
	return (num == 0);
}
