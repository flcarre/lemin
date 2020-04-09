/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prepound_notnull.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:00:02 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 14:53:55 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_prepound_notnull(t_formatinfo *info, char *str,
								va_list ap, t_output *out)
{
	if (!value_is_zero(info, ap))
		out_putchar_len(out, str, ft_strlen(str));
}
