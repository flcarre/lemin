/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number_generic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:26:31 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 14:53:26 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_sign(t_formatinfo *info, t_64 num, t_output *output)
{
	if (num < 0)
	{
		out_putchar(output, '-');
		num *= -1;
	}
	else
	{
		if (info->flags & FLAG_PLUS)
			out_putchar(output, '+');
		else if (info->flags & FLAG_SPACE)
			out_putchar(output, ' ');
	}
}

void			print_number_generic(t_formatinfo *info, \
				va_list ap, char *base, t_output *output)
{
	t_64		num;
	t_u64		unum;
	t_output	output2;

	if (info->specifier == SPEC_INT)
	{
		num = read_argument_signed(info, ap);
		print_sign(info, num, output);
		if (num < 0)
			num *= -1;
		unum = num;
	}
	else
	{
		unum = read_argument_unsigned(info, ap);
	}
	if (info->flags & FLAG_HASPRECISION && info->precision == 0 && unum == 0)
		return ;
	out_init(&output2);
	ft_putnbr_base(unum, base, &output2);
	if (info->flags & FLAG_HASPRECISION)
		out_fill(output, info->precision - output2.size, '0');
	else if (!(info->flags & FLAG_MINUS) && info->flags & FLAG_ZERO)
		out_fill(output, info->width - output->size - output2.size, '0');
	ft_putnbr_base(unum, base, output);
}
