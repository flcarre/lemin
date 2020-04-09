/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:30:55 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 14:44:20 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define BUF_SIZE 255

void		print_octal(t_formatinfo *info, va_list ap, t_output *output)
{
	t_output	output2;
	char		buf[BUF_SIZE];
	va_list		ap2;

	if (info->flags & FLAG_PREPOUND)
	{
		va_copy(ap2, ap);
		out_init(&output2);
		output2.buf = buf;
		print_number_generic(info, ap2, "01234567", &output2);
		if (output2.size == 0 || buf[0] != '0')
			out_putchar_len(output, "0", 1);
	}
	print_number_generic(info, ap, "01234567", output);
}
