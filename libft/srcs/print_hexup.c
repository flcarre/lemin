/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:38:52 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 14:39:33 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_hexup(t_formatinfo *info, va_list ap, t_output *output)
{
	if (info->flags & FLAG_PREPOUND)
		print_prepound_notnull(info, "0X", ap, output);
	print_number_generic(info, ap, "0123456789ABCDEF", output);
}
