/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_putchar_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:37:52 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 13:27:06 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	out_putchar_len(t_output *output, char *ptr, unsigned long size)
{
	int	i;

	i = 0;
	while ((unsigned long)i < size)
	{
		out_putchar(output, ptr[i]);
		i++;
	}
}
