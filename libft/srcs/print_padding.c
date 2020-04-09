/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:22:53 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 14:53:46 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_padding(t_formatinfo *formatinfo, int len, t_output *output)
{
	char	padchar;

	if (len >= formatinfo->width)
		return ;
	if (formatinfo->flags & FLAG_ZERO)
		padchar = '0';
	else
		padchar = ' ';
	out_fill(output, (formatinfo->width - len), padchar);
}
