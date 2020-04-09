/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:38:52 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 14:46:35 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_ptr(t_formatinfo *info, va_list ap, t_output *output)
{
	info->length = LEN_PTR;
	out_putchar_len(output, "0x", 2);
	print_number_generic(info, ap, "0123456789abcdef", output);
}
