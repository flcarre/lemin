/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_argument.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:47:54 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 14:21:09 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_64	read_argument_signed(t_formatinfo *info, va_list ap)
{
	t_64	num;

	if (info->length == LEN_CHAR)
		num = (char)(va_arg(ap, int));
	else if (info->length == LEN_SHORT)
		num = (short)(va_arg(ap, int));
	else if (info->length == LEN_LONG)
		num = (long)(va_arg(ap, long));
	else if (info->length == LEN_LLONG)
		num = (long long)(va_arg(ap, long long));
	else if (info->length == LEN_PTR)
		num = (t_64)(va_arg(ap, void*));
	else
		num = (int)(va_arg(ap, int));
	return (num);
}

t_u64	read_argument_unsigned(t_formatinfo *info, va_list ap)
{
	t_u64	num;

	if (info->length == LEN_CHAR)
		num = (unsigned char)(va_arg(ap, unsigned int));
	else if (info->length == LEN_SHORT)
		num = (unsigned short)(va_arg(ap, unsigned int));
	else if (info->length == LEN_LONG)
		num = (unsigned long)(va_arg(ap, unsigned long));
	else if (info->length == LEN_LLONG)
		num = (unsigned long long)(va_arg(ap, unsigned long long));
	else if (info->length == LEN_PTR)
		num = (t_u64)(va_arg(ap, void*));
	else
		num = (unsigned int)(va_arg(ap, unsigned int));
	return (num);
}
