/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:59:35 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 13:13:17 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		out_fill(t_output *output, int count, char c)
{
	int	i;

	i = 0;
	while (i < count)
	{
		out_putchar(output, c);
		i++;
	}
}
