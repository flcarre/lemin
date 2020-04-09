/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:06:45 by tavelino          #+#    #+#             */
/*   Updated: 2020/03/10 14:49:48 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_convertnbr_base(t_u64 nbr, char *base, \
				int base_len, t_output *output)
{
	if (nbr >= (t_u64)base_len)
	{
		ft_convertnbr_base((nbr / base_len), base, base_len, output);
	}
	out_putchar(output, base[(nbr % base_len)]);
}

void			ft_putnbr_base(t_u64 nbr, char *base, t_output *output)
{
	int		base_len;

	base_len = ft_strlen(base);
	ft_convertnbr_base(nbr, base, base_len, output);
}
